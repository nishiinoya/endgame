#include "header.h"

int loc_gate_night(void) {
	if (h != 4) {
		bg_music("resources/sounds/spooky_outside.mp3", volume);
		h = 4;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_gate_night.bmp");
	currentBg = 8;

	// Initialize player position
	playerRect.x = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2;
	playerRect.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	playerRect.w = PLAYER_WIDTH;
	playerRect.h = PLAYER_HEIGHT;
	
	int frameWidthPlayer = 60;
	int frameHeightPlayer = 60;
	for (int i = 0; i < NUM_FRAMES_PLAYER; ++i) {
		animationClipsPlayer[i].x = i * frameWidthPlayer;
		animationClipsPlayer[i].y = 0;
		animationClipsPlayer[i].w = frameWidthPlayer;
		animationClipsPlayer[i].h = frameHeightPlayer;
	}
	
	backgroundRect.x = -SCREEN_WIDTH;
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}

