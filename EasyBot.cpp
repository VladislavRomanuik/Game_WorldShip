#include "EasyBot.h"

bool EasyBot::FireByHit()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map->Cells[i][j]->GetState() == Hit)
			{
				int offseter = 1;
				for (int offseter = 2; offseter < 20; offseter++)
				{
					if (map->Cells[i][j]->refShip->IsRotate)
					{
						shot.x = i + offseter / 2 * (offseter % 2 == 0 ? -1 : 1);
						shot.x = shot.x < 0 ? 0 : shot.x > 9 ? 9 : shot.x;
						shot.y = j;
					}
					else
					{
						shot.y = j - offseter / 2 * (offseter % 2 == 0 ? -1 : 1);
						shot.y = shot.y < 0 ? 0 : shot.y > 9 ? 9 : shot.y;
						shot.x = i;
					}

					StateCell st = map->Cells[(int)shot.x][(int)shot.y]->GetState();
					if (st == Empty || st == ShipCell) return false;
				}
			}
		}
	}

	return true;
}

EasyBot::EasyBot(Map* map)
{
	this->map = map;
	shot = Point();
}

EasyBot::EasyBot() {}

Point EasyBot::Fire()
{

	if (FireByHit())
	{
		while (true)
		{
			shot.x = rand() % 10;
			shot.y = rand() % 10;
			StateCell st = map->Cells[(int)shot.x][(int)shot.y]->GetState();
			if (st == Empty || st == ShipCell)
			{
				return shot;
			}
		}
	}

	else
	{
		return shot;
	}
}
