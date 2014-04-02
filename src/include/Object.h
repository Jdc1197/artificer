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

#ifndef OBJECT_H
#define OBJECT_H

#include "Time.h"
#include "Message.h"
#include "DisplayTile.h"
#include "SpawnIDs.h"


// Forward Declarations
class Being;

/// Abstract class which parents all Being, Item, and MapObject classes
class Object : public TimableObject
{
protected:
	short x, y;
public:
	Object();

	// Virtual Methods //
	virtual DisplayTile GetTile();
	virtual void Receive(Message, Being *);
	virtual ObjectID GetID();
	
	// Movement //
	void RelativeMove(int x, int y);
	void Move(int x, int y);

	// Get //
	int GetX();
	int GetY();
};
#endif
