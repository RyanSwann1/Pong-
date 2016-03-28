#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Game.h"
#include "Window.h"
#include "Ball.h"
#include <SDL.h>
#include <memory>

//http://answers.unity3d.com/questions/52881/vector-normalization-question.html		
//http://forum.unity3d.com/threads/what-is-vector3-normalize.164135/
//http://rembound.com/articles/the-pong-tutorial

//http://codereview.stackexchange.com/questions/42823/pong-game-using-sdl-2-0
//http://codereview.stackexchange.com/questions/42823/pong-game-using-sdl-2-0
//http://rembound.com/articles/the-pong-tutorial
//http://codereview.stackexchange.com/questions/46414/pong-game-written-in-c-and-using-sdl-2-0-part-2
//http://www.16software.com/blog/getting-your-feet-wet-in-sdl-part-2-the-pong-clone
//http://www.aaroncox.net/tutorials/arcade/PaddleBattle.html
//https://github.com/chaficnajjar/21st-century-pong/tree/master/src

int main(int argc, char* args[])
{
	Window window(800, 400);
	Game game(window);
	SDL_Event e;
	//Initialization of players
	std::unique_ptr<Player> player1(new HumanPlayer);
    std::unique_ptr<Player> player2(new ComputerPlayer);
	Ball ball(game);



	//Game loop
	while (!game.iGameOver())
	{
		//Listen for events
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) {
				game.endGame();
			}
		}

		game.inputManager(game, *player1, ball);
		game.update(game, *player1, *player2, ball);
		game.render(window, *player1, *player2, ball);
	}

	return 0;
}