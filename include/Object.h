#ifndef OBJECT_H
#define OBJECT_H
#include "Message.h"
#include "DisplayTile.h"
#include "SpawnIDs.h"

// Forward Declarations
class Being;

class Object
{
protected:
	bool Opaque, Solid;
	short x, y;
public:
	Object();

	// Virtual Methods
	virtual DisplayTile GetTile();
	virtual void Recieve(Message, Being *);
	virtual ObjectID GetID();
	
	// Movement //
	void RelativeMove(int x, int y);
	void Move(int x, int y);

	// Get //
	int GetX();
	int GetY();
};
#endif