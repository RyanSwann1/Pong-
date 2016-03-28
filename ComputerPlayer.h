#pragma once
#include "Player.h"
class Ball;
class ComputerPlayer :
	public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();


	void movement(const Ball& ball, const Game& game, const MoveDirection& dir) override;
	SDL_Rect getPos() const { return m_pos; }

private:
	SDL_Rect m_pos; //Position of player
	int m_movementSpeed;

	static constexpr int START_X_POS = 750;
	static constexpr int START_Y_POS = 200;
	static constexpr int SIZE_HEIGHT = 75;
	static constexpr int SIZE_WIDTH = 10;
};

