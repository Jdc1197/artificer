#ifndef SPAWNIDS_H
#define SPAWNIDS_H

enum ObjectID
{
	ObjectAbstract = 0,			// ID for abstract objects
	
	MapFirst,
	MapFloor, MapWall, MapDoor,
	MapLast,

	BeingFirst,
	BeingHuman,
	BeingLast,

	ItemFirst,
	ItemWeapon,
	ItemLast
};

#endif