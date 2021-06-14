#pragma once

#include "GlobalResource.h"
#include "Point.h"
#include "Map.h"

class EasyBot
{
protected:
	Map* map;
	Point shot;

	bool FireByHit();
public:
	
	EasyBot();

	EasyBot(Map* map);

	virtual Point Fire();

};

