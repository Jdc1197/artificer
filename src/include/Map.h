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

#ifndef MAP_H
#define MAP_H
#include "Being.h"
#include "Object.h"
#include "MapObject.h"
#include "Item.h"
#include <vector>
using namespace std;

const int MapWidth = 78;
const int MapHeight = 38;

/// A Map container which store binary information rather than actual MapObjects
struct BinaryMap
{
	bool map[MapWidth][MapHeight];
};

/// A Map container.
class Map : public TimableObject
{
private:
	///Array of MapObjects which make up the map
	MapObject* MapCell[MapWidth][MapHeight];
public:
	/// Constructor
	Map();
	/// Destructor
	~Map();
	
	/// List of MapObjects which keep track of time (i.e. need to be ticked)
	vector<MapObject*> TickMapObjects;	
	/// List of Items on the map which keep track of time
	vector<Item*> TickItems;
	/// List of Items on the map
	vector<Item*> Items;
	/// List of Beings on the map
	vector<Being*> Beings;
	
	
	// Access Methods //
	/// Returns a map cell
	MapObject* GetMapCell(int,int);
	/// Sets a MapObject
	void SetMapCell(MapObject*, int, int);	
	
	// Inherited Methods //
	virtual void ElapseTime(float);
	
	// Methods //
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

void BuildTCODMap(Map*, TCODMap*);
/// Checks if a coordinate is out of bounds
bool IsOOB(int x, int y);

#endif
