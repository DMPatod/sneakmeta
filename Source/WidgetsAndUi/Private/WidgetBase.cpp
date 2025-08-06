#include "WidgetBase.h"

#if WITH_EDITOR

const FText UWidgetBase::GetPaletteCategory()
{
	return NSLOCTEXT("UMG", "CustomPaletteCategory", "Player UI");
}

#endif