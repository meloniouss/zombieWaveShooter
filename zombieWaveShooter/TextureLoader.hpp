#pragma once
#include "gameLoop.hpp"
class TextureLoader {
public:
	static SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);
};