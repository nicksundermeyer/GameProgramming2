// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsActor.h"
#include "ConstructorHelpers.h"
#include "Engine/Engine.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
APhysicsActor::APhysicsActor(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootCollision"));
	MeshComponent->SetHiddenInGame(false);

	RootComponent = MeshComponent;

	OnActorHit.AddDynamic(this, &APhysicsActor::OnMyHit);
	MeshComponent->SetNotifyRigidBodyCollision(true);

	// add audio component
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));

	// add explosion audiocue to audio component
	AudioComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void APhysicsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APhysicsActor::OnMyHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	print(OtherActor->GetActorLabel());

	if (!AudioComponent->IsPlaying())
	{
		AudioComponent->SetSound(ExplosionCue);
		AudioComponent->Play();
	}
}