#ifndef BASICITEMS_H
#define BASICITEMS_H
#include "Item.h"
#include "StandardItemFunctions.h"

class Weapon : public StandardItemFunctions
{
public:
	Weapon();
	Weapon(int);
	int Attack;
	
	// Inherited Methods
	virtual DisplayTile GetTile();
	virtual void Recieve(Message, Being *);
	virtual ObjectID GetID();
	virtual const char * GetFullName();
	virtual const char * GetShortName();
};

#endif