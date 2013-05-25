#include "BasicMapObject.h"
#include "Being.h"
#include "Game.h"
#include "Reference.h"




// Floors
Floor::Floor()
{
	HandleTick = false;
}
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
Wall::Wall()
{
	HandleTick = false;
}

void Wall::Recieve(Message msg, Being * Sender)
{
	if (msg.Type == MOVE)
		InterfaceReference::AddMessage("Ouch! You bump into a wall.");
}

DisplayTile Wall::GetTile()
{
	return DisplayTile('#', TCODColor::white, TCODColor::white);
}


// Doors
Door::Door()
{
	HandleTick = false;
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