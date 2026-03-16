// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MovementSpeed = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDistance = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Plane;

	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity;


	UFUNCTION()
	void MovePlatform(const float DeltaTime);

	UFUNCTION()
	void RotatePlatform(const float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector CurrentLocation;
	FVector StartingLocation;
	double Distance;
};