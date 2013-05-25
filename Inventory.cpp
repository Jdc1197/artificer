#include "Inventory.h"

const int DefaultInventoryCapacity = 25;

Inventory::Inventory() { SetCapacity(DefaultInventoryCapacity); }
Inventory::Inventory(int Size) { SetCapacity(Size); }
Inventory::~Inventory()
{
	while(!Items.empty())
	{
		delete Items.back().GetItem();
		Items.pop_back();
	}
}

char Inventory::GetUnusedIdentifier()
{
	if (GetSize() == 0)
		return 'a';
	int IntIdentifier = 0;
	char Identifier = ' ';
	bool Done = false;
	while(!Done)
	{
		if (IntIdentifier >= 52)
		{
			Identifier = char(NULL);
			break;
		}
		Identifier = GenerateIdentifier(IntIdentifier);
		for (unsigned int i = 0; i < Items.size(); i++)
			if (Items[i].GetIdentifier() == Identifier)
				{
					IntIdentifier += 1;
					break;
			}
			else if (i == Items.size()-1)
				Done = true;
	}
	return Identifier;
}

char Inventory::GetLowestIdentifier()
{
	int min = 53;
	for (int i = 0; i < GetSize(); i++)
		if (GenerateNumber(GetIdentifier(i)) <= min)
			min = GenerateNumber(GetIdentifier(i));
	return GenerateIdentifier(min);
}

char Inventory::GetHighestIdentifier()
{
	int max = -1;
	for (int i = 0; i < GetSize(); i++)
		if (GenerateNumber(GetIdentifier(i)) > max)
			max = GenerateNumber(GetIdentifier(i));
	return GenerateIdentifier(max);
}


bool Inventory::AddItem(Item* ToAdd)
{
	if (Items.size() < Capacity)
	{
		// Add the item into the list with an unused identifier
		Items.push_back(ItemContainer(ToAdd, GetUnusedIdentifier()));
		return true;
	}
	return false;
}

char Inventory::GetIdentifier(int selection)
{
	if (Items.size() > (unsigned int)selection)
		return Items[selection].GetIdentifier();
	return char(NULL);
}

char Inventory::GetIdentifier(Item * I)
{
	for (unsigned int i = 0; i < Items.size(); i++)
		if (Items[i].GetItem() == I)
			return Items[i].GetIdentifier();
	return char(NULL);
}
Item* Inventory::GetItem(int selection)
{
	if (Items.size() > (unsigned int)selection)
		return Items[selection].GetItem();
	return nullptr;
}
Item* Inventory::GetItem(char identifier)
{
	for (unsigned int i = 0; i < Items.size(); i++)
		if (Items[i].GetIdentifier() == identifier)
			return Items[i].GetItem();
	return nullptr;
}
Item* Inventory::operator[](int selection)
{
	return GetItem(selection);
}
Item* Inventory::operator[](char selection)
{
	return GetItem(selection);
}

/* Inventory::RemoveItem(int selection, bool destroy)
Function:
	Removes an item from the inventory.
Args:
	int selection
		The selected item.
	bool destroy
		Whether or not to deallocate the item
*/
void Inventory::RemoveItem(int selection, bool destroy)
{
	if (selection > 0 && selection < GetSize())
		if (Items[selection].GetItem() != nullptr)
		{
			if (destroy)
				delete Items[selection].GetItem();
			Items.erase(Items.begin()+selection-1);		// remove the item from the list
		}
}
/* Inventory::RemoveItem(char selection, bool destroy)
Function:
	Removes an item from the inventory.
Args:
	char selection
		The selected item.
	bool destroy
		Whether or not to deallocate the item
*/
void Inventory::RemoveItem(char selection, bool destroy)
{
	for (unsigned int i = 0; i < Items.size(); i++)
		if (Items[i].GetIdentifier() == selection)
		{
			if (destroy)
				delete Items[i].GetItem();
			Items.erase(Items.begin()+selection-1);
		}
}
/* Inventory::RemoveItem(Item* selection, bool destroy)
Function:
	Removes an item from the inventory.
Args:
	Item * selection
		A pointer to the selected item.
	bool destroy
		Whether or not to deallocate the item
*/
void Inventory::RemoveItem(Item* selection, bool destroy)
{
	for (unsigned int i = 0; i < Items.size(); i++)
		if (Items[i].GetItem() == selection)
		{
			if (destroy)
				delete Items[i].GetItem();
			Items.erase(Items.begin()+i);
		}
}

char Inventory::GenerateIdentifier(int i)
{
	// Lowercase
	if (i >= 0 && i <= 25)
		return char(97+i);
	// Uppercase
	if (i >=26 && i <= 51)
		return char(i + 65 - 26); //39 is the starting uppercase ASCII character (65) minus the number of letters (26)
	return ' ';
}

int Inventory::GenerateNumber(char ID)
{
	// lowercase
	if (ID > 96 && ID < 123)
		return (ID - 97);
	// uppercase
	if (ID > 64 && ID < 91)
		return (ID - 65 + 26);
	return -1;
}

void Inventory::SetCapacity(int Capacity) { this->Capacity = Capacity; }
int  Inventory::GetCapacity() { return Capacity; }
int  Inventory::GetSize() { return Items.size(); }