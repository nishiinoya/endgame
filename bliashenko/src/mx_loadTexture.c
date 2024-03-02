#include "header.h"

SDL_Texture* loadTexture(const char* path) 
{
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
		return NULL;
	}

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

