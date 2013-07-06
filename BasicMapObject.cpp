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

#include "BasicMapObject.h"
#include "Being.h"
#include "Game.h"
#include "Reference.h"




// Floors
Floor::Floor() {}
void Floor::Recieve(Message msg, Being * Sender)
{
	if (msg.Type == MOVE)
	{
		if (!MapRef::IsBeingOnTile(x,y))
			Sender->Move(this->x, this->y); // Move the sender onto the new tile
		if (MapRef::IsItemOnTile(x,y))
			InterfaceRef::AddMessage(MakeItemList());
	}
	else
		return;
}

DisplayTile Floor::GetTile()
{
	return DisplayTile('.', TCODColor::white, TCODColor::black);
}

std::string Floor::MakeItemList()
{
	vector<Item*> ItemList = MapRef::GetItemsOnTile(x,y);
	string Message = "You see here ";
	for (unsigned int i = 0; i < ItemList.size(); i++)
	{
		if (i == ItemList.size() - 1 && i != 0)
			Message += "and ";
		Message += ItemList[i]->GetShortName();
		if (i != ItemList.size() - 1)
			Message += ", ";
		else
			Message += ".";
	}
	return Message;
}


// Walls
Wall::Wall() {}

void Wall::Recieve(Message msg, Being * Sender)
{
	if (msg.Type == MOVE)
		InterfaceReference::AddMessage("Ouch! You bump into a wall.");
}

DisplayTile Wall::GetTile()
{
	return DisplayTile('#', TCODColor::white, TCODColor::white);
}

bool Wall::GetTransparent() {return false;}


// Doors
Door::Door()
{
	Open = false;
}

void Door::Recieve(Message msg, Being * Sender)
{
	if (msg.Type == MOVE)
		if (Open)
			Sender->Move(this->x, this->y);		// Move the sender onto the new tile
		else
			Open = true;
	else
		return;
	return;
}

DisplayTile Door::GetTile()
{
	if (Open)
		return DisplayTile('/', TCODColor::darkerYellow, TCODColor::black);
	else
		return DisplayTile('+', TCODColor::darkerYellow, TCODColor::black);
}