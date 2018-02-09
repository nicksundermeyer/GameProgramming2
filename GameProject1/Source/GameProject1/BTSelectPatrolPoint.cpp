// Fill out your copyright notice in the Description page of Project Settings.

#include "BTSelectPatrolPoint.h"
#include "AIPatrolPoint.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"

//EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	// get reference to enemy ai controller
//	AEnemyAIController* AICon = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
//
//	if (AICon)
//	{
//		// get BB component
//		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();
//
//		AAIPatrolPoint* CurrentPoint = Cast<AAIPatrolPoint>(BlackboardComp->GetValueAsObject("targetLoc"));
//
//		TArray<AActor*> AvailablePatrolPoints = AICon->GetPatrolPoints();
//
//		AAIPatrolPoint* NextPatrolPoint = nullptr;
//
//		// if not at end of array
//		if (AICon->CurrentPatrolPoint != (AvailablePatrolPoints.Num() - 1))
//		{
//			// move to next patrol point in array
//			NextPatrolPoint = Cast<AAIPatrolPoint>(AvailablePatrolPoints[++AICon->CurrentPatrolPoint]);
//		}
//		else // if there are not any more points to go to, go back to the start
//		{
//			NextPatrolPoint = Cast<AAIPatrolPoint>(AvailablePatrolPoints[0]);
//			AICon->CurrentPatrolPoint = 0;
//		}
//
//		// update blackboard component
//		BlackboardComp->SetValueAsObject("targetLoc", NextPatrolPoint);
//
//		return EBTNodeResult::Succeeded;
//	}
//	return EBTNodeResult::Failed;
//}