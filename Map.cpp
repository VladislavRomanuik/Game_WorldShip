#include "Map.h"

extern vector<Drawable*> drawObjects_layer0;
extern vector<Drawable*> drawObjects_layer1;
extern vector<Drawable*> drawObjects_layer2;
extern Window* windows[5];
int idDrag = -1;

Map::Map(Point GlobalPos, Point GlobalSize, int indexTexture, Game* game, bool isBot) 
	: Drawable(GlobalPos, GlobalSize, indexTexture)
{
	gameObj = game;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Cells[j][i] = new Cell(Point(GlobalPos.x + 32 + j * 32, GlobalPos.y - 32 - i * 32), Point(32, 32), 0);
			drawObjects_layer0.push_back(Cells[j][i]);
			//if (isBot)
				windows[2]->elements.push_back(Cells[j][i]);
			//else
				windows[1]->elements.push_back(Cells[j][i]);
				windows[4]->elements.push_back(Cells[j][i]);
		}
	}

	if (isBot)
	{
		Ships[0] = new Ship(Point(0, 0), Point(32, 32 * 4), rand() % 2 == 0, 4);
		Ships[1] = new Ship(Point(0, 0), Point(32, 32 * 3), rand() % 2 == 0, 3);
		Ships[2] = new Ship(Point(0, 0), Point(32, 32 * 3), rand() % 2 == 0, 3);
		Ships[3] = new Ship(Point(0, 0), Point(32, 32 * 2), rand() % 2 == 0, 2);
		Ships[4] = new Ship(Point(0, 0), Point(32, 32 * 2), rand() % 2 == 0, 2);
		Ships[5] = new Ship(Point(0, 0), Point(32, 32 * 2), rand() % 2 == 0, 2);
		Ships[6] = new Ship(Point(0, 0), Point(32, 32 * 1), rand() % 2 == 0, 1);
		Ships[7] = new Ship(Point(0, 0), Point(32, 32 * 1), rand() % 2 == 0, 1);
		Ships[8] = new Ship(Point(0, 0), Point(32, 32 * 1), rand() % 2 == 0, 1);
		Ships[9] = new Ship(Point(0, 0), Point(32, 32 * 1), rand() % 2 == 0, 1);


		Generate();

		
	}
	else
	{
		float startOffsetX = Cells[9][0]->GlobalPos.x + 64;
		float startOffsetY = Cells[9][0]->GlobalPos.y;
		Ships[0] = new Ship(Point(startOffsetX + 32 * 0, startOffsetY), Point(32, 32 * 4), false, 4);
		Ships[1] = new Ship(Point(startOffsetX + 32 * 5, startOffsetY), Point(32, 32 * 3), false, 3);
		Ships[2] = new Ship(Point(startOffsetX + 32 * 9, startOffsetY), Point(32, 32 * 3), false, 3);
		Ships[3] = new Ship(Point(startOffsetX + 32 * 13, startOffsetY), Point(32, 32 * 2), false, 2);
		Ships[4] = new Ship(Point(startOffsetX + 32 * 0, startOffsetY + 32 * 5), Point(32, 32 * 2), false, 2);
		Ships[5] = new Ship(Point(startOffsetX + 32 * 3, startOffsetY + 32 * 5), Point(32, 32 * 2), false, 2);
		Ships[6] = new Ship(Point(startOffsetX + 32 * 6, startOffsetY + 32 * 5), Point(32, 32 * 1), false, 1);
		Ships[7] = new Ship(Point(startOffsetX + 32 * 8, startOffsetY + 32 * 5), Point(32, 32 * 1), false, 1);
		Ships[8] = new Ship(Point(startOffsetX + 32 * 10, startOffsetY + 32 * 5), Point(32, 32 * 1), false, 1);
		Ships[9] = new Ship(Point(startOffsetX + 32 * 12, startOffsetY + 32 * 5), Point(32, 32 * 1), false, 1);

		/*for (auto& ship : Ships)
		{
			ship.IsVisible = false;
		}*/

		for (auto ship : Ships)
		{
			ship->mapCoord = Point(15, 15);
			drawObjects_layer1.push_back(ship);
			windows[1]->elements.push_back(ship);
			windows[2]->elements.push_back(ship);
			windows[4]->elements.push_back(ship);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		Ships[i]->ID = i;
	}
}

