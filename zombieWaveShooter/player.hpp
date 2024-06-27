#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Player {
public:
	Player();
	~Player();
	void handleEvent(SDL_Event& e);
	void Update();
	void Draw();
	SDL_Texture* playerTex;
};