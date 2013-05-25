#include "MenuInventory.h"
#include "InventoryGraphics.h"
#include "Game.h"
#include "Reference.h"


MenuInventory::MenuInventory(Inventory* Inv) { this->Inv = Inv; }
MenuInventory::~MenuInventory() { GameRef::CloseMenu(); }

void MenuInventory::Draw() 
{
	InventoryGraphics::DrawInventory(Inv, "Viewing Inventory");
}

void MenuInventory::HandleInput(TCOD_key_t Key)
{
	GameReference::CloseMenu();
	return;
}