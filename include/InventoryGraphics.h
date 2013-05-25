#ifndef INVENTORYGRAPHICS_H
#define INVENTORYGRAPHICS_H
#include <libtcod.hpp>
#include "Inventory.h"

class InventoryGraphics
{
public:
	static void DrawInventory(Inventory*);
	static void DrawInventory(Inventory*, const char*);
	static void DrawInventory(Inventory*, const char*, TCODConsole*);
};

#endif