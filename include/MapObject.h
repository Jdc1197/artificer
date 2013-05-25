#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "Object.h"

class MapObject : public Object
{
public:
	MapObject();
	bool HandleTick;
};

#endif

