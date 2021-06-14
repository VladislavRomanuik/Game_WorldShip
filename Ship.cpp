#include "Ship.h"

Ship::Ship(Point GlobalP, Point GlobalS, bool IsRotate, int countDecks)
{
	this->IsRotate = IsRotate;
	this->countDecks = countDecks;
	countHited = 0;
	mapCoord = Point(15, 15);

	if (IsRotate)
	{
		Index = rotableShip[countDecks - 1];
		GlobalS = Point(GlobalS.y, GlobalS.x);
	}
	else
	{
		Index = noRotableShip[countDecks - 1];
	}

	this->GlobalPos = GlobalP;
	this->GlobalSize = GlobalS;
	
	for (int i = 0; i < countDecks; i++)
	{
		if (IsRotate)
			body.push_back(Point(i, 0));
		else	
			body.push_back(Point(0, i));
	}

	for (int i = -1; i < countDecks + 1; i++)
	{
		if (IsRotate)
		{
			border.push_back(Point(i, -1));
			border.push_back(Point(i, 1));
		}
		else
		{
			border.push_back(Point(-1, i));
			border.push_back(Point(1, i));
		}
	}

	if (IsRotate)
	{
		border.push_back(Point(-1, 0));
		border.push_back(Point(countDecks, 0));
	}
	else
	{
		border.push_back(Point(0, -1));
		border.push_back(Point(0, countDecks));
	}

	int height = IsRotate ? 2 : countDecks + 1;
	int width = IsRotate ? countDecks + 1 : 2;

	startPos = GlobalPos;
}

bool Ship::Hiting()
{
	countHited++;
	if (countHited >= body.size())
	{
		IsAlive = false;
		return true;
	}
	return false;
}
 