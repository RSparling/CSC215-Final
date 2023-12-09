#pragma once
#include "State.h"
#include "Input.h"
#include "WinScreen.h"
#include "MainMenu.h"
using namespace States;

namespace States {
	class WinState :public State
	{
	public:
		// Inherited via State
		bool CanEnter() override;
		void Enter() override;
		bool Execute() override;
		State* Exit() override;

	private:
		Input* input;
		WinScreen winScreen;
	};
}