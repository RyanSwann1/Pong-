#ifndef BALL_H
#define BALL_H

#include "MoveDirection.h"
#include <SDL.h>
struct MoveDirection;
class Game;
class Ball
{
public:
	Ball(const Game& game);
	~Ball();

	void movement(const Game& game);
	void changeDir(const MoveDirection& newDir);

	bool collision(const SDL_Rect& player);

	//Getters
	MoveDirection getReflection(const SDL_Rect& playerPos) const;
	SDL_Rect getPos() const { return m_pos; } //Get position of ball
	MoveDirection getDir() const { return m_dir; } //Get direction of ball

private:
	SDL_Rect m_pos; //Position of ball
	MoveDirection m_dir;
	int m_movementSpeed; //movement speed of ball

	static constexpr int SIZE_HEIGHT = 10;
	static constexpr int SIZE_WIDTH = 10;
};

#endif // !BALL_H