// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorSpawner.h"
#include "MyActor.h"

// Sets default values
AMyActorSpawner::AMyActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
}

// Called every frame
void AMyActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorSpawner::Spawn()
{
	AActor* Actor1 = GetWorld()->SpawnActor<AActor>(ToSpawn, FVector(0.f, 0.f, 100.f), FRotator::ZeroRotator);

	AActor* Actor2 = GetWorld()->SpawnActor<AActor>(ToSpawn, FVector(100.f, 0.f, 100.f), FRotator::ZeroRotator);
}
