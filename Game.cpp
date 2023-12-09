#include "Game.h"

Game::Game()
{
	Input::GetInstance(); //used to initialize Input isntance;
	Display::GetInstance();//used to initialize Display instance;
	Player::GetInstance(); //used to initialize Player instance;

	gameState = StateMachine();//should be initialized last due to dependences with utility classes.
}

void Game::Setup()
{
	gameState.SetUp(); //Setups gamestate to start with main menu.
}

void Game::Run()
{
	while (!isGameOver) {
		Input::GetInstance()->Update();
		gameState.Update();
	}
}

void Game::SetGameOver()
{
	isGameOver = true;
}