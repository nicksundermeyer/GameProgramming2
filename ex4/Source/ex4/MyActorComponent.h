// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EX4_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UMyActorComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	AActor *myParent;

	UPROPERTY(EditAnywhere)
	TArray<AActor *> myChildren;

	UPROPERTY(EditAnywhere)
	FTransform LocalTransform;

	UPROPERTY(EditAnywhere)
	FQuat rotSpeed;

	// adjust scale, rotation, translation of LocalTransform
	UFUNCTION(BlueprintCallable)
	void Scale(FVector newScale);

	UFUNCTION(BlueprintCallable)
	void Rotate(FQuat newRot);

	UFUNCTION(BlueprintCallable)
	void Translate(FVector newTrans);
};
