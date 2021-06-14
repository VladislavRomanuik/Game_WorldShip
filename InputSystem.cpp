#include "InputSystem.h"

extern float coord_x, coord_y;
extern float HALF_SCREEN_WIDTH, HALF_SCEEN_HEIGHT, SCREN_HEIGHT, SCREN_WIDTH;
extern vector<Drawable*> drawObjects_layer0;
extern vector<Drawable*> drawObjects_layer1;
extern vector<Drawable*> drawObjects_layer2;
extern InputSystem inputSystem;
extern Window* windows[5];

void SetDiff(int p)
{
    inputSystem.gameObj->SetDifficult(p);
}

void InitMap(int p)
{
    inputSystem.InitMaps(p);
}

void SetStateGame(int p)
{
    inputSystem.gameObj->SetState(p);
}

void NextState(int p)
{
    inputSystem.Next();
}

void GoToMenu(int p)
{
    inputSystem.gameObj->SetState(State::Menu);
    for (auto window : windows)
    {
        window->elements.clear();
    }
    drawObjects_layer0.clear();
    drawObjects_layer1.clear();
    drawObjects_layer2.clear();
    inputSystem = InputSystem();
}

void RandomMap(int p)
{
    inputSystem.mapPlayer1->GenerateMap();
}

InputSystem::InputSystem()
{
    gameObj = new Game();

    buttonPlayerBot = new Button(Point(860, 550), Point(200, 80), 13);
    buttonPlayerBot->AddAction(InitMap, 0);
    drawObjects_layer1.push_back(buttonPlayerBot);
    buttons.push_back(buttonPlayerBot);
    windows[0]->elements.push_back(buttonPlayerBot);

    buttonBotBot = new Button(Point(860, 450), Point(200, 80), 14);
    buttonBotBot->AddAction(InitMap, 1);
    drawObjects_layer1.push_back(buttonBotBot);
    buttons.push_back(buttonBotBot);
    windows[0]->elements.push_back(buttonBotBot);

    buttonEasyGame = new Button(Point(860, 750), Point(200, 80), 15);
    buttonEasyGame->AddAction(SetDiff, 0);
    drawObjects_layer1.push_back(buttonEasyGame);
    buttons.push_back(buttonEasyGame);
    windows[0]->elements.push_back(buttonEasyGame);

    buttonHardGame = new Button(Point(860, 650), Point(200, 80), 16);
    buttonHardGame->AddAction(SetDiff, 1);
    drawObjects_layer1.push_back(buttonHardGame);
    buttons.push_back(buttonHardGame);
    windows[0]->elements.push_back(buttonHardGame);

    buttonNext = new Button(Point(1300, 150), Point(200, 80), 18);
    buttonNext->AddAction(NextState, 0);
    drawObjects_layer1.push_back(buttonNext);
    buttons.push_back(buttonNext);
    windows[1]->elements.push_back(buttonNext);

    buttonMenu = new Button(Point(1300, 150), Point(200, 80), 18);
    buttonMenu->AddAction(GoToMenu, 0);
    drawObjects_layer1.push_back(buttonMenu);
    buttons.push_back(buttonMenu);
    windows[4]->elements.push_back(buttonMenu);


    buttonRandomMap = new Button(Point(1300, 400), Point(200, 80), 18);
    buttonRandomMap->AddAction(RandomMap, 0);
    drawObjects_layer1.push_back(buttonRandomMap);
    buttons.push_back(buttonRandomMap);
    windows[1]->elements.push_back(buttonRandomMap);


    regulations = new Drawable(Point(0, 1080), Point(1920, 1080), 23);
    regulations->IsVisible = false;
    drawObjects_layer1.push_back(regulations);

    instrcutions = new Drawable(Point(300, 900), Point(1073, 466), 24);
    instrcutions->IsVisible = false;
    drawObjects_layer1.push_back(instrcutions);

    gameObj->SetState(State::Menu);
}

