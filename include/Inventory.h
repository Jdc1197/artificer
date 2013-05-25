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