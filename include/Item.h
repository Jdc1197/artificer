#ifndef ITEM_H
#define ITEM_H
#include "Object.h"

class Item : public Object
{
public:
	Item();
	virtual const char * GetFullName();
	virtual const char * GetShortName();
};


#endif