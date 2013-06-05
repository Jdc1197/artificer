#include "Graphics/GraphicsBorders.h"

GraphicsBorders::GraphicsBorders() {}
void GraphicsBorders::Draw()
{
	// Around the message box
	for (int x = 0; x < 80; x++) // Top //
	{
		DrawDisplayTile(x, 0, DisplayTile('#', TCODColor::white, TCODColor::white), RootConsole);
	}

	for (int y = 0; y < 10; y++) // Sides //
	{
		DrawDisplayTile(0, y, DisplayTile('#', TCODColor::white, TCODColor::white), RootConsole);
		DrawDisplayTile(80-1, y, DisplayTile('#', TCODColor::white, TCODColor::white), RootConsole);
	}
}