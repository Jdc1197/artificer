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