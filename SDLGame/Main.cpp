#include "Game.h"

namespace WindowSize
{
	int screen_width = 1280;
	int screen_height = 720;
}


Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	game->init("Koaxy's Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowSize::screen_width, WindowSize::screen_height, false);

	while (game->running())
	{
		
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}