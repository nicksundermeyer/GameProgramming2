// Fill out your copyright notice in the Description page of Project Settings.

#include "AMyActor.h"


// Sets default values
AAMyActor::AAMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

