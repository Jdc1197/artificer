#ifndef INTERFACE_H
#define INTERFACE_H
#include "ColoredString.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Interface
{
private:
	vector<ColoredString> Messages;
public:
	Interface();
	Interface(ColoredString);

	void AddMessage(string);
	void AddMessage(ostringstream*);
	void AddMessage(const char *);

	ColoredString GetMessage(int);
};

#endif