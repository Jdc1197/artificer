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

#include "Graphics/GraphicsMap.h"

GraphicsMap::GraphicsMap(Map* m)
{
	ToDraw = m;
}

void GraphicsMap::Draw()
{
	ScreenGame->clear();
	// First draw the map objects onto the graphical map
	for (int x = 0; x < MapWidth; x++)
		for (int y = 0; y < MapHeight; y++)
			DrawDisplayTile(x, y, ToDraw->MapCell[x][y]->GetTile(), ScreenGame);

	// Draw the items to the graphical map
	for (unsigned int i = 0; i < (ToDraw->Items.size()); i++)
	{
		// Get the item from the map
		Item* itm = ToDraw->Items[i];
		DrawDisplayTile(itm->GetX(), itm->GetY(), itm->GetTile(), ScreenGame);
	}
	
	// Draw the beings to the graphical map
	for (unsigned int i = 0; i < (ToDraw->Beings.size()); i++)
	{
		// Get the being from the map
		Being* b = ToDraw->Beings[i];
		DrawDisplayTile(b->GetX(), b->GetY(), b->GetTile(), ScreenGame);
	}
}