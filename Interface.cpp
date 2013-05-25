#include "Interface.h"

Interface::Interface()
{
	Messages.assign(9, "");
	for (int i = 0; i < 9; i++)
		Messages[i] = char(i+65);
}

Interface::Interface(std::string Message)
{
	Messages.assign(9, "");
	Messages[0] = Message;
}


void Interface::AddMessage(string Message)
{
	Messages.erase(Messages.end()-1);
	Messages.insert(Messages.begin(), Message);
}
void Interface::AddMessage(ostringstream* Message)
{
	Messages.erase(Messages.end()-1);
	Messages.insert(Messages.begin(), Message->str());
}
void Interface::AddMessage(const char * Message)
{
	Messages.erase(Messages.end()-1);
	Messages.insert(Messages.begin(), Message);
}

const char * Interface::GetMessage(int MessageNumber)
{
	const char * r = (MessageNumber >= 0 && MessageNumber < 9) ? Messages[MessageNumber].c_str() : "";
	return r;
}