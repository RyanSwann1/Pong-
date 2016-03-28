#include "ComputerPlayer.h"
#include "Game.h"
#include "Ball.h"


ComputerPlayer::ComputerPlayer()
{
	//Initialize Starting position
	m_pos.x = START_X_POS;
	m_pos.y = START_Y_POS;
	//Intiialize size
	m_pos.w = SIZE_WIDTH;
	m_pos.h = SIZE_HEIGHT;
	//Initialize Movement speed;
	m_movementSpeed = 5;
}


ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::movement(const Ball& ball, const Game& game, const MoveDirection& dir)
{
	if (ball.getPos().x >= (game.getPlayingFieldWidth() / 3)) 
	{
		//If ball is above enemy
		if (ball.getPos().y <= m_pos.y + (m_pos.h / 2)) {

			m_pos.y -= m_movementSpeed;
		}
		//If ball is below enemy
		else if (ball.getPos().y >= m_pos.y + (m_pos.h / 2)) {
			m_pos.y += m_movementSpeed;
		}
	}
}
