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

	ConstructorHelpers::FObjectFinder<UStaticMesh> asset(TEXT("/Game/Game/Meshes/Shape_Sphere.Shape_Sphere"));
	if (asset.Succeeded())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Set mesh"));
		mesh->SetStaticMesh(asset.Object);
		mesh->SetWorldScale3D(FVector(.50f));
	}

	// adding scene component
	scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = mesh;
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

	this->SetActorRotation(this->GetActorRotation() + FRotator(0.f, 0.5f, 0.f));
}