void Map::Generate()
{
	vector<Point> freeCells;
	bool setShip = false;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			freeCells.push_back(Point(j, i));

	for (auto ship : Ships)
	{
		do
		{
			ship->mapCoord = freeCells[rand() % freeCells.size()];

			Point pt(ship->mapCoord.x + ship->body.back().x,
				ship->mapCoord.y + ship->body.back().y);
			for (auto obj : freeCells)
			{
				if (obj == pt)
				{
					for (int j = 0; j < ship->border.size(); j++)
					{
						for (int i = 0; i < freeCells.size(); i++)
						{
							if (freeCells[i] == Point(ship->mapCoord.x + ship->border[j].x, ship->mapCoord.y + ship->border[j].y))
							{
								freeCells.erase(freeCells.begin() + i);
								break;
							}
						}
					}
					for (int j = 0; j < ship->body.size(); j++)
					{
						for (int i = 0; i < freeCells.size(); i++)
						{
							if (freeCells[i] == Point(ship->mapCoord.x + ship->body[j].x, ship->mapCoord.y + ship->body[j].y))
							{
								freeCells.erase(freeCells.begin() + i);
								break;
							}
						}
					}
					setShip = true;
					countSettedShips++;
					break;
				}
			}
		} while (setShip == false);

		setShip = false;

		ship->GlobalPos = Point(ship->mapCoord.x * Cells[0][0]->GlobalSize.x + Cells[0][0]->GlobalPos.x,
			Cells[0][0]->GlobalPos.y - ship->mapCoord.y * Cells[0][0]->GlobalSize.y);

		for (auto part : ship->body)
		{
			Cells[(int)(part.x + ship->mapCoord.x)][(int)(part.y + ship->mapCoord.y)]->SetState(StateCell::ShipCell);
			Cells[(int)(part.x + ship->mapCoord.x)][(int)(part.y + ship->mapCoord.y)]->refShip = ship;
		}
	}
}

void Map::ClickRotate(Point mousePt)
{
	if (mousePt.x > Cells[9][9]->GlobalPos.x + Cells[9][9]->GlobalSize.x)
	{
		
		for (auto& ship : Ships)
		{
			if (mousePt.x > ship->GlobalPos.x && mousePt.x < ship->GlobalPos.x + ship->GlobalSize.x
				&& mousePt.y > ship->GlobalPos.y - ship->GlobalSize.y && mousePt.y < ship->GlobalPos.y)
			{
				std::cout << ship->ID << std::endl;
				int id = ship->ID;

				Point curPos = ship->GlobalPos;
				Point curSize = ship->GlobalSize;
				bool curRotate = !ship->IsRotate;
				int curDecks = ship->countDecks;

				delete ship;
				
				for (int i = 0; i < drawObjects_layer1.size(); i++)
				{
					if (drawObjects_layer1[i] == ship)
					{
						drawObjects_layer1.erase(drawObjects_layer1.begin() + i);
					}
				}
				ship = new Ship(curPos, curSize, curRotate, curDecks);
				drawObjects_layer1.push_back(ship);
				windows[1]->elements.push_back(ship);
				windows[2]->elements.push_back(ship);
				windows[4]->elements.push_back(ship);
				ship->ID = id;
			}
		}
	}
}

