#include "Particle.hpp"
#include "gameLoop.hpp"
#include "TextureLoader.hpp"



Particle::Particle() {
	playerTex = TextureLoader::LoadTexture("assets/player.png", renderer);
}
Particle::~Particle() {}

void Particle::handleEvent(SDL_Event& e) {

}
void Particle::Update() {

}

void Particle::Draw() {

}