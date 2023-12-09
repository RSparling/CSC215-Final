#include "Player.h"

Player* Player::instance = nullptr;

Player::Player(int startingPositionX, int startingPositionY) : positionX(startingPositionX), positionY(startingPositionY)
{
	// Link player coordinates to the map
	Map::GetInstance()->LinkPlayerCoords(&positionX, &positionY);
	// Set the viewport centered on the player's position
	Map::GetInstance()->SetViewportCenteredOnPosition(positionX, positionY);
	// Get the the base creature class
	Creature* creature = dynamic_cast<Creature*>(this);

	if (creature == nullptr)//should not be null under any instance
		return;

	// Set the creature's health and mana
	creature->SetHealth(50);
	creature->SetMana(10);
}

void Player::DoMove()
{
	Input* input = Input::GetInstance();
	Map* map = Map::GetInstance();
	int relativePositionX = 0;
	int relativePositionY = 0;
	// Check if the right arrow key is pressed
	if (input->GetKeyDown(KeyCode::Arrow_Right))
		relativePositionX = 1;
	// Check if the left arrow key is pressed
	else if (input->GetKeyDown(KeyCode::Arrow_Left))
		relativePositionX = -1;
	// Check if the up arrow key is pressed
	else if (input->GetKeyDown(KeyCode::Arrow_Up))
		relativePositionY = -1; // Y neg is up
	// Check if the down arrow key is pressed
	else if (input->GetKeyDown(KeyCode::Arrow_Down))
		relativePositionY = 1; // Y positive is down

	// Check if the new position is within the map bounds and the tile is walkable
	if (map->isInMapBounds(positionX + relativePositionX, positionY + relativePositionY) && map->IsTileWalkableAt(positionX + relativePositionX, positionY + relativePositionY))
		SetPosition(positionX + relativePositionX, positionY + relativePositionY);
	std::cout << std::endl << std::endl << "X: " << positionX << " , " << "Y: " << positionY << "    ";
}

void Player::SetPosition(int x = 5, int y = 5)
{
	positionX = x;
	positionY = y;
	// Set the viewport centered on the new position
	Map::GetInstance()->SetViewportCenteredOnPosition(positionX, positionY);
}