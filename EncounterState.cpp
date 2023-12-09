#include "EncounterState.h"

bool States::EncounterState::CanEnter()
{
	// Check if the player instance is null
	if (Player::GetInstance() == nullptr)
		return false;

	return true;
}

void States::EncounterState::Enter()
{
	// Initialize combat data for the monster and player
	monsterCombatData = Creature();
	playerCombatData = dynamic_cast<Creature*>(Player::GetInstance());

	// Create a new combat screen and set the player combat data
	combatScreen = new CombatScreen();
	combatScreen->SetPlayerCombatData(playerCombatData);

	// Draw the base screen of the combat screen
	combatScreen->DrawBaseScreen();

	// Enable input
	Input::SuspendInput = false;
}

bool States::EncounterState::Execute()
{
	// Check if the game is over or the combat is over
	if (isGameOver || isCombatOver)
		return true; // Return true to change state

	// Update the combat screen
	combatScreen->Update();

	// Check if the player has finalized their choice
	if (combatScreen->IsChoiceFinalized())
	{
		// Resolve the combat round
		ResolveCombatRound();
	}

	return false; // Return false to continue executing
}

State* States::EncounterState::Exit()
{
	// Suspend input
	Input::SuspendInput = true;

	// Check if the game is over
	if (isGameOver)
		return new GameOverState(); // Return a new game over state

	return new MapState(); // Return a new map state
}

void States::EncounterState::ResolveCombatRound()
{
	// Get the menu choice from the combat screen
	int menuChoice = combatScreen->GetMenuChoice();
	int ammt = 0;

	switch (menuChoice) {
	case 0:
		// Attack
		ammt = playerCombatData->RollDamage();
		isCombatOver = monsterCombatData.TakeDamage(ammt);
		combatScreen->PushToCombatLog(MessageType::playerAttack, ammt);
		break;
	case 1:
		// Heal
		ammt = playerCombatData->Heal();
		combatScreen->PushToCombatLog(MessageType::playerHeal, ammt);
		break;

	case 2:
		// Recover
		ammt = playerCombatData->RecoverMP();
		combatScreen->PushToCombatLog(MessageType::playerRecover, ammt);
		break;
	default:
		system("cls");
		std::cout << "Something has gone wrong when executing combat round." << std::endl;
		system("pause");
		break;
	}

	if (isCombatOver) // Early end flag: Monster Died
		return;

	// Monster attack
	ammt = monsterCombatData.RollDamage();
	isGameOver = playerCombatData->TakeDamage(ammt);

	if (isGameOver) // Early end flag: Player Died
		return;

	combatScreen->PushToCombatLog(MessageType::monsterAttack, ammt);
	combatScreen->Reset();
}