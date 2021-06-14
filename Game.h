#pragma once
#include <GL/freeglut.h>
#include "GlobalResource.h"
#include "State.h"
#include "Window.h"

class Game
{
private:
	int difficult;
	State stateGame;
public:
	Drawable* howTurnImage;
	Drawable* nickPlayer1;
	Drawable* nickPlayer2;
	Drawable* mainInscription;
	int howTurn;

	Game();

	void SetState(int newState);

	State GetCurrentState();

	void SetDifficult(int diff);

	int GetDifficult();

	void NextTurn();

	void Quit(int res);
};

