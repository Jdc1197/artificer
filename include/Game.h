#ifndef GAME_H
#define GAME_H
#include "Being.h"
#include "Map.h"
#include "Graphics.h"
#include "Spawn.h"
#include "Interface.h"
#include "Menu.h"

class Game
{
private:
	bool Debug;
	bool MenuOpen;

	void HandleInput(TCOD_key_t);
public:
	Map CurrentMap;
	Interface GameInterface;
	Graphics GraphicsEngine;
	
	Being * Player;
	Menu * CurrentMenu;

	Game();
	~Game();

	void Run();

	void OpenMenu(Menu*);
	void CloseMenu();
};

#endif