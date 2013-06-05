#ifndef GRAPHICSINVENTORY_H
#define GRAPHICSINVENTORY_H
#include <libtcod.hpp>
#include "Inventory.h"
#include "Graphics/Graphics.h"


class GraphicsInventory : public Graphics
{
private:
	Inventory * inv;
	const char * title;
public:
	GraphicsInventory(Inventory*, const char*);
	virtual void Draw();
};

#endif