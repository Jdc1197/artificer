#ifndef ACTIONPICKUP_H
#define ACTIONPICKUP_H
#include <vector>
#include "Menu.h"
#include "Item.h"
#include "List.h"
#include "Graphics/GraphicsPickup.h"

using std::vector;

// class ActionPickUp : public Menu
// Menu class which implements picking up of multiple items from the map
class ActionPickUp : public Menu
{
private:
	GraphicsPickup* Renderer;
	Being* Sender;
	vector<Item*> ItemList;
	vector<Item*> PickupList;
	void Pickup();
	
	bool Close;		// Whether or not to close the menu
public:
	ActionPickUp(int, int, Being*);
	~ActionPickUp();
	virtual void HandleInput(TCOD_key_t);
	virtual void Draw();
	virtual void Init();
};

#endif