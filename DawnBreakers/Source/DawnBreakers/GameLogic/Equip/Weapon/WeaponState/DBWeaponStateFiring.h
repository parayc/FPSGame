// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameLogic/Equip/Weapon/WeaponState/DBWeaponStateBase.h"
#include "DBWeaponStateFiring.generated.h"

/**
 * 
 */
UCLASS()
class DAWNBREAKERS_API UDBWeaponStateFiring : public UDBWeaponStateBase
{
	GENERATED_UCLASS_BODY()
	
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = WeaponState)
	UAnimMontage* m_FiringAnim;

	UPROPERTY(EditDefaultsOnly, Category = WeaponState)
	USoundCue* m_FiringSound;

	UPROPERTY(EditAnywhere,  Category = WeaponState)
	TArray<UParticleSystemComponent*> MuzzleFlash;
	
};
