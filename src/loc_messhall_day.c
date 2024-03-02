#include "header.h"

int loc_messhall_day(void) {
	if (h != 1) {
		bg_music("resources/sounds/day.mp3", volume);
		h = 1;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	chelkaTexture = loadTexture("resources/textures/sprites/chelka.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_messhall.bmp");
	currentBg = 3;
	
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
	
	CorrDoorRect.x = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2;
	CorrDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	CorrDoorRect.w = DOOR_WIDTH;
	CorrDoorRect.h = DOOR_HEIGHT;
	
	chelkaRect.x = SCREEN_WIDTH - PLAYER_WIDTH / 2;
	chelkaRect.y = SCREEN_HEIGHT - TEEN_HEIGHT;
	chelkaRect.w = TEEN_WIDTH;
	chelkaRect.h = TEEN_HEIGHT;

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

