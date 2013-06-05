#include "Graphics/GraphicsInventory.h"


GraphicsInventory::GraphicsInventory(Inventory* inventory, const char* str)
{
	inv = inventory;
	title = str;
}

void GraphicsInventory::Draw()
{
	RootConsole->clear();
	// Print inventory capacity
	RootConsole->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - %d/%d          %s", inv->GetSize(), inv->GetCapacity(), title);
	// Print items
	for (int i = 0; i < inv->GetSize(); i++)
	{
		Item * I = inv->GetItem(i);
		char C = inv->GetIdentifier(i);
		RootConsole->printLeft(0, i+2, TCOD_BKGND_NONE, "%c - %s", C, I->GetFullName());
	}
}

/*void GraphicsInventory::DrawInventory(Inventory * Inv, const char * ActionString, TCODConsole * Console)
{
	RootConsole->clear();
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

void GraphicsInventory::DrawInventory(Inventory * Inv, const char * ActionString)
{
	DrawInventory(Inv, ActionString, TCODConsole::root);
}

void GraphicsInventory::DrawInventory(Inventory * Inv)
{
	// Draw to the root console automatically
	DrawInventory(Inv, "", TCODConsole::root);
}*/