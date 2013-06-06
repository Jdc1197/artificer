#include <assert.h>
#include "Map.h"
#include "Spawn.h"


Map::Map() {}
Map::~Map()
{
	// Deallocate MapCell array
	for (int x = 0; x < MapWidth; x++)
		for (int y = 0; y < MapHeight; y++)
			delete MapCell[x][y];

	// Deallocate TickMapObjects vector
	while(!TickMapObjects.empty())
	{
		delete TickMapObjects.back();
		TickMapObjects.pop_back();
	}
	
	// Deallocate Items vector
	while(!Items.empty())
	{
		delete Items.back();
		Items.pop_back();
	}

	while(!TickItems.empty())
	{
		delete Items.back();
		Items.pop_back();
	}
	
	// Deallocate Beings vector
	while(!Beings.empty())
	{
		delete Beings.back();
		Beings.pop_back();
	}
}

void Map::SetTile(MapObject * ToSpawn, int x, int y)
{
	assert(x > -1 && x < MapWidth && y > -1 && y < MapHeight);
	MapCell[x][y] = ToSpawn;
	ToSpawn->Move(x,y);
}
void Map::AddBeing(Being *ToSpawn, int x, int y)
{
	ToSpawn->Move(x,y);
	Beings.push_back(ToSpawn);
}
void Map::AddItem(Item * ToSpawn, int x, int y)
{
	ToSpawn->Move(x,y);
	Items.push_back(ToSpawn);
}

void Map::RemoveItem(Item* ItemToRemove, bool DestroyItem = false)
{
	for (unsigned int i = 0; i < Items.size(); i++)
		if (Items[i] == ItemToRemove)
		{
			Items.erase(Items.begin()+i);
			if (DestroyItem)
			{ delete ItemToRemove; ItemToRemove = nullptr; }
		}
}
void Map::RemoveBeing(Being * BeingToRemove, bool DestroyBeing = false)
{
	for (unsigned int i = 0; i < Beings.size(); i++)
		if (Beings[i] == BeingToRemove)
		{
			Beings.erase(Beings.begin()+(i-1));
			if (DestroyBeing)
			{ delete BeingToRemove; BeingToRemove = nullptr; }
		}
}

bool Map::IsItemOnTile(int x, int y)
{
	for (unsigned int i = 0; i < Items.size(); i++)
		if (Items[i]->GetX() == x && Items[i]->GetY() == y)
			return true;
	return false;
}
bool Map::IsBeingOnTile(int x, int y)
{
	for (unsigned int i = 0; i < Beings.size(); i++)
		if (Beings[i]->GetX() == x && Beings[i]->GetY() == y)
			return true;
	return false;
}

vector<Item*> Map::GetItemsOnTile(int x, int y)
{
	vector<Item*> list;
	for (unsigned int i = 0; i < Items.size(); i++)		// Cycle through all items
		if (Items[i]->GetX() == x && Items[i]->GetY() == y)	// If they are on the specified tile, add them to I
			list.push_back(Items[i]);
	return list;
}
