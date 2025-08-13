#include "HealthStaminaBarsBase.h"

#include "StatBarBase.h"

void UHealthStaminaBarsBase::SetDetails(bool Details)
{
    if (HealthBar)
    {
        HealthBar->SetDetails(Details);
    }
    if (StaminaBar)
    {
        StaminaBar->SetDetails(Details);
    }
}
