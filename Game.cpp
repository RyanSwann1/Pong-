#include "Game.h"
#include "Window.h"
#include "Player.h"
#include "MoveDirection.h"
#include "Ball.h"

#include <SDL.h>
#include <iostream>

Game::Game(const Window& window)
{
	m_gameOver = false;

	//Intialize size of playing field
	m_playingFieldHeight = window.getScreenHeight();
	m_playingFieldWidth = window.getScreenWidth();
}


Game::~Game()
{
}

void Game::render(const Window & window, const Player & player1, const Player & player2, const Ball& ball)
{
	SDL_RenderClear(window.getRenderer());

	//Render players
	SDL_SetRenderDrawColor(window.getRenderer(), 255, 255, 255, 255);
	SDL_RenderFillRect(window.getRenderer(), &player1.getPos());
	SDL_RenderFillRect(window.getRenderer(), &player2.getPos());

	//Render Ball
	SDL_SetRenderDrawColor(window.getRenderer(), 255, 255, 255, 255);
	SDL_RenderFillRect(window.getRenderer(), &ball.getPos());

	//Render Background
	SDL_SetRenderDrawColor(window.getRenderer(), 0, 0, 0, 0);

	//Apply render
	SDL_RenderPresent(window.getRenderer());
}

void Game::inputManager(const Game& game, Player & player1, const Ball& ball)
{
	const Uint8 *keyState = SDL_GetKeyboardState(nullptr);
	MoveDirection dir;
	
	//Move player upwards
	if (keyState[SDL_SCANCODE_W]) {
		dir.dirY = -1;
		player1.movement(ball, game, dir);
	}
	//Move player downwards
	if (keyState[SDL_SCANCODE_S]) {
		dir.dirY = 1;
		player1.movement(ball, game, dir);
	}
}

void Game::update(const Game & game, Player & player1, Player & player2, Ball & ball)
{
	MoveDirection m_dir;
	//Movements
	ball.movement(game);
	controlBallBounds(ball);
	player2.movement(ball, game, m_dir);
	//Handle collisions
	collisionManagement(player1, player2, ball);
}

void Game::collisionManagement(const Player & player1, const Player & player2, Ball & ball)
{
//	float ballcentery = ball.y + ball.height / 2.0f;
//
//	// Left paddle collisions
//	if (PaddleCollision(0)) {
//		ball.x = paddle[0].x + paddle[0].width;
//		ball.SetDirection(1, GetReflection(0, ballcentery - paddle[0].y));
//	}
	//Ball & Player1 collision
	if (ball.collision(player1.getPos())) {
		ball.changeDir(ball.getReflection(player1.getPos()));
	}
	
	else if (ball.collision(player2.getPos())) {
		ball.changeDir(ball.getReflection(player2.getPos()));
	}
}

void Game::controlBallBounds(Ball& ball)
{
	MoveDirection newDir; //New Direction in which ball will move
	
	//If ball reaches the left wall
	if (ball.getPos().x < (m_playingFieldWidth - m_playingFieldWidth)) 
	{
		//Reverse balls diagonal movement	
		if (ball.getDir().dirY == -1) {
			newDir.dirX = 1;
			newDir.dirY = -1;
		}

		//Reverse balls diagonal movement
		else if (ball.getDir().dirY == 1) {
			newDir.dirX = 1;
			newDir.dirY = 1;
		}

		//Reverse balls x axis movement
		else if (ball.getDir().dirX == -1 && ball.getDir().dirY == 0) {
			newDir.dirX = 1;
			newDir.dirY = 0;
		}
		//Change balls movement direction
		ball.changeDir(newDir);
	}

	//If ball reaches the right wall
	else if ((ball.getPos().x + ball.getPos().w) > m_playingFieldWidth) 
	{
		//Reverse balls diagonal movement
		if (ball.getDir().dirY == -1) {
			newDir.dirY = -1;
			newDir.dirX = -1;
		}
		//Reverse balls diagonal movement
		else if (ball.getDir().dirY == 1) {
			newDir.dirY = 1;
			newDir.dirX = -1;
		}
		//Reverse balls x axis movement
		else if (ball.getDir().dirX == 1) {
			newDir.dirY = 0;
			newDir.dirX = -1;
		}	
		//Change ball movement dir
		ball.changeDir(newDir);
	}

	//If ball reaches the top wall
	else if (ball.getPos().y < (m_playingFieldHeight - m_playingFieldHeight))
	{
		//Reverse balls diagonal movement
		if (ball.getDir().dirX == -1) {
			newDir.dirX = -1;
			newDir.dirY = 1;
		}
		//Reverse balls diagonal movement
		else if (ball.getDir().dirX == 1) {
			newDir.dirX = 1;
			newDir.dirY = 1;
		}
		//Change balls movement direction
		ball.changeDir(newDir);
	}

	//if ball reaches the bottom wall
	else if (ball.getPos().y + ball.getPos().h > m_playingFieldHeight) 
	{
		//Reverse balls diagonal movement
		if (ball.getDir().dirX == -1) {
			newDir.dirX = -1;
			newDir.dirY = -1;
		}

		//Reverse balld diagonal movement 
		if (ball.getDir().dirX == 1) {
			newDir.dirX = 1;
			newDir.dirY = -1;
		}
		//Change balls movement direction
		ball.changeDir(newDir);
	}
}
