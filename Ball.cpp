#include "Ball.h"
#include "Game.h"

#include <iostream>

Ball::Ball(const Game& game)
{
	//Initialize starting position and size of ball
	m_pos.w = SIZE_WIDTH;
	m_pos.h = SIZE_HEIGHT;

	m_pos.y = (game.getPlayingFieldHeight() / 2) - (m_pos.h / 2);
	m_pos.x = (game.getPlayingFieldWidth() / 2) - (m_pos.w / 2);

	m_dir.dirX = -1; //Set moveDirection of ball to left
	m_movementSpeed = 6;
}

Ball::~Ball()
{
}

void Ball::movement(const Game & game)
{

	//control x axis movement
	switch (m_dir.dirX)
	{
	//Move LEFT
	case -1: m_pos.x -= m_movementSpeed; break;
	//Move Right
	case 1: m_pos.x += m_movementSpeed; break;
	}

	//Control x axis movement
	switch (m_dir.dirY)
	{
	//Move Up
	case -1: m_pos.y -= m_movementSpeed; break;
	//Move Down
	case 1: m_pos.y += m_movementSpeed; break;
	}
}

void Ball::changeDir(const MoveDirection& newDir)
{
	m_dir = newDir;
}

MoveDirection Ball::getReflection(const SDL_Rect& playerPos) const
{
	MoveDirection newDir; //New direction in which ball will move
	int hitPos = (m_pos.y + (m_pos.h / 2)) - playerPos.y;
	const int playerSize = playerPos.h / 2;
	const int offSet = 12;

	//Making sure that the hitYPos is within the area of the paddle
	if (hitPos < 0) {
		hitPos = 0;
	}
	else if (hitPos > playerPos.h) {
		hitPos = playerPos.h;
	}

	//If ball is moving left
	if (m_dir.dirX == -1)
	{
		std::cout << hitPos;
		newDir.dirX = 1; //Change direction to right
		//If ball hits upper part of paddle
		if (hitPos <= (playerSize - offSet)) {
			newDir.dirY = -1; //Change Y direction to up diagonal
		}
		//If ball hits lower part of paddle
		else if (hitPos >= (playerSize + offSet)) {
			newDir.dirY = 1;
		}
		//If ball hits middle part of paddle
		else {
			newDir.dirY = 0;
		}
	}
//
//JmCriat: newDir.dirX *= -1;
//
//	if (hitPos <= playerSize - newDir.dirX * offSet) {
//		newDir.dirY = -1;
//	}
//	else if (hitPos >= playerSize + offSet) {
//		newDir.dirY = 1;
//	}
//	else {
//		newDir.dirY = 0;
//	}
//
	
	//If ball is moving right
	else if (m_dir.dirX == 1)
	{
		newDir.dirX = -1; //Change direction to left

		//If ball its upper part of paddle
		if (hitPos <= playerSize + offSet) {
			newDir.dirY = -1; //Change Y direction to up diagonal
		}

		else if (hitPos >= playerSize + offSet) {
			newDir.dirY = 1;
		}

		else {
			newDir.dirY = 0;
		}
	}
	//MoveDirection result;
	//result.vx = -m_dir.vx;
	//const double hitPos = m_pos.y - player.getPos().y; //Get hit position
	//const double playerSize = player.getPos().h / 2;
	//result.vy = (hitPos > playerSize + 25) - (hitPos < playerSize - 25);
	//return result;
	////Everything above the center of the paddle is reflected upwards.
	////Everything below the centre is reflected downward.
	//hitYPos -= playerPos.h / 2.0f;
	////hitYPos is now: -25. Meaning that it hit the very top of the player paddle
	//float numb = 2.0f;
	//
	////std::cout << numb;
	////return 2.0f * (hity / (paddle[i].height / 2.0f));
	////return 2.0f * (hity / (paddle[i].height / 2.0f));
	//return 2.0f * (hitYPos / (playerPos.h / 2.0f));
	////float GetReflection(int i, float hity) {
	////	// Make sure the hity variable is within the height of the paddle
	////	if (hity < 0) {
	////		hity = 0;
	////	}
	////	else if (hity > paddle[i].height) {
	////		hity = paddle[i].height;
	////	}
	////	// Everything above the center of the paddle is reflected upward
	////	// while everything below the center is reflected downward
	////	hity -= paddle[i].height / 2.0f;
	////	// Scale the reflection, making it fall in the range -2.0f to 2.0f
	////}
	return newDir;
}

bool Ball::collision(const SDL_Rect & player)
{
	//if (m_pos.x <= (pos.x + pos.w))
	//{
	//	if (m_pos.x <= pos.x) {
	//		return false;
	//	}
	//	else
	//	{
	//		if ((m_pos.y + m_pos.h) < pos.y || m_pos.y > (pos.y + pos.h)) {
	//			return false;
	//		}
	//		else
	//		{
	//			m_dir.dirX = 1;
	//			return true;
	//		}
	//	}
	//

	//If collision
	if (m_pos.x + m_pos.w > player .x && m_pos.x < player.x + player.w &&
		m_pos.y + m_pos.h > player.y && m_pos.y < player.y + player.h) {
		return true;
	}

	return false;
}

//bool PaddleCollision(int i) {
//	// Check paddle bounding box against ball bounding box
//	if (ball.x + ball.width > paddle[i].x && ball.x < paddle[i].x + paddle[i].width &&
//		ball.y + ball.height > paddle[i].y && ball.y < paddle[i].y + paddle[i].height) {
//		return true;
//	}
//	return false;
//}





