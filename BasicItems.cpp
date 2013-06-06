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

#include <sstream>
#include <string>
#include "BasicItems.h"
using namespace std;
Weapon::Weapon()
{
	Attack = 1;
}
Weapon::Weapon(int Attack)
{
	this->Attack = Attack; 
}

void Weapon::Recieve(Message msg, Being * Sender)
{
	if (msg.Type == DROP)
		this->GetPlaced(Sender);
	else if (msg.Type == PICKUP)
		this->GetPickedUp(Sender);
	return;
}
DisplayTile Weapon::GetTile()
{
	return DisplayTile('\\', TCODColor::silver, TCODColor::black);
}
ObjectID Weapon::GetID()
{
	return ItemWeapon;
}

const char * Weapon::GetFullName()
{
	ostringstream str;
	str << "The Weapon [" << Attack << "]";
	char * cstr = new char [str.str().length()+1];
	strcpy (cstr, str.str().c_str());
	return cstr;
}

const char * Weapon::GetShortName()
{
	return "a %[255,90,8]weapon";
}