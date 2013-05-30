#include "Graphics.h"
#include "Graphics/GraphicsColoredString.h"
#include "BasicMapObject.h"


// Constructors //
Graphics::Graphics()
{
	TCODConsole::setCustomFont("terminal8x12_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW);
	TCODConsole::initRoot(MapWidth, MapHeight+10, "Scourge of Westnor", false);
	GameMessages = new TCODConsole(MapWidth-2, 9);
	GameMap = new TCODConsole(MapWidth, MapHeight);
}

Graphics::Graphics(bool Fullscreen)
{
	TCODConsole::setCustomFont("terminal8x12_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW);
	TCODConsole::initRoot(MapWidth, MapHeight+10, "Scourge of Westnor", Fullscreen);
	GameMessages = new TCODConsole(MapWidth-2, 9);
	GameMap = new TCODConsole(MapWidth, MapHeight);
}

Graphics::~Graphics()
{
	delete GameMessages;
	delete GameMap;
}



// Drawing Functions //

// Draws a DisplayTile onto the root console
void Graphics::DrawDisplayTile(int x, int y, DisplayTile Tile)
{
	DrawDisplayTile(x, y, Tile, TCODConsole::root);
}
// Draws a DisplayTile onto the specified console
void Graphics::DrawDisplayTile(int x, int y, DisplayTile Tile, TCODConsole* Console)
{
	Console->putCharEx(x, y, Tile.GetTile(), Tile.GetForegroundColor(), Tile.GetBackgroundColor());
}


// Render Fuctions //

// Renders the playing area of the screen
void Graphics::RenderPlayingScreen(Map* ToDraw)
{
	// First draw the map objects onto the graphical map
	for (int x = 0; x < MapWidth; x++)
		for (int y = 0; y < MapHeight; y++)
			DrawDisplayTile(x, y, ToDraw->MapCell[x][y]->GetTile(), GameMap);

	// Draw the items to the graphical map
	for (unsigned int i = 0; i < (ToDraw->Items.size()); i++)
	{
		// Get the item from the map
		Item* itm = ToDraw->Items[i];
		DrawDisplayTile(itm->GetX(), itm->GetY(), itm->GetTile(), GameMap);
	}
	
	// Draw the beings to the graphical map
	for (unsigned int i = 0; i < (ToDraw->Beings.size()); i++)
	{
		// Get the being from the map
		Being* b = ToDraw->Beings[i];
		DrawDisplayTile(b->GetX(), b->GetY(), b->GetTile(), GameMap);
	}
	// Draw the graphical map onto the console
	TCODConsole::root->blit(GameMap, 0, 0, GameMap->getWidth(), GameMap->getHeight(), TCODConsole::root, 0, 10);
}

// Renders the white borders around the interface //
void Graphics::RenderBorders()
{
	// Around the message box
	for (int x = 0; x < MapWidth; x++) // Top //
	{
		DrawDisplayTile(x, 0, DisplayTile('#', TCODColor::white, TCODColor::white));
	}

	for (int y = 0; y < 10; y++) // Sides //
	{
		DrawDisplayTile(0, y, DisplayTile('#', TCODColor::white, TCODColor::white));
		DrawDisplayTile(MapWidth-1, y, DisplayTile('#', TCODColor::white, TCODColor::white));
	}
}

// Renders the messages onto the message window
void Graphics::RenderMessageWindow(Interface * UI)
{
	GameMessages->clear();
	for (int i = 0; i < 9; i++)
	{
		GraphicsColoredString G(UI->GetMessage(i));
		G.Draw(0, 8-i, GameMessages);
		//GameMessages->printLeftRect(0, 8-i, GameMessages->getWidth(), GameMessages->getHeight(),TCOD_BKGND_NONE, UI->GetMessage(i));
	}
	TCODConsole::root->blit(GameMessages, 0, 0, GameMessages->getWidth(), GameMessages->getHeight(), TCODConsole::root, 1, 1);
}

// Shows the root console on the screen
void Graphics::DisplayScreen()
{
	//GraphicsColoredString G("%[255,0,0]#%[255,255,0]#%[0,255,0]#%[0,255,255]#%[0,0,255]#");
	//G.Draw(1,1);
	// Show the console
	TCODConsole::root->flush();
}