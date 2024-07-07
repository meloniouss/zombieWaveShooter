#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Particle {
	SDL_Renderer* renderer;
public:
	Particle(gameLoop& loop) : renderer(loop.getRenderer()) {}; //we pass the gameLoop object used as an argument in the constructor
	Particle();
	~Particle();

	double x_pos;
	double y_pos;
	double force;
	double mass;

	void handleEvent(SDL_Event& e); //irrelevant
	void Update();
	void Draw();
private:
	SDL_Texture* playerTex; //? unsure
};