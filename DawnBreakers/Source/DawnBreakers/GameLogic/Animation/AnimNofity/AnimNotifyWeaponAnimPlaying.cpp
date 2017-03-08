// Fill out your copyright notice in the Description page of Project Settings.

#include "DawnBreakers.h"
#include "AnimNotifyWeaponAnimPlaying.h"




UAnimNotifyWeaponAnimPlaying::UAnimNotifyWeaponAnimPlaying()
{
	
}

void UAnimNotifyWeaponAnimPlaying::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	DAWNBREAKERS_LOG_INFO("UAnimNotifyWeaponAnimPlaying::Notify");

	UAnimInstance* TAnimInstance = MeshComp->GetAnimInstance();
	if (TAnimInstance && TAnimInstance->IsValidLowLevel())
	{
		UDBCharacterAnimInstance* TDBCharacterAnimInstance = Cast<UDBCharacterAnimInstance>(TAnimInstance);
		if (TDBCharacterAnimInstance && TDBCharacterAnimInstance->IsValidLowLevel())
		{
			ADBCharacter* TDBCharacter = TDBCharacterAnimInstance->GetCharacter();
			if (TDBCharacter)
			{
				ADBWeaponBase* TWeapon = TDBCharacter->GetHoldWeapon();
				if (TWeapon)
				{
					TWeapon->OnWeaponAnimPlayingOnePoint().Broadcast();
				}
			}
		}
	}
}
