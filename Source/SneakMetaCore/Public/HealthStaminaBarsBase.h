// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "HealthStaminaBarsBase.generated.h"

class UStatBarBase;

UCLASS(Abstract)
class SNEAKMETACORE_API UHealthStaminaBarsBase : public UWidgetBase
{
public:
	UPROPERTY(EditAnywhere, Category = "Stat Bars")
	bool Details = false;

	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UStatBarBase> HealthBar = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UStatBarBase> StaminaBar = nullptr;

private:
	virtual void NativeOnInitialized() override;

	GENERATED_BODY()

};
