#ifndef GRAPHICSINTERFACE_H
#define GRAPHICSINTERFACE_H
#include "Graphics/Graphics.h"
#include "Interface.h"

class GraphicsInterface : public Graphics
{
private:
	Interface* ToDraw;
public:
	GraphicsInterface(Interface*);
	virtual void Draw();
};

#endif