#include "header.h"

void closeSDL(void) {
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(DoorTexture);
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	exit(0);
}

