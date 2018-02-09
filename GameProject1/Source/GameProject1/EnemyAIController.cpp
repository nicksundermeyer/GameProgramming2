// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "BasicEnemyPawn.h"
#include "AIPatrolPoint.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AEnemyAIController::AEnemyAIController()
{
	// initialize blackboard and behavior tree
	behaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("behaviorComp"));
	blackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("blackboardComp"));

	// initialize blackboard keys
	playerKey = "target";
	targetLoc = "targetLoc";
}

void AEnemyAIController::Possess(APawn* pawn)
{
	Super::Possess(pawn);

	// get reference to character
	ABasicEnemyPawn* enemyPawn = Cast<ABasicEnemyPawn>(pawn);

	// if enemy pawn and blackboard asset exist, initialize blackboard
	if (enemyPawn)
	{
		if (enemyPawn->behaviorTree->BlackboardAsset)
		{
			blackboardComp->InitializeBlackboard(*(enemyPawn->behaviorTree->BlackboardAsset));
		}

		// find ai patrol points in world, start behavior tree on points
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), patrolPoints);

		behaviorComp->StartTree(*enemyPawn->behaviorTree);
	}
}