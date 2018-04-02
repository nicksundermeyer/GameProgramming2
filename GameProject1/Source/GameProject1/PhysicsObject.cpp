// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsObject.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
APhysicsObject::APhysicsObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootCollision"));
	MeshComponent->SetHiddenInGame(false);

	RootComponent = MeshComponent;

	OnActorHit.AddDynamic(this, &APhysicsObject::OnMyHit);
	MeshComponent->SetNotifyRigidBodyCollision(true);

	// add audio component
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void APhysicsObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APhysicsObject::OnMyHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	//print(FString::SanitizeFloat(NormalImpulse.Size()));

	if (!AudioComponent->IsPlaying())
	{
		AudioComponent->SetVolumeMultiplier(NormalImpulse.Size() / (sensitivity*1000));
		AudioComponent->Play();
	}
}