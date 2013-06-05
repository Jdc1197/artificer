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

/// A Map container.
class Map
{
public:
	/// Constructor
	Map();
	/// Destructor
	~Map();
	
	///Array of MapObjects which make up the map
	MapObject* MapCell[MapWidth][MapHeight];
	///List of MapObjects which keep track of time (i.e. need to be ticked)
	vector<MapObject*> TickMapObjects;	
	///List of Items on the map which keep track of time
	vector<Item*> TickItems;
	///List of Items on the map
	vector<Item*> Items;
	///List of Beings on the map
	vector<Being*> Beings;
	
	
	/// Sets a MapObject
	void SetTile(MapObject*, int, int);		
	/// Adds a Being to the Map
	void AddBeing(Being*, int, int);
	/// Adds an Item to the Map
	void AddItem(Item *, int, int);			

	/// Removes an Item from the Map
	void RemoveItem(Item*, bool);
	/// Removes a Being from the Map
	void RemoveBeing(Being*, bool);

	/// Checks if an Item is on the specified tile
	bool IsItemOnTile(int x, int y);
	/// Checks if a Being is on the specified tile
	bool IsBeingOnTile(int x, int y);		
	
	/// Returns a list of Items on a tile
	vector<Item*> GetItemsOnTile(int x, int y);		
};

#endif