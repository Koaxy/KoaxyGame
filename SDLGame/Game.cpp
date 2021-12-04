#include "Game.h"

#include <iostream>


SDL_Texture* PlayerTex;




Game::~Game()
{

}
Game::Game()
{
	

}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initilised." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	SDL_Surface* tmpSurface = IMG_Load("assets/KoaxyAsset.png");
	PlayerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
	{
		isRunning = false;
		break;
	}

	default: 
		break;
	}
}

void Game::update()
{
	//printf("Updated Game..\n");
	//count++;
	//std::cout << count << std::endl;
	int MouseX = 0;
	int MouseZ = 0;
	int res = SDL_GetMouseState(&MouseX, &MouseZ);
	printf("Mouse State: %i\n", res);
}
void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, PlayerTex, NULL, NULL);
	SDL_RenderPresent(renderer);
	// add shit to render lmao
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned up" << std::endl;
}

void Game::movePlayer(int x, int y, int z)
{
	

}