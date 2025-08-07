#pragma once

#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "DebugHudLayoutBase.generated.h"

class UHealthStaminaBarsBase;
class UImage;

UCLASS(ABSTRACT)
class SNEAKMETACORE_API UDebugHudLayoutBase : public UWidgetBase
{
public:
	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UHealthStaminaBarsBase> BaseBars = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UImage> Crosshair = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Definitions", meta = (ClampMin = 0, UIMin = 0))
	float CrosshairSize = 32.f;

private:
	virtual void NativeConstruct() override;


	GENERATED_BODY()
};
