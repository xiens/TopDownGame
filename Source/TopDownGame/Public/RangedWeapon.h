// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponComponent.h"
#include "RangedWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNGAME_API URangedWeapon : public UWeaponComponent
{
	GENERATED_BODY()

	virtual void Attack() override;
};
