#ifndef MENU_H
#define MENU_H
#include <libtcod.hpp>

class Game;
class Menu 
{
public:
	// Handle Input
	virtual void HandleInput(TCOD_key_t) = 0;
	// Draw the Menu
	virtual void Draw() = 0;
	// Function called after the menu is opened
	virtual void Init();
};

#endif