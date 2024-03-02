#include "header.h"

int loc_outdoors_night(void) {
	if (h != 3) {
		bg_music("resources/sounds/bessonitsa_outside.mp3", volume);
		h = 3;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	vitalikTexture = loadTexture("resources/textures/sprites/vitalik_8fr.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_outdoors_night.bmp");
	currentBg = 7;
	
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
	
	vitalikRect.x = SCREEN_WIDTH;
	vitalikRect.y = SCREEN_HEIGHT - ADULT_HEIGHT;
	vitalikRect.w = ADULT_WIDTH;
	vitalikRect.h = ADULT_HEIGHT;
	
	NightGateDoorRect.x = SCREEN_WIDTH;
	NightGateDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	NightGateDoorRect.w = DOOR_WIDTH;
	NightGateDoorRect.h = DOOR_HEIGHT;

	int frameWidthDoor = 177;
	int frameHeightDoor = 288;
	for (int i = 0; i < NUM_FRAMES_DOOR; ++i) {
		animationClipsDoor[i].x = i * frameWidthDoor;
		animationClipsDoor[i].y = 0;
		animationClipsDoor[i].w = frameWidthDoor;
		animationClipsDoor[i].h = frameHeightDoor;
	}
	
	int frameWidthVitalik = 60;
	int frameHeightVitalik = 69;
	for (int i = 0; i < NUM_FRAMES_VITALIK; ++i) {
		animationClipsVitalik[i].x = i * frameWidthVitalik;
		animationClipsVitalik[i].y = 0;
		animationClipsVitalik[i].w = frameWidthVitalik;
		animationClipsVitalik[i].h = frameHeightVitalik;
	}
	
	backgroundRect.x = -SCREEN_WIDTH;
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH * 2;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}
