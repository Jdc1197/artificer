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
#include "Time.h"
#include "Being.h"
#include <algorithm>

void TimeManager::SortEventList()
{
	for (vector<TimedEvent>::iterator i = EventList.begin() + 1; i < EventList.end(); ++i)
	{
		for(vector<TimedEvent>::iterator j = i; j->Delay < (j - 1)->Delay && j > EventList.begin(); --j )
		{
			std::iter_swap((j - 1), j);
		}
	}
}

void TimeManager::AddEvent(TimedEvent Evnt)
{
	EventList.push_back(Evnt);
}

TimedEvent TimeManager::ExecuteNextEvent()
{
	// Send the message
	EventList[0].Receiver->Receive(EventList[0].Msg, EventList[0].Sender);
	// Decrease the delay of the rest of the list.
	for (unsigned int i = 1; i < EventList.size(); i++)
			EventList[i].Delay -= EventList[0].Delay;
	TimedEvent R = *EventList.begin();
	// Remove the event from the list
	EventList.erase(EventList.begin());
	return R;
}

bool TimeManager::IsInList(Being* B)
{
	for (unsigned int i = 0; i < EventList.size();)
		if (EventList[i].Sender == B)
			return true;
	return false;
}

void TimableObject::ElapseTime(float time){}