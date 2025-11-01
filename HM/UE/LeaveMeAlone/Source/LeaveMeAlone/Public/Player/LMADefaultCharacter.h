// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/DecalComponent.h"
#include "Components/InputComponent.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent *SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent *CameraComponent;

	UPROPERTY()
	UDecalComponent *CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface *CursorMaterial = nullptr;
        
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

    //зум камеры
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MinArmLength = 300.0f; // Минимальное расстояние камеры

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
    float MaxArmLength = 3000.0f; // Максимальное расстояние камеры

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomSpeed = 100.0f; // Скорость изменения зума



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float YRotation = -75.0f; // отвечает за поворот камеры по оси Y.
	float ArmLength = 1400.0f;  // отвечает за длину штатива.
	float FOV = 55.0f; // отвечает за поле зрения камеры.

	void MoveForward(float Value); // будет отвечать за движение персонажа по оси X.
	void MoveRight(float Value); // будет отвечать за движение персонажа по оси Y.

	// Метод для обработки зума
	void MouseWheelZoom(float Value);
};
