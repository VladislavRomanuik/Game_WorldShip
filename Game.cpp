#include "Game.h"

extern Window* windows[5];
extern vector<Drawable*> drawObjects_layer0;
extern vector<Drawable*> drawObjects_layer1;
extern vector<Drawable*> drawObjects_layer2;

Game::Game()
{
	windows[0] = new Window();
	windows[1] = new Window();
	windows[2] = new Window();
	windows[3] = new Window();
	windows[4] = new Window();
	
	howTurn = 0;
	difficult = 0;

	howTurnImage = new Drawable(Point(660, 830), Point(200, 168), 5);
	nickPlayer1 = new Drawable(Point(200, 900), Point(200, 80), 19);
	nickPlayer2 = new Drawable(Point(1200, 900), Point(200, 80), 20);
	mainInscription = new Drawable(Point(700, 1000), Point(500, 200), 22);

	drawObjects_layer0.push_back(howTurnImage);
	drawObjects_layer0.push_back(nickPlayer1);
	drawObjects_layer0.push_back(nickPlayer2);
	windows[2]->elements.push_back(howTurnImage);
	windows[2]->elements.push_back(nickPlayer1);
	windows[2]->elements.push_back(nickPlayer2);
	windows[0]->elements.push_back(mainInscription);
	drawObjects_layer1.push_back(mainInscription);

}

void Game::SetState(int newState)
{
	stateGame = (State)newState;
	for (auto window : windows)
	{
		window->SetActive(false);
	}
	windows[((int)stateGame) == 3 ? 2 : (int)stateGame]->SetActive(true);
}

State Game::GetCurrentState()
{
	return stateGame;
}

void Game::SetDifficult(int diff)
{
	difficult = diff;
}

int Game::GetDifficult()
{
	return difficult;
}

void Game::NextTurn()
{
	howTurn = !howTurn;
	if (howTurn == 0)
	{
		howTurnImage->Index = 5;
	}
	else
	{
		howTurnImage->Index = 17;
	}
}

void Game::Quit(int res)
{

}
