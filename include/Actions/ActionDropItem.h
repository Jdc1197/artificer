#ifndef MENUDROPITEM_H
#define MENUDROPITEM_H
#include "Menu.h"
#include "Item.h"

class ActionDropItem : public Menu
{
public:
	virtual void HandleInput(TCOD_key_t);
	virtual void Draw();
};

#endif