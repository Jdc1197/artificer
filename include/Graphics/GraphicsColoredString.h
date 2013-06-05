#ifndef GRAPHICSCOLOREDSTRING_H
#define GRAPHICSCOLOREDSTRING_H
#include "Graphics/Graphics.h"
#include "ColoredString.h"

// class GraphicsColoredString
// class to implement graphics with ColoredString
class GraphicsColoredString
{
private:
	ColoredString clstr;
	void DrawSegment(ColoredStringSegment, int, int, TCODConsole*);
public:
	GraphicsColoredString(ColoredString);
	void Draw(int, int, TCODConsole*);
	void Draw(int, int);
};

#endif