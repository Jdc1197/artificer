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

#ifndef GAME_H
#define GAME_H
#include "Time.h"
#include "Being.h"
#include "Map.h"
#include "Graphics/Graphics.h"
#include "Spawn.h"
#include "Interface.h"
#include "Menu.h"

/// A running instance of the game.
class Game
{
private:
	bool Debug;
	bool MenuOpen;

	void HandleInput(TCOD_key_t);
	
	/// Renderer for the map
	Graphics* MapRenderer;
	/// Renderer for the screen borders
	Graphics* BorderRenderer;
	/// Renderer for the interface
	Graphics* InterfaceRenderer;
	
	/// The engine for managing time
	TimeManager TimeEngine;
public:
	Map* CurrentMap;
	Interface GameInterface;
	Being* Player;
	Menu* CurrentMenu;
	

	Game();
	~Game();

	Being* GetPlayer();
	
	void Run();
	// Menu Methods
	void OpenMenu(Menu*);
	void CloseMenu();
	
	// Graphics Methods
	void DrawSubconsoles();
	
	// Time Methods
	void AddEvent(float, Message, Being*, Object*);
};

#endif