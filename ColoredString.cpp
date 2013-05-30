#include "ColoredString.h"
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;


// Segment functions
ColoredStringSegment::ColoredStringSegment() {}
ColoredStringSegment::ColoredStringSegment(const char * s) { str = s; }
ColoredStringSegment::ColoredStringSegment(const char * s, TCODColor c) { str = s; color = c; }
const char * ColoredStringSegment::GetString() { return str; }
TCODColor ColoredStringSegment::GetColor() { return color; }
void ColoredStringSegment::SetString(const char * s) { str = s; }
void ColoredStringSegment::SetColor(TCODColor c) { color = c; }
int ColoredStringSegment::GetLength() { return strlen(str); }

// String functions
ColoredString::ColoredString(const char * c, TCODColor color){ Parse(c, color); }
ColoredString::ColoredString(const char * c){ Parse(c, TCODColor(255,255,255)); }
ColoredString::ColoredString() {}

int ColoredString::GetFullStringSize()
{
	int size = 0;
	for (unsigned int i = 0; i < SegmentList.size(); i++)
		size += SegmentList[i].GetLength();
	return size;
}

unsigned int ColoredString::GetSize() { return SegmentList.size(); }

ColoredStringSegment ColoredString::GetSegment(int segment)
{
	if ((unsigned int)segment < SegmentList.size())
		return SegmentList[segment];
	return ColoredStringSegment();
}




void ColoredString::Parse(const char * str)
{
	Parse(str, TCODColor(255,255,255));
}

void ColoredString::Parse(const char * str, TCODColor DefaultColor)
{
	int temp_number = 0;
	SettingFlag setting = SettingFlag::None;
	bool inBracket = false;
	string current_str = "";
	TCODColor current_color, temp_color;
	current_color = DefaultColor;
	while(*str != '\0')
	{
		if (*str != '%')
		{
			if (!inBracket)
				current_str += *str;
			else
			{
				if (isdigit(*str))
					temp_number = ((temp_number*10) + ((*str)-48));
				else if (*str == ',')
				{
					if (setting == SettingFlag::Red)
						{temp_color.r = temp_number; setting = SettingFlag::Green; temp_number = 0; }
					else if (setting == SettingFlag::Green)
						{temp_color.g = temp_number; setting = SettingFlag::Blue; temp_number = 0; }
					else if (setting == SettingFlag::Blue)
						{temp_color.b = temp_number; setting = SettingFlag::None; temp_number = 0; }
				}
				else if (*str == ']')
				{
					if (setting == SettingFlag::Blue)
						{temp_color.b = temp_number; setting = SettingFlag::None; temp_number = 0; }
					ColoredStringSegment segment;
					segment.SetColor(current_color);
					char * str_duplicate = new char[current_str.length()+1];
					strcpy(str_duplicate, current_str.c_str());
					segment.SetString(str_duplicate);
					SegmentList.push_back(segment);
					current_str = "";
					current_color = temp_color;
					inBracket = false;
				}
			}
		}
		else if (*str == '%')
		{
			if (*(str+1) == '%')
			{
				current_str += *str;
				str++;
			}
			else if (*(str+1) == '[')
			{
				str++;
				inBracket = true;
				setting = SettingFlag::Red;
			}
		}
		str++;
	}
	ColoredStringSegment segment;
	segment.SetColor(current_color);
	char * str_duplicate = new char[current_str.length()+1];
	strcpy(str_duplicate, current_str.c_str());
	segment.SetString(str_duplicate);
	SegmentList.push_back(segment);
}
