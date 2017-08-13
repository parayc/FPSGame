// Fill out your copyright notice in the Description page of Project Settings.

#include "DawnBreakers.h"
#include "DBZombieSurviveGameMode.h"

ADBZombieSurviveGameMode::ADBZombieSurviveGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = ADBZombieModePlayerController::StaticClass();
}

class ADBZombieCharacter* ADBZombieSurviveGameMode::SpawnZombie()
{
	return nullptr;
}

