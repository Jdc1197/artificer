#ifndef RACES_H
#define RACES_H
#include "Being.h"

class Human : public Being
{
public:
	virtual DisplayTile GetTile();
};
#endif
