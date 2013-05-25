#include "Actions/ActionPickUp.h"
#include "Reference.h"

ActionPickUp::ActionPickUp(int x, int y, Being * B)
{
	if (MapReference::IsItemOnTile(x,y))
	{
		vector<Item*> ItemList = MapReference::GetItemsOnTile(x,y);
		if (ItemList.size() == 1)
		{
			B->Send(ItemList[0], PICKUP);
		}
	}
}

void ActionPickUp::HandleInput(TCOD_key_t key)
{
	GameReference::CloseMenu();
}

void ActionPickUp::Draw()
{

}