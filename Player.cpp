#include "Player.h"

Player::Player() :playerPositionX(Map::GetInstance()->GetMapSizeX() / 2), playerPositionY(Map::GetInstance()->GetMapSizeY() / 2)
{
}

void Player::DoMove()
{
	Input* input = Input::GetInstance();
	int relativePositionX = 0;
	int relativePositionY = 0;
	if (input->GetKeyDown(KeyCode::Arrow_Right))
		relativePositionX = 1;
	else if (input->GetKeyDown(KeyCode::Arrow_Left))
		relativePositionX = -1;
	else if (input->GetKeyDown(KeyCode::Arrow_Up))
		relativePositionY = 1;
	else if (input->GetKeyDown(KeyCode::Arrow_Down))
		relativePositionY = 0;

	if (Map::GetInstance()->IsTileWalkableAt(playerPositionX + relativePositionX, playerPositionY + relativePositionY))
		SetPosition(playerPositionX + relativePositionX, playerPositionY + relativePositionY);
}

void Player::SetPosition(int x, int y)
{
}