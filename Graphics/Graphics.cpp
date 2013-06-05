#include "Graphics/Graphics.h"
#include <windows.h>

TCODConsole* Graphics::ScreenGame;
TCODConsole* Graphics::ScreenMessages;
TCODConsole* Graphics::RootConsole;

Graphics::Graphics() {}

void Graphics::Init()
{
	TCODConsole::setCustomFont("terminal8x12_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW );
	TCODConsole::initRoot(80, 50, "Scourge of Westnor", false);
	ScreenGame = new TCODConsole(80, 40);
	ScreenMessages = new TCODConsole(78, 10);
	RootConsole = new TCODConsole(80, 50);
}

void Graphics::Destroy()
{
	delete ScreenGame;
	delete ScreenMessages;
	delete RootConsole;
}

void Graphics::DrawDisplayTile(int x, int y, DisplayTile tile, TCODConsole* console)
{
	console->putCharEx(x, y, tile.GetTile(), tile.GetForegroundColor(), tile.GetBackgroundColor());
}

void Graphics::DrawDisplayTile(int x, int y, DisplayTile tile)
{
	DrawDisplayTile(x, y, tile, RootConsole);
}

TCODConsole* Graphics::GetScreen(ScreenFlag ID)
{
	if (ID == ScreenFlag::Game)
		return ScreenGame;
	else if (ID == ScreenFlag::Messages)
		return ScreenMessages;
	else
		return RootConsole;
	
}

void Graphics::BlitSubconsoles()
{
	TCODConsole::blit(ScreenMessages, 0, 0, ScreenMessages->getWidth(), ScreenMessages->getHeight(), RootConsole, 1, 1);
	TCODConsole::blit(ScreenGame, 0, 0, ScreenGame->getWidth(), ScreenGame->getHeight(), RootConsole, 0, 10);
}

void Graphics::FlushRoot()
{

	TCODConsole::blit(RootConsole, 0, 0, RootConsole->getWidth(), RootConsole->getHeight(), TCODConsole::root, 0, 0);
	TCODConsole::root->flush();
}