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

#include "Graphics/GraphicsColoredString.h"

void GraphicsColoredString::DrawSegment(ColoredStringSegment seg, int x, int y, ScreenFlag screen)
{
	GetScreen(screen)->printEx(x, y, TCOD_BKGND_NONE, TCOD_LEFT, "%c%c%c%c%s%c", TCOD_COLCTRL_FORE_RGB, seg.GetColor().r, seg.GetColor().g, seg.GetColor().b, seg.GetString(), TCOD_COLCTRL_STOP);
}

void GraphicsColoredString::Draw(ColoredString clstr, int x, int y)
{
	Draw(clstr, x, y, ScreenFlag::Root);
}
void GraphicsColoredString::Draw(ColoredString clstr, int x, int y, ScreenFlag screen)
{
	int offset = 0;
	for (unsigned int i = 0; i < clstr.GetSize(); i++)
	{
		ColoredStringSegment Segment = clstr.GetSegment(i);
		DrawSegment(Segment, x+offset, y, screen);
		offset += Segment.GetLength();
	}
}
