// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponComponent.h"
#include "MeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNGAME_API UMeleeWeapon : public UWeaponComponent
{
	GENERATED_BODY()

	virtual void Attack() override;
};
