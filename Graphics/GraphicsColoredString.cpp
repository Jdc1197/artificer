#include "Graphics/GraphicsColoredString.h"

GraphicsColoredString::GraphicsColoredString(ColoredString coloredString)
{
	clstr = coloredString;
}

void GraphicsColoredString::DrawSegment(ColoredStringSegment seg, int x, int y, TCODConsole * console)
{
	console->printLeft(x, y, TCOD_BKGND_NONE, "%c%c%c%c%s%c", TCOD_COLCTRL_FORE_RGB, seg.GetColor().r, seg.GetColor().g, seg.GetColor().b, seg.GetString(), TCOD_COLCTRL_STOP);
}

void GraphicsColoredString::Draw(int x, int y) { Draw(x, y, TCODConsole::root); }
void GraphicsColoredString::Draw(int x, int y, TCODConsole * console)
{
	int offset = 0;
	for (unsigned int i = 0; i < clstr.GetSize(); i++)
	{
		ColoredStringSegment Segment = clstr.GetSegment(i);
		DrawSegment(Segment, x+offset, y, console);
		offset += Segment.GetLength();
	}
}