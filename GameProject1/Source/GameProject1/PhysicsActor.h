// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundCue.h"
#include "GameFramework/Actor.h"
#include "PhysicsActor.generated.h"

UCLASS()
class GAMEPROJECT1_API APhysicsActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APhysicsActor(const FObjectInitializer& objectInitializer);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnMyHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
		UAudioComponent* AudioComponent;

};
