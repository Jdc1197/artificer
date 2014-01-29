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

#include <string.h>
#include <sstream>
#include "StandardItem.h"
#include "Being.h"
#include "Reference.h"

void StandardItem::PlaceInInventory(Inventory * ToPlaceInto)
{
	if (ToPlaceInto->AddItem(this))
		MapReference::RemoveItem(this, false);
	return;
}

void StandardItem::GetPickedUp(Being * B)
{
	if (B->Inv.GetSize() != B->Inv.GetCapacity())
	{
		std::ostringstream str;
		str << "You pick up " << this->GetShortName() << ".";
		InterfaceReference::AddMessage(&str);
		PlaceInInventory(&B->Inv);
	}
	else
		InterfaceReference::AddMessage("You cannot pick up this item, your inventory is full");
}

void StandardItem::GetPlaced(Being * B)
{
	B->Inv.RemoveItem(this, false);
	MapReference::AddItem(this, B->GetX(), B->GetY());
	std::ostringstream str;
	str << "You drop " << this->GetShortName() << ".";
	InterfaceReference::AddMessage(&str);
}