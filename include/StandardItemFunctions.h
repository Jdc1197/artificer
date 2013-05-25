#ifndef STANDARDITEMFUNCTIONS_H
#define STANDARDITEMFUNCTIONS_H
#include "Item.h"
#include "Inventory.h"

class StandardItemFunctions : public Item
{
protected:
	void PlaceInInventory(Inventory*);
	void GetPickedUp(Being*);
	void GetPlaced(Being*);
};


#endif