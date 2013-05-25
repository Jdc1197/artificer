#ifndef BEING_H
#define BEING_H
#include "Object.h"
#include "Message.h"
#include "Inventory.h"

class Being : public Object
{
public:
	Being();
	void Send(Object *, Message);
	Inventory Inv;
};

#endif