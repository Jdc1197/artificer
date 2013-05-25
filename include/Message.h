#ifndef MESSAGE_H
#define MESSAGE_H

enum MessageType {MOVE, TICK, PICKUP, DROP};
class Message
{
public:
	Message(MessageType Type);
	MessageType Type;
};

#endif