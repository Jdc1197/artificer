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

#include "Graphics/GraphicsBorders.h"

GraphicsBorders::GraphicsBorders() {}
void GraphicsBorders::Draw()
{
	// Around the message box
	for (int x = 0; x < 80; x++) // Top //
	{
		DrawDisplayTile(x, 0, DisplayTile('#', TCODColor::white, TCODColor::white), RootConsole);
	}

	for (int y = 0; y < 10; y++) // Sides //
	{
		DrawDisplayTile(0, y, DisplayTile('#', TCODColor::white, TCODColor::white), RootConsole);
		DrawDisplayTile(80-1, y, DisplayTile('#', TCODColor::white, TCODColor::white), RootConsole);
	}
}