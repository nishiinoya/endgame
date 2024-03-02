#include "header.h"

void sound_play(char *href, int volume) 
{
	sound = Mix_LoadWAV(href);

	if (sound == NULL) {
		printf("Failed to load sound! SDL_mixer Error: %s\n", Mix_GetError());
	} else {
		Mix_VolumeChunk(sound, volume);
		// Воспроизведение звука
		Mix_PlayChannel(-1, sound, 0);
	}
}

