#include "gameLoop.hpp"

gameLoop::gameLoop()
{

}
gameLoop::~gameLoop()
{

}
void gameLoop::init(const char* title, int xpos, int ypos, int w, int h, bool fullscreen) {
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN; //returns 1 if fullscreen
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "ERROR, INIT FAILED: " << SDL_GetError() << std::endl;
		isRunning = false;
	}
	else {
		gWindow = SDL_CreateWindow("Zombie Game", xpos, ypos, w, h, flags);
		if (gWindow == NULL) {
			std::cout << "ERROR, WINDOW NULL: " << SDL_GetError() << std::endl;
		}
		gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
		if (gRenderer == NULL) {
			std::cout << "ERROR, RENDERER NULL: " << SDL_GetError() << std::endl;
		}
		isRunning = true;
	}
}
void gameLoop::eventHandler() { //each object, for example the player, will need their own event function
	SDL_Event e;
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void gameLoop::close() {
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

void gameLoop::update()
{
	//here we will call the players' update function etc... so basically every object will have an update function
}
void gameLoop::render()
{

}