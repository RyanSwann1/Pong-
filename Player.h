#ifndef PLAYER_H
#define PLAYER_H

#include "MoveDirection.h"
#include <SDL.h>

struct MoveDirection;
class Ball;
class Game;
class Player
{
public:
	Player();
	~Player();

	virtual void movement(const Ball& ball, const Game& game, const MoveDirection& dir) = 0; //Control movement of player
 	virtual SDL_Rect getPos() const = 0; //Get position of player
};
#endif // !PLAYER_H
