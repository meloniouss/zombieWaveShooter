/*This source code copyrighted by Lazy Foo' Productions 2w004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init() { //for initializing the window
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError();
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("Zombie Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (gWindow == NULL) {
			printf("Window could not be created! Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow); //this grabs the surface contained by the window we've created (interior basically)
		}
	}
	return success;
}

bool loadMedia() { //for loading something to the window, in this case we are using the gHelloWorld global variable
	bool success = true;

	gHelloWorld = SDL_LoadBMP("");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image");
		success = false;
	}
	return success;
}

void close() {
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL; //not necessary, just good practice once you dereference
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

bool quit = false;
SDL_Event e;
int main(int argc, char* args[])
{
	while (!quit) {
		if (SDL_PollEvent(&e) != 0) //0 if no pending events, 1 if event is pending
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}

		SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
		//Update the surface
		SDL_UpdateWindowSurface(gWindow)
	}

	close();
	return 0;
}

