#pragma once
#include "State.h"
#include "MapState.h"
#include "MainMenuScreen.h"

namespace States {
	/*
		<summary>
		MainMenu state, starting state for the application.
		</summary>
	*/
	class MainMenu : public State
	{
	public:
		MainMenu();

		// Inherited via State
		bool CanEnter() override;
		void Enter() override;
		bool Execute() override;
		State* Exit() override;

	private:
		MainMenuScreen menuScreen;
		int menuChoice = 0;
	};
}