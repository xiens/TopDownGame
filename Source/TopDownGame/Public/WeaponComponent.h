// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNGAME_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
	float DamagePerHit = 20.0f;

	UPROPERTY(EditDefaultsOnly)
	float ReloadTime = 2.0f; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent * WeaponMesh;

public:

	FORCEINLINE float GetDamagePerHit() const { return DamagePerHit; }
	
	FORCEINLINE UStaticMeshComponent * GetWeaponMesh() const { return WeaponMesh; }

	FORCEINLINE void SetWeaponMesh(UStaticMeshComponent* StaticMeshComponent){ WeaponMesh = StaticMeshComponent;}
};
