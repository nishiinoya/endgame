#include "header.h"

int loc_garden_day(void) {
	if (h != 2) {
		bg_music("resources/sounds/day_outside.mp3", volume);
		h = 2;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	gardenerTexture = loadTexture("resources/textures/sprites/gardener_2fr.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_garden.bmp");
	currentBg = 5;
	
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
	
	FromGardenDoorRect.x = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2;
	FromGardenDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	FromGardenDoorRect.w = DOOR_WIDTH;
	FromGardenDoorRect.h = DOOR_HEIGHT;
	
	gardenerRect.x = SCREEN_WIDTH;
	gardenerRect.y = SCREEN_HEIGHT - ADULT_HEIGHT;
	gardenerRect.w = ADULT_WIDTH;
	gardenerRect.h = ADULT_HEIGHT;

	int frameWidthDoor = 177;
	int frameHeightDoor = 288;
	for (int i = 0; i < NUM_FRAMES_DOOR; ++i) {
		animationClipsDoor[i].x = i * frameWidthDoor;
		animationClipsDoor[i].y = 0;
		animationClipsDoor[i].w = frameWidthDoor;
		animationClipsDoor[i].h = frameHeightDoor;
	}
	
	int frameWidthGardener = 70;
	int frameHeightGardener = 70;
	for (int i = 0; i < NUM_FRAMES_GARDENER; ++i) {
		animationClipsGardener[i].x = i * frameWidthGardener;
		animationClipsGardener[i].y = 0;
		animationClipsGardener[i].w = frameWidthGardener;
		animationClipsGardener[i].h = frameHeightGardener;
	}
	
	backgroundRect.x = -SCREEN_WIDTH;
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}

