#pragma once
#include "GlobalResource.h"
#include "Point.h"
#include "Drawable.h"

using std::vector;

class Ship : public Drawable
{
private:
	int rotableShip[4] = { 6, 10, 11, 12 }; 
	int noRotableShip[4] = { 6, 7, 8, 9 }; 
public:
	Ship() {}

	Ship(Point GlobalPos, Point GlobalSize, bool IsRotate, int countDecks);

	Point startPos;
	vector<Point> border;
	vector<Point> body; // сам корабль
	Point mapCoord; // координаты на карте
	
	int ID;
	int countHited;
	int countDecks;

	bool IsRotate;

	bool IsAlive = true;

	bool Hiting();
};
