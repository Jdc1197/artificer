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

#ifndef MESSAGE_H
#define MESSAGE_H

enum MessageType
{
	MSGNULL = 0,
	ASSUME_CONTROL,	// Gives control to the being after his last move
	MOVE,		// Movement
	PICKUP,		// Pick up item
	DROP,		// Drop item
	CHAT		// Chat with being
};

class Message
{
public:
	Message();
	Message(MessageType Type);
	MessageType Type;
};

#endif