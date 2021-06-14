#pragma once
#include <GL/freeglut.h>
#include "Map.h"
#include "Button.h"
#include "EasyBot.h"
#include "HardBot.h"
#include "Game.h"

void SetDiff(int p);

void InitMap(int p);

void SetStateGame(int p);


class InputSystem
{
private:
    vector<Button*> buttons;
    EasyBot* easyBot1;
    EasyBot* easyBot2;
    HardBot* hardBot1;
    HardBot* hardBot2;
    bool IsMousePressed;
    Button* buttonPlayerBot;
    Button* buttonBotBot;
    Button* buttonEasyGame;
    Button* buttonHardGame;
    Button* buttonNext;
    Button* buttonMenu;
    Button* buttonRandomMap;
    Drawable* regulations;
    Drawable* instrcutions;

public:
    Game* gameObj;
    Map* mapPlayer1;
    Map* mapPlayer2;

    InputSystem();

    void InitMaps(int typeGame);

    void SpecialKeys(int key, int x, int y);

    void Mouse(int button, int state, int x, int y);

    void MouseMove(int x, int y);

    void Next();
};



