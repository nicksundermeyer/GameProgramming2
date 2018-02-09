// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT1_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

private:
	// blackboard and behavior tree
	UBlackboardComponent* blackboardComp;
	UBehaviorTreeComponent* behaviorComp;

	UPROPERTY(EditDefaultsOnly, Category = AI)
		FName targetLoc;

	UPROPERTY(EditDefaultsOnly, Category = AI)
		FName playerKey;

	TArray<AActor *> patrolPoints;

	virtual void Possess(APawn* pawn) override;
	
public:
	
	AEnemyAIController();

	int32 CurrentPatrolPoint = 0;

	UBlackboardComponent* GetBlackboardComponent() const { return blackboardComp; }
	TArray<AActor*> GetPatrolPoints() const { return patrolPoints; }
	
};
