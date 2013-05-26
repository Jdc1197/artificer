#ifndef ACTIONPICKUP_H
#define ACTIONPICKUP_H
#include <vector>
#include "Menu.h"
#include "Item.h"
#include "List.h"

using std::vector;

class ActionPickUp : public Menu
{
private:
	Being* Sender;
	vector<Item*> ItemList;
	vector<Item*> PickupList;
	void Pickup();
public:
	ActionPickUp(int, int, Being*);
	virtual void HandleInput(TCOD_key_t);
	virtual void Draw();
};

#endif