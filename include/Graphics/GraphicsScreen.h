#ifndef GRAPHICSSCREEN_H
#define GRAPHICSSCREEN_H
#include "Graphics/GraphicsMap.h"
#include "Graphics/GraphicsInterface.h"
#include "Graphics/GraphicsBorders.h"

class GraphicsScreen
{
private:
	static GraphicsMap MapRenderer;
	static GraphicsInterface InterfaceRenderer;
	static GraphicsBorders BordersRenderer;
public:
	void RenderScreen();
	void BlitScreen();
	void RenderAndBlitScreen();
};

#endif