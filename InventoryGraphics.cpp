#include "InventoryGraphics.h"

void InventoryGraphics::DrawInventory(Inventory * Inv, const char * ActionString, TCODConsole * Console)
{
	Console->clear();
	// Print inventory capacity
	Console->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - %d/%d          %s", Inv->GetSize(), Inv->GetCapacity(), ActionString);
	// Print items
	for (int i = 0; i < Inv->GetSize(); i++)
		{
			Item * I = Inv->GetItem(i);
			char C = Inv->GetIdentifier(i);
			Console->printLeft(0, i+2, TCOD_BKGND_NONE, "%c - %s", C, I->GetFullName());
	}
}

void InventoryGraphics::DrawInventory(Inventory * Inv, const char * ActionString)
{
	DrawInventory(Inv, ActionString, TCODConsole::root);
}

void InventoryGraphics::DrawInventory(Inventory * Inv)
{
	// Draw to the root console automatically
	DrawInventory(Inv, "", TCODConsole::root);
}