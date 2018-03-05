// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingActor.h"
#include "Engine/Engine.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(Speed*(RunningTime + DeltaTime)) - FMath::Sin(Speed*RunningTime));
	NewLocation.Z += DeltaHeight * Distance;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

