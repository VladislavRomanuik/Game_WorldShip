#include "Cell.h"

void Cell::ChangeStateCell(StateCell stateCell)
{
    this->stateCell = stateCell;
}

Cell::Cell()
{
    stateCell = Empty;
}

Cell::Cell(Point GlobalPos, Point GlobalSize, int indexTexture) : Drawable(GlobalPos, GlobalSize, indexTexture)
{
    stateCell = Empty;
}

void Cell::SetState(StateCell value)
{
    stateCell = value;
    Index = stateCell == 4 ? Index : stateCell;
}

StateCell Cell::GetState()
{
    return stateCell;
}