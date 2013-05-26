#include "Graphics/GraphicsPickup.h"
#include "Inventory.h"



GraphicsPickup::GraphicsPickup(vector<Item*> Items, vector<Item*>* Pickup)
{
	this->ItemList = Items;
	this->PickupList = Pickup;
}

void GraphicsPickup::Draw()
{
	//TCODConsole * Console = TCODConsole::root;
	TCODConsole::root->clear();
	// Print inventory capacity
	TCODConsole::root->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - Pick up items");
	
	// Print items
	for (unsigned int i = 0; i < ItemList.size(); i++)
	{
			char Seperator = '-';			// the character to display between the identifier and the item name
			Item * I = ItemList[i];
			if (IsInList<Item*>(PickupList, I))
				Seperator = '+';
			char Identifier = Inventory::GenerateIdentifier(i);
			TCODConsole::root->printLeft(0, i+2, TCOD_BKGND_NONE, "%c %c %s", Identifier, Seperator, I->GetFullName());
	}
}