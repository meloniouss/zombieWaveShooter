#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Player {
	SDL_Renderer* renderer;
public:
	Player(gameLoop& loop) : renderer(loop.getRenderer()) {}; //we pass the gameLoop object used as an argument in the constructor
	Player();
	~Player();
	void handleEvent(SDL_Event& e);
	void Update();
	void Draw();
private:
	SDL_Texture* playerTex; //? unsure
};