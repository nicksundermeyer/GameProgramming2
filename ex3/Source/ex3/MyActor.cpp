// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// creating mesh component and setting as root
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = mesh;
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> asset(TEXT("/Game/Meshes/Shape_Sphere.Shape_Sphere"));
	if(asset.Succeeded())
	{
		mesh->SetStaticMesh(asset.Object);
	}

	// adding scene component
	scene = CreateDefaultObject<USceneComponent>(TEXT("SceneComponent"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

