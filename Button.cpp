#include "Button.h"

void Nothing(int a) { }

void Button::Init()
{
    currentNewAction = 0;
    for (int i = 0; i < 5; i++)
    {
        action[i] = Nothing;
        paramClick[i] = 0;
    }
}

Button::Button()
{
    Init();
}

Button::Button(Point GlobalPos, Point GlobalSize, int indexTexture) : Drawable(GlobalPos, GlobalSize, indexTexture)
{
    Init();
}

void Button::CheckClick(Point mousePt)
{
    if (IsVisible)
    {
        if (mousePt.x > GlobalPos.x && mousePt.x < GlobalPos.x + GlobalSize.x
            && mousePt.y > GlobalPos.y - GlobalSize.y && mousePt.y < GlobalPos.y)
        {
            for (int i = 0; i < 5; i++)
            {
                action[i](paramClick[i]);
            }
        }
    }
}

void Button::AddAction(void (*func)(int), int param)
{
    if (currentNewAction >= 5) return;

    action[currentNewAction] = func;
    paramClick[currentNewAction] = param;
    currentNewAction++;
}