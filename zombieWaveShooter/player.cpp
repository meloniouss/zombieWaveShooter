#include "player.hpp"
#include "gameLoop.hpp"
#include "TextureLoader.hpp"



Player::Player() {
	playerTex = TextureLoader::LoadTexture("assets/player.png", renderer);
}
Player::~Player() {}

void Player::handleEvent(SDL_Event& e) {

}
void Player::Update() {

}

void Player::Draw() {

}