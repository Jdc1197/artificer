#ifndef SPAWN_H
#define SPAWN_H
#include "SpawnIDs.h"
#include "Being.h"
#include "MapObject.h"
#include "Item.h"


MapObject * SpawnMap(ObjectID);	
MapObject * SpawnMap(ObjectID, int);

Item * SpawnItem(ObjectID);
Item * SpawnItem(ObjectID, int);

Being * SpawnBeing(ObjectID);
Being * SpawnBeing(ObjectID, int);

#endif