void Map::DragShip(Point mousePt, int state)
{
	for (auto ship : Ships)
	{
		if (mousePt.x > ship->GlobalPos.x && mousePt.x < ship->GlobalPos.x + ship->GlobalSize.x
			&& mousePt.y > ship->GlobalPos.y - ship->GlobalSize.y && mousePt.y < ship->GlobalPos.y)
		{
			if (state == GLUT_DOWN) // down
			{
				idDrag = ship->ID;
				deltaMouse.x = mousePt.x;
				deltaMouse.y = mousePt.y;
			}
			else if (state == GLUT_UP) // up
			{
				idDrag = -1;
				float halfCell = Cells[0][0]->GlobalPos.x / 2;
				if (ship->GlobalPos.x + halfCell > Cells[0][0]->GlobalPos.x
					&& ship->GlobalPos.x + ship->GlobalSize.x - halfCell < Cells[9][0]->GlobalPos.x + Cells[9][0]->GlobalSize.x
					&& Cells[0][0]->GlobalPos.y > ship->GlobalPos.y - halfCell
					&& Cells[0][9]->GlobalPos.y - Cells[0][9]->GlobalSize.y < ship->GlobalPos.y - ship->GlobalSize.y + halfCell)
				{
					Point p = Point((ship->GlobalPos.x - Cells[0][0]->GlobalPos.x),
						(Cells[0][0]->GlobalPos.y - ship->GlobalPos.y));
					Point tempCoord = p / Cells[0][0]->GlobalSize.x;
					tempCoord.x = (int)tempCoord.x;
					tempCoord.y = (int)tempCoord.y;

					for (int i = 0; i < ship->body.size(); i++)
					{
						for (int j = 0; j < 10; j++) // every ship
						{
							if (ship->ID != Ships[j]->ID)
							{
								// check with other body
								for (int o = 0; o < Ships[j]->body.size(); o++)
								{
									Point pt = ship->body[i] + tempCoord;
									if (pt == Ships[j]->body[o] + Ships[j]->mapCoord
										|| pt.x < 0 || pt.x > 9 || pt.y < 0 || pt.y > 9)
									{
										ship->GlobalPos = ship->startPos;
										return; // collision with other ship
									}
								}
								// check with other border
								for (int o = 0; o < Ships[j]->border.size(); o++)
								{
									if (ship->body[i] + tempCoord == Ships[j]->border[o] + Ships[j]->mapCoord)
									{
										ship->GlobalPos = ship->startPos;
										return; // collision with other ship
									}
								}
							}
						}
					}
					// no collision with other ships
					ship->GlobalPos = Point(tempCoord.x * Cells[0][0]->GlobalSize.x + Cells[0][0]->GlobalPos.x,
						Cells[0][0]->GlobalPos.y - tempCoord.y * Cells[0][0]->GlobalSize.y);
					ship->mapCoord = tempCoord;
					ship->startPos = ship->GlobalPos;
					countSettedShips++;
				}
				else
				{
					ship->GlobalPos = ship->startPos;
				}
			}
		}
		if (state == 5) // moving
		{
			if (idDrag == ship->ID)
			{
				ship->GlobalPos.x += mousePt.x - deltaMouse.x;
				ship->GlobalPos.y += mousePt.y - deltaMouse.y;
				deltaMouse.x = mousePt.x;
				deltaMouse.y = mousePt.y;
			}

		}
	}
}

void Map::Fire(Point firePt)
{
	Cell* curCell = (Cells[(int)(firePt.x)][(int)(firePt.y)]);

	if (curCell->GetState() != StateCell::Empty)
	{
		if (curCell->GetState() == StateCell::ShipCell)
		{
			curCell->SetState(StateCell::Hit);
			if (curCell->refShip->Hiting())
			{
				for (auto &part : curCell->refShip->body)
				{
					Cells[(int)(curCell->refShip->mapCoord.x + part.x)]
						[(int)(curCell->refShip->mapCoord.y + part.y)]->SetState(StateCell::Die);
					
				}
				for (int i = 0; i < curCell->refShip->border.size(); i++)
				{
					int tx = (int)(curCell->refShip->mapCoord.x + curCell->refShip->border[i].x);
					int ty = (int)(curCell->refShip->mapCoord.y + curCell->refShip->border[i].y);
					if (tx < 0 || tx > 9 || ty < 0 || ty > 9) continue;
					Cells[tx][ty]->SetState(StateCell::Missed);
				}

				countDieShips++;
				if (countDieShips >= 10)
					gameObj->SetState(State::EndGame);
			}
		}
	}
	else
	{
		curCell->SetState(StateCell::Missed);
		gameObj->NextTurn();
	}
}

void Map::ApplyShipToCells()
{
	for (auto ship : Ships)
	{
		for (auto part : ship->body)
		{
			Cells[(int)(part.x + ship->mapCoord.x)][(int)(part.y + ship->mapCoord.y)]->SetState(StateCell::ShipCell);
			Cells[(int)(part.x + ship->mapCoord.x)][(int)(part.y + ship->mapCoord.y)]->refShip = ship;
		}
	}
}

void Map::GenerateMap()
{
	Generate();
}