void InputSystem::InitMaps(int typeGame)
{
    if (typeGame == 0) // player vs bot
    {
        mapPlayer1 = new Map(Point(100, 800), Point(32 * 11, 32 * 11), 4, gameObj, false);
        gameObj->SetState(State::SetShips);

        drawObjects_layer0.push_back(mapPlayer1);
        windows[1]->elements.push_back(mapPlayer1);
        windows[2]->elements.push_back(mapPlayer1);
        windows[4]->elements.push_back(mapPlayer1);
    }
    else // bot vs bot
    {
        mapPlayer1 = new Map(Point(100, 800), Point(32 * 11, 32 * 11), 4, gameObj, true);
        mapPlayer2 = new Map(Point(700 + 32 * 11 + 40, 800), Point(32 * 11, 32 * 11), 4, gameObj, true);
        gameObj->SetState(State::GameBotBot);
        easyBot2 = new EasyBot(mapPlayer1);
        hardBot2 = new HardBot(mapPlayer1, 0);
        easyBot1 = new EasyBot(mapPlayer2);
        hardBot1 = new HardBot(mapPlayer2, 0);

        drawObjects_layer0.push_back(mapPlayer1);
        drawObjects_layer0.push_back(mapPlayer2);
        windows[2]->elements.push_back(mapPlayer1);
        windows[2]->elements.push_back(mapPlayer2);
        windows[4]->elements.push_back(mapPlayer1);
        windows[4]->elements.push_back(mapPlayer2);
    }

    windows[0]->SetActive(false);

}

void InputSystem::Next()
{
    if (mapPlayer1->countSettedShips < 10) return;

    mapPlayer2 = new Map(Point(700 + 32 * 11 + 40, 800), Point(32 * 11, 32 * 11), 4, gameObj, true);
    gameObj->SetState(State::GamePlayerBot);
    easyBot2 = new EasyBot(mapPlayer1);
    hardBot2 = new HardBot(mapPlayer1, 5);
    mapPlayer1->ApplyShipToCells();

    drawObjects_layer0.push_back(mapPlayer2);
    windows[2]->elements.push_back(mapPlayer2);
    windows[4]->elements.push_back(mapPlayer2);
}

void InputSystem::SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_F1:
        regulations->IsVisible = !regulations->IsVisible;
        break;
    case GLUT_KEY_F2:
        // action
        break;
    }
}

void InputSystem::Mouse(int button, int state, int x, int y)
{
    //coord_x = (mx / HALF_SCREEN_WIDTH - 1.0);
    //coord_y = -(my / HALF_SCEEN_HEIGHT - 1.0);
    coord_x = x;
    coord_y = SCREN_HEIGHT - y;
    
    if (gameObj->GetCurrentState() == State::SetShips && button == GLUT_LEFT_BUTTON)
    {
        mapPlayer1->DragShip(Point(coord_x, coord_y), state);
    }

    if (gameObj->GetCurrentState() == State::SetShips && button == GLUT_RIGHT_BUTTON)
    {
        mapPlayer1->ClickRotate(Point(coord_x, coord_y));
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (state == GLUT_DOWN)
        {
            for (auto button : buttons)
            {
                button->CheckClick(Point(coord_x, coord_y));
            }
        }
        
        if (state == GLUT_DOWN)
        {
            if (gameObj->GetCurrentState() == State::GamePlayerBot)
            {
                
                if (gameObj->howTurn == 0) // player 1 (human)
                {
                    Point p = Point((coord_x - mapPlayer2->Cells[0][0]->GlobalPos.x),
                        (mapPlayer2->Cells[0][0]->GlobalPos.y - coord_y));
                    Point tempCoord = p / mapPlayer2->Cells[0][0]->GlobalSize.x;
                    tempCoord.x = (int)tempCoord.x;
                    tempCoord.y = (int)tempCoord.y;

                    if (tempCoord.x >= 0 && tempCoord.y >= 0 && tempCoord.x <= 9 && tempCoord.y <= 9)
                        mapPlayer2->Fire(tempCoord);
                }
                else // player 2 (bot)
                {
                    //gameObj.NextTurn();
                    if (gameObj->GetDifficult() == 0) // easy bot
                        mapPlayer1->Fire(easyBot2->Fire());
                    else // hard bot
                        mapPlayer1->Fire(hardBot2->Fire());
                }
            }
            else if (gameObj->GetCurrentState() == State::GameBotBot)
            {
                if (gameObj->howTurn == 0) // player 1 (bot)
                {
                    if (gameObj->GetDifficult() == 0) // easy bot
                        mapPlayer2->Fire(easyBot1->Fire());
                    else // hard bot
                        mapPlayer2->Fire(hardBot1->Fire());
                }
                else // player 2 (bot)
                {
                    if (gameObj->GetDifficult() == 0) // easy bot
                        mapPlayer1->Fire(easyBot2->Fire());
                    else // hard bot
                        mapPlayer1->Fire(hardBot2->Fire());
                }
            }
        }
    }
}

void InputSystem::MouseMove(int x, int y)
{
    if (gameObj->GetCurrentState() == State::SetShips)
    {
        coord_x = x;
        coord_y = SCREN_HEIGHT - y;
        mapPlayer1->DragShip(Point(coord_x, coord_y), 5);
    }
}