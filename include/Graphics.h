#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <libtcod.hpp>
#include "DisplayTile.h"
#include "Map.h"
#include "Interface.h"

class Graphics
{
private:
	TCODConsole* GameMessages;   // Virtual console for the message window
	TCODConsole* GameMap;		 // Virtual console for the gameplay window
	
	void DrawDisplayTile(int x, int y, DisplayTile Tile);   // Draws a DisplayTile onto the root console
	void DrawDisplayTile(int x, int y, DisplayTile Tile, TCODConsole* Console);   // Draws a DisplayTile onto the specified console
public:
	Graphics();   	// Constructor
	Graphics(bool);	// Constructor + Fullscreen Option
	~Graphics();

	void Render();   // Renders all of the screen
	void RenderPlayingScreen(Map*);   // Renders the playing screen
	void RenderBorders();   // Renders the white borders around the interface
	void RenderMessageWindow(Interface*);   // Renders the message window

	void DisplayScreen();   // Flushes the console and displays the screen
};

#endif