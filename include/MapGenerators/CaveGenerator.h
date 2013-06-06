#ifndef MAPGENERATORRANDOM_H
#define MAPGENERATORRANDOM_H
#include "MapGenerators/MapGenerator.h"

namespace MapGenerator
{
	struct Rectangle
	{
		int x;
		int y;
		int width;
		int height;
	};
	
	struct BinaryMap
	{
		bool map[MapWidth][MapHeight];
	};
	
	void TranscribeBinaryMap(Map*, BinaryMap, ObjectID, ObjectID);
	void RoundBinaryMap(BinaryMap*, int);
	
	class CaveGenerator : public MapGenerator
	{
	private:
		bool RectIntersection(Rectangle, Rectangle);
		Rectangle RandomRect();
		void FillRect(BinaryMap*, Rectangle, bool);
		Being* player;
	public:
		CaveGenerator(Being*);
		virtual Map* GenerateMap();
	};
}

#endif