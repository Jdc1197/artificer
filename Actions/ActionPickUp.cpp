#include "Actions/ActionPickUp.h"
#include "Graphics/GraphicsPickup.h"
#include "Reference.h"

ActionPickUp::ActionPickUp(int x, int y, Being * B)
{
	Sender = B;
	if (MapReference::IsItemOnTile(x,y))
	{
		ItemList = MapReference::GetItemsOnTile(x,y);
	}
}

void ActionPickUp::Pickup()
{
	for (unsigned int i = 0; i < PickupList.size(); i++)
		Sender->Send(PickupList[i], PICKUP);
}

void ActionPickUp::HandleInput(TCOD_key_t key)
{
	int Number = 0;
	if (key.vk == TCODK_ESCAPE || key.vk == TCODK_DELETE)
		GameReference::CloseMenu();
	else if (key.vk == TCODK_ENTER)
	{
		Pickup();
		GameReference::CloseMenu();
	}
	else
	{
		Number = Inventory::GenerateNumber(key.c);
		if (Number != -1 && Number < (signed int)ItemList.size())
		{	
			if (IsInList<Item*>(&PickupList, ItemList[Number]))
				RemoveFromList<Item*>(&PickupList, ItemList[Number]);
			else
				PickupList.push_back(ItemList[Number]);
		}
	}
		
}

void ActionPickUp::Draw()
{
	GraphicsPickup G(ItemList, &PickupList);
	G.Draw();
}