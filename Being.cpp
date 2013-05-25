#include "Being.h"

Being::Being()
{
	this->Solid=true;
}

void Being::Send(Object * SentTo, Message Sending)
{
	SentTo->Recieve(Sending, this);
}