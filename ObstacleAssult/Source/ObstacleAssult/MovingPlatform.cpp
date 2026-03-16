// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	const ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneObj(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Plane.Plane'"));

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane ->SetupAttachment(RootComponent);
	Plane->SetStaticMesh(PlaneObj.Object);
	Plane->SetWorldScale3D(FVector(3.f));
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartingLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

//Moving platform
void AMovingPlatform::MovePlatform(const float DeltaTime) {
	
	SetActorLocation(GetActorLocation() + (MovementSpeed * DeltaTime));

	Distance = FVector::Dist(GetActorLocation(), GetStartingPoint());

	if (Distance >= MaxDistance) {
		MovementSpeed = -MovementSpeed;

		StartingLocation = GetActorLocation();
	}
}

//Rotating platform
void AMovingPlatform::RotatePlatform(const float DeltaTime) {


}
