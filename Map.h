#pragma once

#include "GlobalResource.h"
#include "Cell.h"
#include "Ship.h"
#include "Game.h"
#include "Drawable.h"

class Map : public Drawable
{
private:
	Point deltaMouse;
	Game* gameObj;
	
public:
	Cell* Cells[10][10];
	Ship* Ships[10];
	int countSettedShips = 0;
	int countDieShips = 0;
	
	Map() { }

	Map(Point GlobalPos, Point GlobalSize, int indexTexture, Game* game, bool isBot);

	void Fire(Point firePt);

	void Generate();

	void ClickRotate(Point mousePt);

	void DragShip(Point mousePt, int state);
	
	void ApplyShipToCells();

	void GenerateMap();
};