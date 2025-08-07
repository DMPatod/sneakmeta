// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDialogBase.h"

void UItemDialogBase::UpdatedWidget()
{
}

#if WITH_EDITOR
void UItemDialogBase::OnDesignerChanged(const FDesignerChangedEventArgs& EventArgs)
{
	Super::OnDesignerChanged(EventArgs);
	UpdatedWidget();
}

void UItemDialogBase::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FString PropertyName = ((PropertyChangedEvent.Property != nullptr)
		? PropertyChangedEvent.Property->GetFName()
		: NAME_None).ToString();

	if (PropertyName == TEXT("CurrentPercentage") || PropertyName == TEXT("CurrentValue") || PropertyName ==
		TEXT("NameValue") || PropertyName == TEXT("Detailed"))
	{
		UpdatedWidget();
	}
}
#endif