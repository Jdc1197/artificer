#include <string.h>
#include <sstream>
#include "StandardItemFunctions.h"
#include "Being.h"
#include "Reference.h"

void StandardItemFunctions::PlaceInInventory(Inventory * ToPlaceInto)
{
	if (ToPlaceInto->AddItem(this))
		MapReference::RemoveItem(this, false);
	return;
}

void StandardItemFunctions::GetPickedUp(Being * B)
{
	if (B->Inv.GetSize() != B->Inv.GetCapacity())
	{
		std::ostringstream str;
		str << "You pick up " << this->GetShortName() << ".";
		InterfaceReference::AddMessage(&str);
		PlaceInInventory(&B->Inv);
	}
	else
		InterfaceReference::AddMessage("You cannot pick up this item, your inventory is full");
}

void StandardItemFunctions::GetPlaced(Being * B)
{
	B->Inv.RemoveItem(this, false);
	MapReference::AddItem(this, B->GetX(), B->GetY());
	std::ostringstream str;
	str << "You drop " << this->GetShortName() << ".";
	InterfaceReference::AddMessage(&str);
}