#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Interface
{
private:
	vector<string> Messages;
public:
	Interface();
	Interface(string);

	void AddMessage(string);
	void AddMessage(ostringstream*);
	void AddMessage(const char *);

	const char* GetMessage(int);
};

#endif