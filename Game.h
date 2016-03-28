#ifndef GAME_H
#define GAME_H

struct MoveDirection;
class Ball;
class Player;
class Window;
class Game
{
public:
	Game(const Window& window);
	~Game();

	bool iGameOver() const { return m_gameOver; }

	void render(const Window& window, const Player& player1, const Player& player2, const Ball& ball);
	void inputManager(const Game& game, Player& player1, const Ball& ball);
	void update(const Game& game, Player& player1, Player& player2, Ball& ball);
	void collisionManagement(const Player& player1, const Player& player2, Ball& ball);
	void endGame() { m_gameOver = true; }



	//Getters
	int getPlayingFieldHeight() const { return m_playingFieldHeight; }
	int getPlayingFieldWidth() const { return m_playingFieldWidth; }
	

private:
	bool m_gameOver;
	void controlBallBounds(Ball& ball);

	int m_playingFieldWidth;
	int m_playingFieldHeight;
};

#endif // !GAME_H