#ifndef GRAPHICSPICKUP_H
#define GRAPHICSPICKUP_H
#include "Graphics/Graphics.h"
#include <vector>
#include "Item.h"
#include "List.h"

using std::vector;

// class GraphicsPickup
// Implements the graphics for ActionPickUp
class GraphicsPickup : public Graphics
{
private:
	vector<Item*>* PickupList;		// List of items to actually pick up
	vector<Item*> ItemList;			// List of the items on the ground
public:
	GraphicsPickup(vector<Item*>, vector<Item*>*);
	virtual void Draw();
};

#endif