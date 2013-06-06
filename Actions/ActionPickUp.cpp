/*	
	Artificer: A roguelike game.
    Copyright (C) 2013 Jdc1197

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Contact Jdc1197 by email at: Jdc1197@gmail.com
*/

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