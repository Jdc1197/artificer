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

#include "Graphics/GraphicsInventory.h"


GraphicsInventory::GraphicsInventory(Inventory* inventory, const char* str)
{
	inv = inventory;
	title = str;
}

void GraphicsInventory::Draw()
{
	RootConsole->clear();
	// Print inventory capacity
	RootConsole->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - %d/%d          %s", inv->GetSize(), inv->GetCapacity(), title);
	// Print items
	for (int i = 0; i < inv->GetSize(); i++)
	{
		Item * I = inv->GetItem(i);
		char C = inv->GetIdentifier(i);
		RootConsole->printLeft(0, i+2, TCOD_BKGND_NONE, "%c - %s", C, I->GetFullName());
	}
}

/*void GraphicsInventory::DrawInventory(Inventory * Inv, const char * ActionString, TCODConsole * Console)
{
	RootConsole->clear();
	// Print inventory capacity
	Console->printLeft(0, 0, TCOD_BKGND_NONE, "Inventory - %d/%d          %s", Inv->GetSize(), Inv->GetCapacity(), ActionString);
	// Print items
	for (int i = 0; i < Inv->GetSize(); i++)
		{
			Item * I = Inv->GetItem(i);
			char C = Inv->GetIdentifier(i);
			Console->printLeft(0, i+2, TCOD_BKGND_NONE, "%c - %s", C, I->GetFullName());
	}
}

void GraphicsInventory::DrawInventory(Inventory * Inv, const char * ActionString)
{
	DrawInventory(Inv, ActionString, TCODConsole::root);
}

void GraphicsInventory::DrawInventory(Inventory * Inv)
{
	// Draw to the root console automatically
	DrawInventory(Inv, "", TCODConsole::root);
}*/