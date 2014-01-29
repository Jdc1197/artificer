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

#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "Item.h"

class ItemContainer
{
private:
	Item * I;			// The item
	char Identifier;	// Character identifier
public:
	ItemContainer();
	ItemContainer(Item *, char);

	// Access methods
	char	GetIdentifier();
	Item*	GetItem();
	void	SetIdentifier(char);
	void	SetItem(Item*);
};

class Inventory
{
private:
	unsigned int Capacity;
	std::vector<ItemContainer> Items;
public:
	
	Inventory();
	Inventory(int);
	~Inventory();
	
	bool AddItem(Item *);
	void SetCapacity(int Size);
	int GetCapacity();
	int GetSize();
	
	Item* GetItem(int);
	Item* GetItem(char);

	char GetIdentifier(int);				// Get identifier from the corresponding item
	char GetIdentifier(Item*);
	char GetUnusedIdentifier();				// Gets the first identifier not being used
	char GetLowestIdentifier();				// Gets the lowest identifier being used
	char GetHighestIdentifier();			// Gets the highest identifier being used
	
	void RemoveItem(int, bool);				// Remove Item from inventory
	void RemoveItem(char, bool);
	void RemoveItem(Item*, bool);

	static char GenerateIdentifier(int);	// Converts number to identifier
	static int GenerateNumber(char);		// Converts identifier to number
	
	Item* operator[](int);
	Item* operator[](char);
};

#endif