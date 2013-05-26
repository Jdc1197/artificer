#include "Graphics/GraphicsPickup.h"
#include "Inventory.h"



GraphicsPickup::GraphicsPickup(vector<Item*> Items, vector<Item*>* Pickup)
{
	this->ItemList = Items;
	this->PickupList = Pickup;
}

void GraphicsPickup::Draw()
{
	TCODConsole::root->clear();
	TCODConsole::root->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - Pick up items");
	
	// Print items
	for (unsigned int i = 0; i < ItemList.size(); i++)
	{
		char Seperator = '-';  // seperator between the item and identifier
		char Identifier = Inventory::GenerateIdentifier(i);
		
		Item * I = ItemList[i];
		if (IsInList<Item*>(PickupList, I))
			Seperator = '+';
		TCODConsole::root->printLeft(0, i+2, TCOD_BKGND_NONE, "%c %c %s", Identifier, Seperator, I->GetFullName());
	}
}