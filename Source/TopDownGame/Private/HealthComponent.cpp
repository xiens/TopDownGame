#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::ChangeHealth(float Percentage, bool IsIncreased)
{
	IsIncreased ? HealthPercentage += Percentage : HealthPercentage -= Percentage;

	HealthPercentage = FMath::Clamp<float>(HealthPercentage, 0.0f, 100.0f);

	if(HealthPercentage == 0.0f)
	{
		OnHealthReachedZero.Broadcast();
	}
}

