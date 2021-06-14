#include "GlobalResource.h"
#include "HardBot.h"
#include "EasyBot.h"

HardBot::HardBot() : EasyBot() {}

HardBot::HardBot(Map* map, int _chance) : EasyBot(map) 
{
    chance = _chance;
}

Point HardBot::Fire()
{
    if (FireByHit())
    {
        while (true)
        {
            if (rand() % 10 <= chance)
            {
                int indexShipTarget = rand() % 10;
                Ship* ship = map->Ships[indexShipTarget];
                shot.x = ship->mapCoord.x;
                shot.y = ship->mapCoord.y;

                if (ship->IsRotate)
                    shot.x += (rand() % ship->countDecks);
                else
                    shot.y += (rand() % ship->countDecks);
                std::cout << shot.x << std::endl;
                std::cout << shot.y << std::endl;

                StateCell st = map->Cells[(int)shot.x][(int)shot.y]->GetState();
                if (st == Empty || st == ShipCell) return shot;
            }
            else
            {
                    shot.x = rand() % 10;
                    shot.y = rand() % 10;
                    StateCell st = map->Cells[(int)shot.x][(int)shot.y]->GetState();
                    if (st == Empty || st == ShipCell) return shot;
            }
        }
    }
    else
    {
        return shot;
    }
}
