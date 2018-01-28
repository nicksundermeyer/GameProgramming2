// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// set up LocalTransform
	// if (myParent == nullptr)
	// {
	// 	LocalTransform = GetOwner()->GetTransform();
	// }
}

// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// if (GetOwner())
	// {
	// 	FTransform newTransform = myParent->GetActorTransform() * GetOwner()->GetActorTransform();

	// 	GetOwner()->SetActorTransform(newTransform);
	// }
}

// Helper functions
// void Scale(FVector newScale)
// {
// 	LocalTransform.SetScale3D(LocalTransform.GetScale3D() + newScale);
// }

// void Rotate(FQuat newRot)
// {
// 	LocalTransform.SetRotation(LocalTransform.GetRotation() + newRotation);
// }
// void Translate(FVector newTrans)
// {
// 	LocalTransform.SetTranslation(LocalTransform.GetTranslation() + newTrans);
// }