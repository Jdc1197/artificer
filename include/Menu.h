#ifndef MENU_H
#define MENU_H
#include <libtcod.hpp>

class Game;
class Menu 
{
public:
	virtual void HandleInput(TCOD_key_t) = 0;
	virtual void Draw() = 0;
};

#endif