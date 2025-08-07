#include "HealthStaminaBarsBase.h"

#include "StatBarBase.h"

void UHealthStaminaBarsBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (HealthBar)
	{
		HealthBar->SetDetailed(Details);
	}
	if (StaminaBar)
	{
		StaminaBar->SetDetailed(Details);
	}
}
