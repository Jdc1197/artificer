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

#include "Graphics/Graphics.h"

TCODConsole* Graphics::ScreenGame;
TCODConsole* Graphics::ScreenMessages;
TCODConsole* Graphics::RootConsole;

Graphics::Graphics() {}

void Graphics::Init()
{
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