#include "FOV.h"


BinaryMap FOV::GetFOVMap(int x, int y, int radius, Map* m)
{
	// Build the map
	TCODMap* VisionMap = new TCODMap(MapWidth, MapHeight);
	BuildTCODMap(m, VisionMap);
	// Compute
	VisionMap->computeFov(x,y);
	BinaryMap binmap;
	for (x = 0; x < MapWidth; x++)
		for (y = 0; y < MapHeight; y++)
			binmap.map[x][y] = VisionMap->isInFov(x,y);
	return binmap;
}