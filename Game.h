#pragma once
#include "StateMachine.h"
#include "Display.h"
#include "Player.h"

class Game
{
public:
	Game();

	//called once to initialize starting variables and values
	void Setup();
	//begin the game, contains gameplay loop using the state machine to change the states
	void Run();
	//used to flag a gameover state and call an exit from the main loop to the failure state.
	void SetGameOver();
private:
	bool isGameOver = false;
	StateMachine gameState;
	Player player;
};