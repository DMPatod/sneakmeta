#include "PlayerCharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"


APlayerCharacterBase::APlayerCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacterBase::AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
{
	if (bIsSprinting && CurrentStamina <= 0.f)
	{
		SetSprinting(false);
	}

	Super::AddMovementInput(WorldDirection, ScaleValue, bForce);

	if (bIsSprinting)
	{
		bHasSprinted = true;
	}
}

void APlayerCharacterBase::Crouch(bool bClientSimulation)
{
	SetSprinting(false);
	Super::Crouch(bClientSimulation);
}

void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (GetMovementComponent())
	{
		GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
	}
}

void APlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetMovementComponent())
	{
		if (GetMovementComponent()->GetForwardVector().IsZero())
		{
			SetSprinting(false);
		}
	}

	float CurrentStaminaRegenRate = StaminaRegenRate;
	if (bHasSprinted)
	{
		CurrentStaminaRegenRate = -StaminaRegenRate;
	}
	else if (bIsCrouched)
	{
		CurrentStaminaRegenRate = RestStaminaRegenRate;
	}

	const float OldStamina = CurrentStamina;

	CurrentStamina = FMath::Clamp(CurrentStamina + CurrentStaminaRegenRate, 0.f, MaxStamina);

	if (CurrentStamina != OldStamina)
	{
		OnStaminaChanged.Broadcast(OldStamina, CurrentStamina, MaxStamina);
	}

	bHasSprinted = false;
}

void APlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

int APlayerCharacterBase::GetHealth()
{
	return CurrentHealth;
}

void APlayerCharacterBase::UpdateHealth(int DeltaHealth)
{
	if (CurrentHealth <= 0.f)
	{
		return;
	}

	int OldValue = CurrentHealth;
	CurrentHealth += DeltaHealth;

	CurrentHealth = FMath::Clamp(CurrentHealth, -1.f, MaxHealth);

	if (OldValue != CurrentHealth)
	{
		OnHealthChanged.Broadcast(OldValue, CurrentHealth, MaxHealth);
	}

	if (CurrentHealth <= 0.f)
	{
		OnPlayerDied.Broadcast();
	}
}

void APlayerCharacterBase::SetMaxHealth(int NewMaxHealth)
{
	MaxHealth = NewMaxHealth;
}

float APlayerCharacterBase::GetStamina()
{
	return CurrentStamina;
}

float APlayerCharacterBase::GetStaminaRegenRate()
{
	return StaminaRegenRate;
}

void APlayerCharacterBase::SetStaminaRegenRate(float NewStaminaRegenRate)
{
	StaminaRegenRate = NewStaminaRegenRate;
}

void APlayerCharacterBase::SetSprinting(bool IsSprinting)
{
	bIsSprinting = IsSprinting;

	GetCharacterMovement()->MaxWalkSpeed = bIsSprinting ? NormalMaxWalkSpeed : SprintingMaxWalkSpeed;
}

void APlayerCharacterBase::ToggleSprint()
{
	SetSprinting(!bIsSprinting);
}

void APlayerCharacterBase::BroadcastCurrentStats()
{
	OnHealthChanged.Broadcast(CurrentHealth, CurrentHealth, MaxHealth);
	OnStaminaChanged.Broadcast(CurrentStamina, CurrentStamina, MaxStamina);
}
