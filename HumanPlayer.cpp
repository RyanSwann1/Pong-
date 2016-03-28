#include "HumanPlayer.h"
#include "Game.h"


HumanPlayer::HumanPlayer()
{
	//Initilaze movementSpeed
	m_movementSpeed = 6;
	
	//Initialize starting position
	m_pos.x = START_X_POS;
	m_pos.y = START_Y_POS;
	//Initialize size
	m_pos.h = SIZE_HEIGHT;
	m_pos.w = SIZE_WIDTH;
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::movement(const Ball& ball, const Game & game, const MoveDirection& dir)
{
	switch (dir.dirY)
	{
		//Move up
	case -1: 
	{
		//If position has not exceeded bounds
		if (m_pos.y >= (game.getPlayingFieldHeight() - game.getPlayingFieldHeight())) {
			m_pos.y -= m_movementSpeed;
			break;
		}
	}
	//Move Down
	case 1:
	{
		//If position has not exceeded bounds
		if (m_pos.y <= (game.getPlayingFieldHeight() - m_pos.h)) {
			m_pos.y += m_movementSpeed;
			break;
		}
	}
	}
}
