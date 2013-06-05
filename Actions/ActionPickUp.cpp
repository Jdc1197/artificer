#include "Actions/ActionPickUp.h"
#include "Reference.h"

ActionPickUp::ActionPickUp(int x, int y, Being * B)
{
	Sender = B;
	Renderer = nullptr;
	if (MapReference::IsItemOnTile(x,y))
	{
		ItemList = MapReference::GetItemsOnTile(x,y);
		// If there is only one item, pick it up and close the menu before it opens
		if (ItemList.size() == 1)
		{
			PickupList.push_back(ItemList[0]);
			Pickup();
			Close = true;
		}
		else
		{	
			Close = false;
			Renderer = new GraphicsPickup(ItemList, &PickupList);
		}
	}
	else
		Close = true;
}

ActionPickUp::~ActionPickUp() { if (Renderer) delete Renderer; }

void ActionPickUp::Init()
{
	if (Close)
		GameReference::CloseMenu();
}

// ActionPickUp::Pickup()
// Picks up all of the items in PickupList
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
	if (Renderer != nullptr)
		Renderer->Draw();
}