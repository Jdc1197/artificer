#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <libtcod.hpp>
#include "DisplayTile.h"

enum class ScreenFlag
{
	Game = 1,
	Messages,
	Root
};


class Graphics
{
protected:
	// Consoles //
	static TCODConsole* ScreenGame;			// Virtual console for the message window
	static TCODConsole* ScreenMessages;		// Virtual console for the gameplay window
	static TCODConsole* RootConsole;		// Virtual root console
	
	// Methods //
	void DrawDisplayTile(int, int, DisplayTile, TCODConsole*);
	void DrawDisplayTile(int, int, DisplayTile);
	TCODConsole* GetScreen(ScreenFlag);
public:
	Graphics();
	
	virtual void Draw() = 0;
	
	static void BlitSubconsoles();
	static void FlushRoot();

	static void Init();
	static void Destroy();
};

#endif