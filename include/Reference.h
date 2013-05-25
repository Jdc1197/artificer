/*
GameReference.h
Defines the GameReference class
*/

#ifndef GAMEREFERENCE_H
#define GAMEREFERENCE_H
#include "Game.h"
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
	static Being * GetPlayer();

	// Method Mirrors
	static void OpenMenu(Menu*);
	static void CloseMenu();
};

/* class MapReference : public Reference
	A static class which mirrors the game's map methods
*/
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