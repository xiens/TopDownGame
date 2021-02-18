// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TopDownCharacter.generated.h"

UCLASS()
class TOPDOWNGAME_API ATopDownCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATopDownCharacter();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	class UHealthComponent * HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UWeaponComponent * WeaponComponent;

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
private:

	bool CanAttack = false;
	float MinTimeBetweenAttacks = 1.0f;
	FTimerHandle TimerHandle;

	void WaitToResetAttack();

	UFUNCTION()
	void KillPlayer();
	
public:

	UFUNCTION(BlueprintCallable)
	void SetWeaponMesh(UStaticMeshComponent * StaticMeshComponent);
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
