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

/*
GameReference.h
Defines the Reference, GameReference, MapReference, and InterfaceReference classes
*/

#ifndef GAMEREFERENCE_H
#define GAMEREFERENCE_H
#include "Game.h"

#include "Graphics/GraphicsMap.h"
#include "Graphics/GraphicsBorders.h"
#include "Graphics/GraphicsInterface.h"
using namespace std;

class Reference
{
protected:
	static Game * GameInstance;
public:
	static bool SetGameInstance(Game*);
};

/* class GameReference : public Reference
	A static class which holds a pointer to the current game instance and mirrors it's public methods.
*/
class GameReference : public Reference
{
public:
	static void SetGameInstance(Game *);
	
	// Access Methods
	static Being* GetPlayer();
	static Map* GetMap();
	static Interface* GetInterface();

	// Method Mirrors
	static void OpenMenu(Menu*);
	static void CloseMenu();
	static void DrawSubconsoles();
	static void AddEvent(float, Message, Being*, Object*);
};

// class MapReference : public Reference
// A static class which mirrors the game's map methods
class MapReference : public Reference
{
public:
	static void SetGameInstance(Game *);

	// Method Mirrors
	static bool IsItemOnTile(int x, int y);
	static bool IsBeingOnTile(int x, int y);
	static void RemoveBeing(Being *, bool);
	static void RemoveItem(Item *, bool);
	static void AddBeing(Being *, int, int);
	static void AddItem(Item *, int, int);

	static vector<Item*> GetItemsOnTile(int x, int y);
};

class InterfaceReference : public Reference
{
public:
	static void AddMessage(string);
	static void AddMessage(ostringstream*);
	static void AddMessage(const char *);
};

typedef GameReference GameRef;
typedef GameReference GR;
typedef MapReference MapRef;
typedef MapReference MR;
typedef InterfaceReference InterfaceRef;
typedef InterfaceReference IR;

#endif