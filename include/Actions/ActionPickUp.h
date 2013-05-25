#ifndef ACTIONPICKUP_H
#define ACTIONPICKUP_H
#include "Menu.h"
#include "Item.h"

class ActionPickUp : public Menu
{
public:
	ActionPickUp(int, int, Being*);
	virtual void HandleInput(TCOD_key_t);
	virtual void Draw();
};

#endif