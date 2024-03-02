#include "header.h"

int loc_gate_day(void) {
	if (h != 2) {
		bg_music("resources/sounds/day_outside.mp3", volume);
		h = 2;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	if (playerTexture == NULL) {
		closeSDL();
		SDL_Quit();
		return 1;
	}
	
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_gate.bmp");
	if (backgroundTexture == NULL) {
		closeSDL();
		SDL_Quit();
		return 1;
	}
	currentBg = 6;
	
	DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr_e.png");

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
	
	FromGateDoorRect.x = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2;
	FromGateDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	FromGateDoorRect.w = DOOR_WIDTH;
	FromGateDoorRect.h = DOOR_HEIGHT;

	int frameWidthDoor = 177;
	int frameHeightDoor = 288;
	for (int i = 0; i < NUM_FRAMES_DOOR; ++i) {
		animationClipsDoor[i].x = i * frameWidthDoor;
		animationClipsDoor[i].y = 0;
		animationClipsDoor[i].w = frameWidthDoor;
		animationClipsDoor[i].h = frameHeightDoor;
	}
	
	backgroundRect.x = - (SCREEN_WIDTH / 2);
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}

