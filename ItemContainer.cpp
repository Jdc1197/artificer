#include "Inventory.h"

ItemContainer::ItemContainer()
{
	Identifier = ' '; 
	I = nullptr;
}

ItemContainer::ItemContainer(Item * Item, char ID)
{
	Identifier = ID;
	I = Item;
}

char ItemContainer::GetIdentifier()
{
	return Identifier;
}

Item * ItemContainer::GetItem()
{
	return I;
}

void ItemContainer::SetIdentifier(char ID)
{
	Identifier = ID;
}

void ItemContainer::SetItem(Item * Item)
{
	I = Item;
}