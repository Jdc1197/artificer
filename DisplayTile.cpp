#include "DisplayTile.h"

DisplayTile::DisplayTile()
{
	Tile = ' ';
	ColorFG = TCODColor(0,0,0);
	ColorBG = TCODColor(0,0,0);
	AlphaBG = false;
	AlphaFG = false;
}

DisplayTile::DisplayTile(char c, TCODColor Foreground, TCODColor Background )
{
	Tile = c;
	ColorFG = Foreground;
	ColorBG = Background;
	AlphaBG = false;
	AlphaFG = false;
}

DisplayTile::DisplayTile(char c, TCODColor Foreground, TCODColor Background, bool BackgroundAlpha)
{
	Tile = c;
	ColorFG = Foreground;
	ColorBG = Background;
	AlphaBG = BackgroundAlpha;
	AlphaFG = false;
}

DisplayTile::DisplayTile(char c, TCODColor Foreground, TCODColor Background, bool BackgroundAlpha, bool ForegroundAlpha)
{
	Tile = c;
	ColorFG = Foreground;
	ColorBG = Background;
	AlphaBG = BackgroundAlpha;
	AlphaFG = ForegroundAlpha;
}


TCODColor DisplayTile::GetBackgroundColor() { return ColorBG; }
void DisplayTile::SetBackgroundColor(TCODColor Color) {ColorBG = Color;}

TCODColor DisplayTile::GetForegroundColor() { return ColorFG; }
void DisplayTile::SetForegroundColor(TCODColor Color) {ColorFG = Color;}

bool DisplayTile::GetBackgroundAlpha() { return AlphaBG; }
void DisplayTile::SetBackgroundAlpha(bool b) { AlphaBG = b; }

bool DisplayTile::GetForegroundAlpha() { return AlphaFG; }
void DisplayTile::SetForegroundAlpha(bool b) { AlphaFG = b; }


char DisplayTile::GetTile() {return Tile;}
void DisplayTile::SetTile(char Tile) {this->Tile = Tile;}