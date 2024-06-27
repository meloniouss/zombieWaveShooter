#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class gameLoop {
public:
	gameLoop();
	~gameLoop();
	void init(const char* title, int x, int y, int w, int h, bool fullscreen);
	void eventHandler();
	void update();
	void render();
	void close();
	bool running() { return isRunning; };
private:
	bool isRunning;
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
};