#ifndef GAME_H
#define GAME_H
#include "Being.h"
#include "Map.h"
#include "Graphics/Graphics.h"
#include "Spawn.h"
#include "Interface.h"
#include "Menu.h"

class Game
{
private:
	bool Debug;
	bool MenuOpen;

	void HandleInput(TCOD_key_t);
	Graphics* MapRenderer;
	Graphics* BorderRenderer;
	Graphics* InterfaceRenderer;
public:
	Map* CurrentMap;
	Interface GameInterface;
	Being * Player;
	Menu * CurrentMenu;

	Game();
	~Game();

	void Run();

	void OpenMenu(Menu*);
	void CloseMenu();
	void DrawSubconsoles();
};

#endif