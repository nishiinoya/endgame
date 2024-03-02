#include "header.h"

int LEVEL = 0;
int PREV_LEVEL = 0;
int currentBg = 0;

int main(void) {
	if (!initializeSDL()) {
        return 1;
    }

    Resolution resolutions[NUM_RESOLUTIONS];
	arrinit(resolutions);

	int resol_count = 4;

	adapUI(resol_count, resolutions);

	if (resol_count == 0)
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}
	
	showmenu();
	
	closeSDL();
	return 0;
}

