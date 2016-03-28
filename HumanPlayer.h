#pragma once
#include "Player.h"

#include <SDL.h>

class Ball;
class Game;
class HumanPlayer :
	public Player
{
public:
	HumanPlayer();
	~HumanPlayer();

	void movement(const Ball& ball, const Game& game, const MoveDirection& dir) override;
	SDL_Rect getPos() const override { return m_pos; } 

private:
	SDL_Rect m_pos; //Position of player
	int m_movementSpeed;
	
	static constexpr int START_X_POS = 50;
	static constexpr int START_Y_POS = 200;
	static constexpr int SIZE_HEIGHT = 75;
	static constexpr int SIZE_WIDTH = 10;
};

