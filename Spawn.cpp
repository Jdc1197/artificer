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