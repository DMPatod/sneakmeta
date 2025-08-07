// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "ItemDialogBase.generated.h"

/**
 *
 */
UCLASS(Abstract)
class SNEAKMETACORE_API UItemDialogBase : public UWidgetBase
{
public:


#if WITH_EDITOR
	virtual void OnDesignerChanged(const FDesignerChangedEventArgs& EventArgs) override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR


private:
	void UpdatedWidget();

	GENERATED_BODY()

};
