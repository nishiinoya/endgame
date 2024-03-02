#include "header.h"

int h = -1;
void bg_music(char *href, double volume)
{
    Mix_HaltMusic();

    // Выгрузка текущей музыки, если она загружена
    if (backgroundMusic) {
        Mix_FreeMusic(backgroundMusic);
        backgroundMusic = NULL;
    }

    backgroundMusic = Mix_LoadMUS(href);
    if (backgroundMusic == NULL) {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        //return 1;
    }
    Mix_VolumeMusic(round(128 * volume));
    // Воспроизведение музыки на фоне
    Mix_PlayMusic(backgroundMusic, -1);
}

