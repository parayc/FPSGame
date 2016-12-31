// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameLogic/Equip/Weapon/WeaponState/DBWeaponStateBase.h"
#include "DBWeaponStateEquiping.generated.h"

/**
 * 
 */
UCLASS()
class DAWNBREAKERS_API UDBWeaponStateEquiping : public UDBWeaponStateBase
{
	GENERATED_UCLASS_BODY()



protected:
	UPROPERTY(EditDefaultsOnly, Category = WeaponState)
	float m_EquipTime;

	UPROPERTY(EditDefaultsOnly, Category = WeaponState)
	UAnimMontage* m_EquipAnim;

	UPROPERTY(EditDefaultsOnly, Category = WeaponState)
	USoundCue* m_EquipSound;
	
};
