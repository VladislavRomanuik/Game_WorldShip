#pragma once
#include "Drawable.h"

class Button :
    public Drawable
{
private:
    void (*action[5])(int);
    int paramClick[5];
    int currentNewAction = 0;
public:

    Button();

    Button(Point GlobalPos, Point GlobalSize, int indexTexture);

    void CheckClick(Point mousePt);

    void AddAction(void (*func)(int), int param);

    void Init();
};

