#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include "Map.h"

namespace MapGenerator
{
	/// Abstract MapGenerator class
	class MapGenerator
	{
	public:
		/// Generates a Map
		virtual Map* GenerateMap() = 0;
	};
}

#endif