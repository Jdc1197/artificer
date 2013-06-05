#ifndef GRAPHICSMAP_H
#define GRAPHICSMAP_H
#include "Graphics/Graphics.h"
#include "Map.h"

class GraphicsMap : public Graphics
{
private:
	Map * ToDraw;
public:
	GraphicsMap(Map*);
	virtual void Draw();
};

#endif