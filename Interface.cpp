#include "Interface.h"

Interface::Interface()
{
	Messages.assign(Messages.size(), ColoredString("%[255,0,0]#%[255,255,0]#%[0,255,0]#%[0,255,255]#%[0,0,255]#"));
}

Interface::Interface(ColoredString Message)
{
	Messages.assign(9, "");
	Messages[0] = Message;
}


void Interface::AddMessage(string Message)
{
	Messages.erase(Messages.end()-1);
	Messages.insert(Messages.begin(), ColoredString(Message.c_str()));
}
void Interface::AddMessage(ostringstream* Message)
{
	Messages.erase(Messages.end()-1);
	Messages.insert(Messages.begin(), ColoredString(Message->str().c_str()));
}
void Interface::AddMessage(const char * Message)
{
	Messages.erase(Messages.end()-1);
	Messages.insert(Messages.begin(), ColoredString(Message));
}

ColoredString Interface::GetMessage(int MessageNumber)
{
	ColoredString r = (MessageNumber >= 0 && MessageNumber < 9) ? Messages[MessageNumber] : ColoredString("");
	return r;
}