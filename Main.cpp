#include <Windows.h>
#include <libtcod.hpp>
#include "Game.h"
#include "Reference.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	TCODConsole::setCustomFont("terminal8x12_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW );
	TCODConsole::initRoot(80, 50, "Scourge of Westnor", false);

	Game CurrentInstance;
	Reference::SetGameInstance(&CurrentInstance);
	CurrentInstance.Run();
	return 4;
}