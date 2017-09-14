// Fill out your copyright notice in the Description page of Project Settings.

#include "DawnBreakers.h"
#include "DBZombieAIController.h"
#include "DawnBreakers/GameLogic/Character/DBBaseCharacter.h"
#include "DawnBreakers/GameLogic/Character/NPC/DBZombieCharacter.h"
#include "DawnBreakers/GameLogic/AI/Misc/DBBotWayPoint.h"




ADBZombieAIController::ADBZombieAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	PatrolLocationKeyName = TEXT("PatrolLocation");
	CurrentWaypointKeyName = TEXT("CurrentWaypoint");
	TargetEnemyKeyName = TEXT("TargetEnemy");
}

void ADBZombieAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ADBZombieAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	ADBZombieCharacter* ZombieBot = Cast<ADBZombieCharacter>(InPawn);

	if (ZombieBot && 
		ZombieBot->BehaviorTree && 
		BehaviorComp)
	{
		BlackboardComp->InitializeBlackboard(*ZombieBot->BehaviorTree->BlackboardAsset);
		

		TArray<AActor*> AllWaypoints;
		UGameplayStatics::GetAllActorsOfClass(this, ADBBotWayPoint::StaticClass(), AllWaypoints);

		float Dist = FLT_MAX;
		for (int32 i = 0; i < AllWaypoints.Num(); ++i)
		{
			float fDist = FVector::DistSquared(InPawn->GetActorLocation(), AllWaypoints[i]->GetActorLocation());
			if (fDist < Dist)
			{
				Dist = fDist;
				ZombieWayPoint = AllWaypoints[i];
			}
		}

		BehaviorComp->StartTree(*ZombieBot->BehaviorTree);
	}
}

void ADBZombieAIController::UnPossess()
{
	Super::UnPossess();

	BehaviorComp->StopTree();
}

ADBBotWayPoint* ADBZombieAIController::GetWaypoint()
{
	if (BlackboardComp)
	{
		return Cast<ADBBotWayPoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
	}

	return nullptr;
}

ADBBaseCharacter* ADBZombieAIController::GetTargetEnemy()
{
	if (BlackboardComp)
	{
		return Cast<ADBBaseCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}

void ADBZombieAIController::SetWaypoint(ADBBotWayPoint* NewWaypoint)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(CurrentWaypointKeyName, NewWaypoint);
	}
}

void ADBZombieAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}
