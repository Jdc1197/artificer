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

#include "Interface.h"

Interface::Interface()
{
	Messages.assign(9, ColoredString("%[255,0,0]#%[255,255,0]#%[0,255,0]#%[0,255,255]#%[0,0,255]#"));
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