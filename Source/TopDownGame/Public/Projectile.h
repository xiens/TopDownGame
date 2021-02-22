// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOPDOWNGAME_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	class URangedWeapon * RangedWeapon;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE void SetOwningWeapon(URangedWeapon * WeaponToSet) { RangedWeapon = WeaponToSet; } //TODO Set when spawning projectile

	FORCEINLINE URangedWeapon * GetOwningWeapon() const { return RangedWeapon; }
};
