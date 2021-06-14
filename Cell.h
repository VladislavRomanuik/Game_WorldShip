#pragma once
#include "Drawable.h"
#include "StateCell.h"
#include "Ship.h"

class Cell :
    public Drawable
{
private:
    void ChangeStateCell(StateCell stateCell);
    StateCell stateCell;

public:
    Ship* refShip;

    Cell();

    Cell(Point GlobalPos, Point GlobalSize, int indexTexture);
   
    
    void SetState(StateCell value);
    StateCell GetState();
};

