/*	
	Artificer: A roguelike game.
    Copyright (C) 2013 Jdc1197

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Contact Jdc1197 by email at: Jdc1197@gmail.com
*/

#include "DisplayTile.h"

DisplayTile::DisplayTile()
{
	Tile = ' ';
	ColorFG = TCODColor(0,0,0);
	ColorBG = TCODColor(0,0,0);
	AlphaBG = false;
	AlphaFG = false;
}

DisplayTile::DisplayTile(unsigned char c, TCODColor Foreground, TCODColor Background )
{
	Tile = c;
	ColorFG = Foreground;
	ColorBG = Background;
	AlphaBG = false;
	AlphaFG = false;
}

DisplayTile::DisplayTile(unsigned char c, TCODColor Foreground, TCODColor Background, bool BackgroundAlpha)
{
	Tile = c;
	ColorFG = Foreground;
	ColorBG = Background;
	AlphaBG = BackgroundAlpha;
	AlphaFG = false;
}

DisplayTile::DisplayTile(unsigned char c, TCODColor Foreground, TCODColor Background, bool BackgroundAlpha, bool ForegroundAlpha)
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


unsigned char DisplayTile::GetTile() {return Tile;}
void DisplayTile::SetTile(unsigned char Tile) {this->Tile = Tile;}