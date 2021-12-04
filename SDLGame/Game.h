#pragma once

#include <Windows.h>

#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();
	void movePlayer(int x, int y, int z);
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };
private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

