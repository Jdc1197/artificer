#include "Spawn.h"
#include "BasicItems.h"
#include "BasicMapObject.h"
#include "Races.h"


MapObject * SpawnMap(ObjectID Base) { return SpawnMap(Base, 0); }
MapObject * SpawnMap(ObjectID Base, int Sub)
{
	switch (Base)
	{
	case MapFloor:
		return new Floor;
		break;
	case MapWall:
		return new Wall;
		break;
	case MapDoor:
		return new Door;
		break;
	default:
		return nullptr;
	}
}

Being * SpawnBeing(ObjectID Base) { return SpawnBeing(Base, 0); }
Being * SpawnBeing(ObjectID Base, int Sub)
{
	switch (Base)
	{
	case BeingHuman:
		return new Human;
		break;
	default:
		return nullptr;
	}
}

Item * SpawnItem(ObjectID Base) { return SpawnItem(Base, 0); }
Item * SpawnItem(ObjectID Base, int Sub)
{
	switch(Base)
	{
	case ItemWeapon:
		return new Weapon;
		break;
	default:
		return nullptr;
	}
}