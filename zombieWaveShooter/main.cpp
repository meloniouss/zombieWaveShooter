#include "gameLoop.hpp";
//undef main -> only if the main function doesnt work for some reason
gameLoop* game = nullptr;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
	game = new gameLoop();
	game->init("GRAVITY SIM", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0); 
	while (game->running()) 
	{
		game->eventHandler();
		game->update();
		game->render();
	}
	game->close();
	return 0;
}