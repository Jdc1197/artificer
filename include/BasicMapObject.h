#ifndef BASICMAPOBJECT_H
#define BASICMAPOBJECT_H
#include <string>
#include "MapObject.h"

class Floor : public MapObject
{
private:
	std::string MakeItemList();		//Constructs a string diplaying all of the items on the tile
public:
	Floor();
	virtual DisplayTile GetTile();
	virtual void Recieve(Message, Being *);
};


class Wall : public MapObject
{
public:
	Wall();
	virtual DisplayTile GetTile();
	virtual void Recieve(Message, Being *);
};

class Door : public MapObject
{
private:
	bool Open;
public:
	Door();
	virtual DisplayTile GetTile();
	virtual void Recieve(Message, Being *);
};

#endif