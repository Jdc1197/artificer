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
#ifndef TIME_H
#define TIME_H

#include "Message.h"
#include <vector>

using std::vector;
using std::iterator;
class Object;
class Being;


struct TimedEvent
{
	Being* Sender;
	Object* Receiver;
	float Delay;
	Message Msg;
};

/// A class which manages the time system
class TimeManager
{
private:
	/// List of TimedEvent
	vector<TimedEvent> EventList;
	/// Sorts the EventList by delay using Insertion Sort
	void SortEventList();
public:
	/// Adds a TimedEvent into the EventList
	void AddEvent(TimedEvent);
	/// Executes the next TimedEvent in the event list
	/// \returns The TimedEvent executed
	TimedEvent ExecuteNextEvent();
	/// Checks if a being has a TimedEvent in the list
	bool IsInList(Being*);
};


class TimableObject
{
public:
	virtual void ElapseTime(float);
};


#endif