#ifndef GRAPHICSDROP_H
#define GRAPHICSDROP_H
#include "Graphics/Graphics.h"
#include "Inventory.h"

class GraphicsDrop : public Graphics
{
private:
	Inventory * Inv;
public:
	GraphicsDrop(Inventory*);
	virtual void Draw();
};

#endif