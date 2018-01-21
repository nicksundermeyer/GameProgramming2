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

	
	
}

// Called every frame
void AMyActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

