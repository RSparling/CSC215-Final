#pragma once
#include <iostream>
#include <string> //to store comba log
#include "Display.h"
#include "Input.h"
#include "Creature.h"


enum MessageType {
	playerHeal,
	playerAttack,
	playerRecover,
	monsterAttack
};

/*
<summary>
This class is used to display the combat screen and get the user's input.
It should not handle actual combat logic.
</summary>
*/
class CombatScreen
{
public:
	CombatScreen();

	void DrawBaseScreen();

	void Update();

	void Reset();

	//setters
	void SetPlayerCombatData(Creature* player) { playerCombatData = player; }

	//getters
	int GetMenuChoice() { return menuChoice; }
	int GetSubMenuChoice() { return subMenuChoice; }
	bool IsChoiceFinalized() { return choiceFinalized; }
	void PushToCombatLog(enum MessageType, int value);

private:
	int menuChoice = 0;
	int subMenuChoice = 0;

	//utility functions
	void DrawMenu();

	void Menu();
	void UpdateHealthBars();
	void UpdateCombatLogs();
	Creature* playerCombatData;
	
	std::string screenBase;
	std::vector<std::string> combatLog;
	//Control flags
	bool mainChoiceSelected = false;
	bool choiceFinalized = false;
};

