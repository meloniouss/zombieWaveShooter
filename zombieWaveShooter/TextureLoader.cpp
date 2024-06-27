#include "TextureLoader.hpp"

SDL_Texture* TextureLoader::LoadTexture(const char* tex, SDL_Renderer* ren) {
	SDL_Surface* tmp = IMG_Load(tex);
	SDL_Texture* newTex = SDL_CreateTextureFromSurface(ren, tmp);
	SDL_FreeSurface(tmp);
	return newTex;
}