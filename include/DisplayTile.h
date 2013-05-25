#ifndef DISPTILE_H
#define DISPTILE_H
#include <libtcod.hpp>


class DisplayTile
{
private:
	char Tile;     // The tile character
	bool AlphaBG, AlphaFG;     // Alpha flags for background and foreground - true = transparent
	TCODColor ColorBG, ColorFG;    // The background and foreground colors
public:
	DisplayTile();
	DisplayTile(char, TCODColor, TCODColor);
	DisplayTile(char, TCODColor, TCODColor, bool);
	DisplayTile(char, TCODColor, TCODColor, bool, bool);

	// Access Methods for ColorFG
	TCODColor GetForegroundColor();
	void SetForegroundColor(TCODColor);
	
	// Access Methods for ColorBG
	TCODColor GetBackgroundColor();
	void SetBackgroundColor(TCODColor);
	
	// Access Methods for AlphaBG
	bool GetBackgroundAlpha();
	void SetBackgroundAlpha(bool);
	
	// Access Methods for AlphaFG
	bool GetForegroundAlpha();
	void SetForegroundAlpha(bool);

	// Access Methods for Tile
	char GetTile();
	void SetTile(char);
};

#endif