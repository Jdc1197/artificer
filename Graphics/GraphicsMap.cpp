#include "Graphics/GraphicsMap.h"

GraphicsMap::GraphicsMap(Map* m)
{
	ToDraw = m;
}

void GraphicsMap::Draw()
{
	ScreenGame->clear();
	// First draw the map objects onto the graphical map
	for (int x = 0; x < MapWidth; x++)
		for (int y = 0; y < MapHeight; y++)
			DrawDisplayTile(x, y, ToDraw->MapCell[x][y]->GetTile(), ScreenGame);

	// Draw the items to the graphical map
	for (unsigned int i = 0; i < (ToDraw->Items.size()); i++)
	{
		// Get the item from the map
		Item* itm = ToDraw->Items[i];
		DrawDisplayTile(itm->GetX(), itm->GetY(), itm->GetTile(), ScreenGame);
	}
	
	// Draw the beings to the graphical map
	for (unsigned int i = 0; i < (ToDraw->Beings.size()); i++)
	{
		// Get the being from the map
		Being* b = ToDraw->Beings[i];
		DrawDisplayTile(b->GetX(), b->GetY(), b->GetTile(), ScreenGame);
	}
}