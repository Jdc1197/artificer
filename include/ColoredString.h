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

#ifndef COLOREDSTRING_H
#define COLOREDSTRING_H
#include <vector>
#include <libtcod.hpp>
using std::vector;


enum class SettingFlag
{
	None = 0,
	Red,
	Green,
	Blue
};

class ColoredStringSegment
{
private:
	const char * str;
	TCODColor color;
public:
	ColoredStringSegment();
	ColoredStringSegment(const char *);
	ColoredStringSegment(const char *, TCODColor);
	
	int GetLength();
	
	// Access methods
	const char * GetString();
	TCODColor GetColor();
	
	void SetColor(TCODColor);
	void SetString(const char *);
};


// class ColoredString
// a string which changes colors inbetween the text
class ColoredString
{
private:
	vector<ColoredStringSegment> SegmentList;
public:
	ColoredString();
	ColoredString(const char *);
	ColoredString(const char *, TCODColor);
	
	int GetFullStringSize();		// returns the full size of all of the segments
	unsigned int GetSize();					// returns the size of the SegmentList vector
	ColoredStringSegment GetSegment(int);	// returns one of the segments
	
	void Parse(const char *, TCODColor);
	void Parse(const char *);
};

#endif

