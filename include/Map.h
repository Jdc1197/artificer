#ifndef MAP_H
#define MAP_H
#include "Being.h"
#include "Object.h"
#include "MapObject.h"
#include "Item.h"
#include <vector>
using namespace std;

const int MapWidth = 80;
const int MapHeight = 40;


class Map
{
public:
	Map();
	~Map();
	
	//The map
	MapObject* MapCell[MapWidth][MapHeight];
	
	//List of Map Objects which keep track of time
	vector<MapObject*> TickMapObjects;	
	
	//List of Items on the map which keep track of time
	vector<Item*> TickItems;
	
	//List of Items on the map
	vector<Item*> Items;

	//List of Beings on the map
	vector<Being*> Beings;
	
	

	void SetTile(MapObject*, int, int);
	void AddBeing(Being*, int, int);
	void AddItem(Item *, int, int);

	void RemoveItem(Item*, bool);
	void RemoveBeing(Being*, bool);

	bool IsItemOnTile(int x, int y);
	bool IsBeingOnTile(int x, int y);

	vector<Item*> GetItemsOnTile(int x, int y);

	void Tick();
};

#endif