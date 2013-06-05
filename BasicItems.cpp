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