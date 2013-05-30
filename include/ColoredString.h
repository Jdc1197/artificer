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

