// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	// Сохраняем начальную позицию актора
        InitialLocation = GetActorLocation();

    // Вызываем информацию об акторе
    ShowActorInformation();

}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Вызываем синусоидальное движение каждый кадр
    SinMovement();

}

void ACppBaseActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *GetName());
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	
	FString AliveStatus = IsAlive ? TEXT("true") : TEXT("false");
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %s"), *AliveStatus);
	
	// Выводим информацию о движении
	UE_LOG(LogTemp, Display, TEXT("Amplitude: %f"), Amplitude);
	UE_LOG(LogTemp, Display, TEXT("Frequency: %f"), Frequency);
	UE_LOG(LogTemp, Display, TEXT("InitialLocation: %s"), *InitialLocation.ToString());
	UE_LOG(LogTemp, Display, TEXT("------------------------"));
}

void ACppBaseActor::SinMovement() {
  // Получаем текущее время
  float Time = GetWorld()->GetTimeSeconds();

  // Рассчитываем смещение по оси Z используя синусоиду
  // Формула: Z = InitialZ + Amplitude * sin(Frequency * Time)
  float DeltaZ = Amplitude * FMath::Sin(Frequency * Time);

  // Создаём новую позицию
  FVector NewLocation = InitialLocation;
  NewLocation.Z += DeltaZ;

  // Устанавливаем новую позицию актору
  SetActorLocation(NewLocation);

}

