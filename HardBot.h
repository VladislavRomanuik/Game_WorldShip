#pragma once
#include "GlobalResource.h"
#include "EasyBot.h"
#include "Map.h"

class HardBot :
    public EasyBot
{
private:
    int chance;
public:
    HardBot(Map* map, int _chance);

    HardBot();

    virtual Point Fire();
};

