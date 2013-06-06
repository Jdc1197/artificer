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

#include "Graphics/GraphicsPickup.h"
#include "Inventory.h"



GraphicsPickup::GraphicsPickup(vector<Item*> Items, vector<Item*>* Pickup)
{
	this->ItemList = Items;
	this->PickupList = Pickup;
}

void GraphicsPickup::Draw()
{
	RootConsole->clear();
	RootConsole->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - Pick up items");
	
	// Print items
	for (unsigned int i = 0; i < ItemList.size(); i++)
	{
		char Seperator = '-';  // seperator between the item and identifier
		char Identifier = Inventory::GenerateIdentifier(i);
		
		Item * I = ItemList[i];
		if (IsInList<Item*>(PickupList, I))
			Seperator = '+';
		RootConsole->printLeft(0, i+2, TCOD_BKGND_NONE, "%c %c %s", Identifier, Seperator, I->GetFullName());
	}
}