#include "Object.h"
#include "DisplayTile.h"
#include "Being.h"
#include "SpawnIDs.h"
#include "Game.h"
#include <assert.h>


Object::Object()
{
	Opaque	=	true;
	Solid	=	true;
}

DisplayTile Object::GetTile()
{
	return DisplayTile('`', TCODColor::black, TCODColor::blue) ;
}
void Object::Recieve(Message msg, Being * Sender)
{
	return;
}
ObjectID Object::GetID()
{
	return ObjectAbstract;
}

void Object::Move(int x, int y)
{
	this->x=x;
	this->y=y;
}
void Object::RelativeMove(int x, int y)
{
	this->x+=x;
	this->y+=y;
}

int Object::GetX() {return x;}
int Object::GetY() {return y;}