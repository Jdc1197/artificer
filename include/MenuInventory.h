#ifndef MENUINVENTORY_H
#define MENUINVENTORY_H
#include "Inventory.h"
#include "Menu.h"

class MenuInventory : public Menu 
{
private:
	Inventory* Inv;
public:
	MenuInventory(Inventory*);
	~MenuInventory();

	virtual void Draw();
	virtual void HandleInput(TCOD_key_t);
};

#endif