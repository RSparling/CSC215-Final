#include "CombatScreen.h"

CombatScreen::CombatScreen()
{
	screenBase =
		"|______________________________________________________________________________________________________________________|\n"//0
		"|                                                                                                                      |\n"//1
		"|                              ,     .                                                                                 |\n"//2
		"|                             /(     )\\               A                                                               |\n"//3
		"|                        .--.( `.___.' ).--.         /_\\                                                               |\n"//4
		"|                        `._ `%_&%#%$_ ' _.'     /| <___> |\\                                                           |\n"//5
		"|                           `|(@\\*%%/@)|'       / (  |L|  ) \\                                                          |\n"//6
		"|                            |  |%%#|  |       J d8bo|=|od8b   L                                                       |\n"//7
		"|                             \\ \\$#%/ /        | 8888|=|8888 |                                                        |\n"//8
		"|                             |\\|%%#|/|        J Y8P\" |= | \"Y8P F                                                     |\n"//9
		"|                             | (.\".) % |       \\ (| L | ) /                                                           |\n"//10
		"|                         ___.'  `-'  `.___      \\|  |L|  |/                                                          |\n"//11
		"|                       .'#*#`-       -'$#*`.       / )|                                                               |\n"//12
		"|                      /#%^#%*_ *%^%_  #  %$%\\    .J (__)                                                              |\n"//13
		"|                      #&  . %%%#% ###%*.   *%\\.-'&# (__)                                                              |\n"//14
		"|----------|           %*  J %.%#_|_#$.\\J* \\ %'#%*^  (__)                                                             |\n"//15
		"|HP        |           *#% J %$%%#|#$#$ J\\%   *   .--|(_)                                                             |\n"//16
		"|          |            |%  J\\ `%%#|#%%' / `.   _.'  |L|                                                              |\n"//17
		"|----------|            |#$%||` %%%$### '|   `-'      |L|                                                              |\n"//18
		"|MP        |            (#%%||` #$#$%%% '|            |L|                                                              |\n"//19
		"|          |             | ##||  $%%.%$%  |           |L|                                                              |\n"//20
		"|--------------------------------Message-Box---------------------------------------------------------------------------|\n"//21
		"|>Attack    |                                                                                                          |\n"//22
		"| Heal      |                                                                                                          |\n"//23
		"| Focus     |                                                                                                          |\n"//24
		"|           |                                                                                                          |\n"//25
		"|___________|__________________________________________________________________________________________________________|\n"//26
		;
}

//draws the underlying screen
void CombatScreen::DrawBaseScreen() {
	Display::GetInstance()->SetCursorPosition(0, 0);
	std::cout << screenBase;
	UpdateHealthBars();
	Menu();
	UpdateCombatLogs();
	Display::GetInstance()->PlaceCursorAtBottom();
}

//Core loop of combat screen
void CombatScreen::Update()
{
	Input input = *Input::GetInstance();

	UpdateHealthBars();
	Menu();
	UpdateCombatLogs();
	//on enter preform the action
	if (input.GetKeyDown(KeyCode::Enter)) {
		choiceFinalized = true;
	}
	if (input.GetKeyDown(KeyCode::Esc)) {
		Reset();
	}
}

//Resets screen to base state, used after a combat round or on esc
void CombatScreen::Reset() {
	Display::GetInstance()->SetCursorPosition(0, 0);
	system("cls");
	mainChoiceSelected = false;
	choiceFinalized = false;
	menuChoice = 0;
	subMenuChoice = 0;
	DrawBaseScreen();
	Display::GetInstance()->PlaceCursorAtBottom();
}

//pushes information to the log regarding what happens turn to turn.
void CombatScreen::PushToCombatLog(MessageType message, int value)
{
	switch (message)
	{
	case MessageType::playerAttack:
		combatLog.push_back("You attack for " + std::to_string(value) + " damage.");
		break;
	case MessageType::playerHeal:
		combatLog.push_back("You heal for " + std::to_string(value) + " health.");
		break;
	case MessageType::playerRecover:
		combatLog.push_back("You recover " + std::to_string(value) + " mana.");
		break;
	case MessageType::monsterAttack:
		combatLog.push_back("The monster attacks for " + std::to_string(value) + " damage.");
		break;
	default:
		break;
	}
}

//Draw the entire thing
void CombatScreen::DrawMenu()
{
	Display::GetInstance()->SetCursorPosition(0, 0);
	std::cout << screenBase;
	UpdateHealthBars();
}

//draws the first selection menu
void CombatScreen::Menu()
{
	Display* display = Display::GetInstance();
	Input* input = Input::GetInstance();

	display->SetCursorPosition(1, 22 + menuChoice);
	std::cout << " ";
	if (input->GetKeyDown(KeyCode::Arrow_Up))
		menuChoice -= 1;
	else if (input->GetKeyDown(KeyCode::Arrow_Down))
		menuChoice += 1;

	if (menuChoice < 0)
		menuChoice = 2;
	if (menuChoice > 2)
		menuChoice = 0;

	display->SetCursorPosition(1, 22 + menuChoice);
	std::cout << ">";
}

//draws the player health information
void CombatScreen::UpdateHealthBars()
{
	Display* display = Display::GetInstance();
	display->SetCursorPosition(5, 17);
	std::cout << playerCombatData->GetHealth() << "  ";
	display->SetCursorPosition(5, 20);
	std::cout << playerCombatData->GetMana() << "  ";
}

//draws the combat log
void CombatScreen::UpdateCombatLogs()
{
	if (combatLog.size() == 0)//early return flag
		return;
	Display* display = Display::GetInstance();
	//get length of combatLog
	int length = combatLog.size();

	if (length - 4 >= 0) {
		display->SetCursorPosition(14, 22);
		std::cout << length - 4 << ":" << combatLog[length - 4];
	}

	if (length - 3 >= 0) {
		display->SetCursorPosition(14, 23);
		std::cout << length - 3 << ":" << combatLog[length - 3];
	}

	if (length - 2 >= 0) {
		display->SetCursorPosition(14, 24);
		std::cout << length - 2 << ":" << combatLog[length - 2];
	}

	if (length - 1 >= 0) {
		display->SetCursorPosition(14, 25);
		std::cout << length - 1 << ":" << combatLog[length - 1];//length would be out of bounds, the element is length -1
	}
}