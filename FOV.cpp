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
#include "FOV.h"


BinaryMap FOV::GetFOVMap(int x, int y, int radius, Map* m)
{
	// Build the map
	TCODMap* VisionMap = new TCODMap(MapWidth, MapHeight);
	BuildTCODMap(m, VisionMap);
	// Compute
	VisionMap->computeFov(x, y, radius);
	BinaryMap binmap;
	for (x = 0; x < MapWidth; x++)
		for (y = 0; y < MapHeight; y++)
			binmap.map[x][y] = VisionMap->isInFov(x,y);
	delete VisionMap;
	return binmap;
}