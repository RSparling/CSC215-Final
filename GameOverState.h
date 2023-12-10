#pragma once
#include "State.h"
#include "Input.h"
#include "GameOverScreen.h"//for display
#include "MainMenu.h" //if the player decides to go again
#include <string>

using States::State;//for return type of state on exit;
namespace States {
	/*
	<summary>
		This state is for whent he player looses.
	</summary>
	*/
	class GameOverState :
		public State
	{
	public:
		GameOverState() {
			input = Input::GetInstance(); // so instance doesnt have to keep getting referenced
		}
		// Inherited via State
		bool CanEnter() override;
		void Enter() override;
		bool Execute() override;
		State* Exit() override;

	private:
		GameOverScreen gameOverScreen;
		Input* input;
		int menuChoice = -1;
	};
}