// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;	  

UENUM(BlueprintType)
enum class EMovementState : uint8 
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class BASECPP_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	FString PlayerName = "Abc";

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 123.1231231f;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	// Переменные для синусоидального движения
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sin Movement")
    float Amplitude = 50.0f; // Амплитуда колебаний

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sin Movement")
    float Frequency = 2.0f; // Частота колебаний

    // Начальная позиция актора
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sin Movement")
    FVector InitialLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
    void ShowActorInformation();

    // Функция синусоидального движения
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void SinMovement();

};
