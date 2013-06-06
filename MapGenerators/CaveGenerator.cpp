#include "MapGenerators/CaveGenerator.h"
#include "Spawn.h"
#include "Reference.h"
#include <libtcod.hpp>


namespace MapGenerator
{
	
	void TranscribeBinaryMap(Map* map, BinaryMap* binmap, ObjectID true_type, ObjectID false_type)
	{
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
			if (binmap->map[x][y] == true)
				map->SetTile(SpawnMap(true_type), x, y);
			else
				map->SetTile(SpawnMap(false_type), x, y);
	}
	
	void RoundBinaryMap(BinaryMap* binmap, int iterations)
	{
		for (int i = 0; i < iterations; i++)
		{
			BinaryMap binmaptmp;
			for (int x = 0; x < MapWidth; x++)
				for (int y = 0; y < MapHeight; y++)
				{
					int adjacentwallcount = 0;
					for (int xi = -1; xi < 2; xi++)
						for (int yi = -1; yi < 2; yi++)
						{
							if (binmap->map[x+xi][y+yi] == true)
								adjacentwallcount++;
						}
					if (adjacentwallcount >= 5)
						binmaptmp.map[x][y] = true;
					else
						binmaptmp.map[x][y] = false;
				}
			*binmap = binmaptmp;
		}
	}
	
	bool CaveGenerator::RectIntersection(Rectangle r1, Rectangle r2)
	{
		return (r1.x < r2.x+r2.width && r1.x + r1.width > r2.x 
				&& r1.x < r2.y + r2.height && r1.y + r1.height > r2.y);
	}

	Rectangle CaveGenerator::RandomRect()
	{
		Rectangle rect;
		rect.x = TCODRandom::getInstance()->getInt(0, MapWidth-1);
		rect.y = TCODRandom::getInstance()->getInt(0, MapHeight-1);
		rect.width = TCODRandom::getInstance()->getInt(1, 15);
		rect.height = TCODRandom::getInstance()->getInt(1, 15);
		if (rect.x + rect.width >= MapWidth || rect.y + rect.height >= MapHeight)
			return RandomRect();
		else
			return rect;
	}

	void CaveGenerator::FillRect(BinaryMap* binmap, Rectangle r, bool val)
	{
		for (int x = 0; x < r.width; x++)
			for (int y = 0; y < r.height; y++)
				binmap->map[x+r.x][y+r.y] = val;
	}

	CaveGenerator::CaveGenerator(Being* p)
	{
		player = p;
	}

	Map* CaveGenerator::GenerateMap()
	{
		// Fill the whole screen with floor tiles
		BinaryMap binmap;
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
				binmap.map[x][y] = true;
		for (int x = 0; x < MapWidth; x++)
			for (int y = 0; y < MapHeight; y++)
				binmap.map[x][y] = TCODRandom::getInstance()->getInt(0,100) > 50 ? true : false;
		RoundBinaryMap(&binmap, 100);
		Map* map = new Map;
		TranscribeBinaryMap(map, &binmap, MapWall, MapFloor);		
		map->AddBeing(player, 10, 10);
		return map;
	}
}