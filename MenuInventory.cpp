#include "MenuInventory.h"
#include "Graphics/GraphicsInventory.h"
#include "Game.h"
#include "Reference.h"


MenuInventory::MenuInventory(Inventory* Inv) { this->Inv = Inv; }
MenuInventory::~MenuInventory() {/*GameReference::CloseMenu();*/}

void MenuInventory::Draw() 
{
	GraphicsInventory InventoryRenderer(Inv, "Viewing Inventory");
	InventoryRenderer.Draw();
}

void MenuInventory::HandleInput(TCOD_key_t Key)
{
	GameReference::CloseMenu();
	return;
}