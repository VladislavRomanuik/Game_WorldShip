#pragma once

#include "GlobalResource.h"
#include "Point.h"

class Drawable
{
public:
    bool IsVisible = true;
	Point GlobalPos;
    Point GlobalSize;
    int Index = 0;

    Drawable() {}

    Drawable(Point GlobalPos, Point GlobalSize, int indexTexture);

    bool operator==(Drawable& obj);    

    void DrawSelf();
};

