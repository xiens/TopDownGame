#include "TopDownCharacter.h"

#include "HealthComponent.h"
#include "MeleeWeapon.h"
#include "Projectile.h"
#include "WeaponComponent.h"
#include "RangedWeapon.h"
#include "Components/CapsuleComponent.h"

ATopDownCharacter::ATopDownCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	CanAttack = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
}

void ATopDownCharacter::BeginPlay()
{
	Super::BeginPlay();

	HealthComponent->OnHealthReachedZero.AddDynamic(this, &ATopDownCharacter::KillPlayer);

	if(WeaponComponent->GetWeaponMesh())
	{
		WeaponComponent->GetWeaponMesh()->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "WeaponSocket");
	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ATopDownCharacter::OnComponentBeginOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &ATopDownCharacter::OnComponentEndOverlap);
}

void ATopDownCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UWeaponComponent * AttackingWeapon = Cast<UWeaponComponent>(OtherActor->GetComponentByClass(UWeaponComponent::StaticClass()));
	if(!AttackingWeapon)
	{
		AProjectile * Projectile = Cast<AProjectile> (OtherActor);
		if(Projectile)
		{
			URangedWeapon * Weapon = Projectile->GetOwningWeapon();
			AttackingWeapon = Cast<UWeaponComponent>(Weapon);
		}
	}
	
	if(AttackingWeapon && CanAttack)
	{
		CanAttack = false;
		HealthComponent->ChangeHealth(AttackingWeapon->GetDamagePerHit(), false);
		UE_LOG(LogTemp, Warning, TEXT(" Player hit ")); // Why is it called 2 times ?
		UE_LOG(LogTemp, Warning, TEXT(" Name:  %s"), *GetOwner()->GetName()); // Why is it called 2 times ?


		GetWorldTimerManager().SetTimer(TimerHandle, this, &ATopDownCharacter::WaitToResetAttack, 2.0f, false);
	}
}

void ATopDownCharacter::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void ATopDownCharacter::WaitToResetAttack()
{
	CanAttack = true;
	GetWorldTimerManager().ClearTimer(TimerHandle);
}

void ATopDownCharacter::KillPlayer()
{
	UE_LOG(LogTemp, Warning, TEXT("Player dead"));
}

void ATopDownCharacter::SetWeaponMesh(UStaticMeshComponent* StaticMeshComponent)
{
	if(WeaponComponent)
	{
		WeaponComponent->SetWeaponMesh(StaticMeshComponent);
	}
}

void ATopDownCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATopDownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

