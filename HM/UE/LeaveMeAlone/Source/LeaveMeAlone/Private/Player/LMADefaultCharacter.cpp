// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LMADefaultCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
ALMADefaultCharacter::ALMADefaultCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->SetUsingAbsoluteRotation(true); //данное условие не позволит нашей камере поворачиваться в момент поворота персонажа
	
	SpringArmComponent->TargetArmLength = ArmLength;
	SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f));
	/* структура FRotator хранит аргументы в следующей последовательности: Pitch,Yaw,Roll.
	Так как нам необходимо определить значения по оси Y,мы устанавливаем Pitch аргумент.*/
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->bEnableCameraLag = true;
	CameraComponent->SetFieldOfView(FOV);
	CameraComponent->bUsePawnControlRotation = false;// данное условие запрещаем камере вращаться относительно SpringArmComponent.


	
	bUseControllerRotationPitch = false; // запретим нашему персонажу поворачиваться в сторону камеры
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void ALMADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();

	// создать курсор на уровне
	if (CursorMaterial) { 
          CurrentCursor = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), CursorMaterial, CursorSize, FVector(0));
    }
	
}

// Called every frame
void ALMADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//отслеживание расположение курсора игрока
	APlayerController *PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
        if (PC) {
          FHitResult ResultHit;
          PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, ResultHit);
          float FindRotatorResultYaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),ResultHit.Location).Yaw;
          SetActorRotation(FQuat(FRotator(0.0f, FindRotatorResultYaw, 0.0f)));
          if (CurrentCursor) {
            CurrentCursor->SetWorldLocation(ResultHit.Location);
          }
        }
     
}

// Called to bind functionality to input
void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this,&ALMADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this,&ALMADefaultCharacter::MoveRight);

	PlayerInputComponent->BindAxis("MouseWheelZoom", this,&ALMADefaultCharacter::MouseWheelZoom);
}

void ALMADefaultCharacter::MoveForward(float Value) 
{
  AddMovementInput(GetActorForwardVector(), Value);//AddMovementInput это стандартная функция, которая в качестве параметров берет направление движения и величину, на которую будет умножено направление.
}

void ALMADefaultCharacter::MoveRight(float Value) 
{
  AddMovementInput(GetActorRightVector(), Value);
}

// Реализация функции зума камеры
void ALMADefaultCharacter::MouseWheelZoom(float Value) 
{
  if (SpringArmComponent && FMath::Abs(Value) > 0.1f) 
  {
    // Вычисляем новое значение длины SpringArm
    float NewArmLength = SpringArmComponent->TargetArmLength - (Value * ZoomSpeed);

    // Ограничиваем значение минимальными и максимальными пределами
    NewArmLength = FMath::Clamp(NewArmLength, MinArmLength, MaxArmLength);

    // Устанавливаем новую длину
    SpringArmComponent->TargetArmLength = NewArmLength;
  }
}