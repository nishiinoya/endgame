#include "header.h"

int loc_outdoors_day(void) {
	int DEV = 0;
	if (h != 2) {
		bg_music("resources/sounds/day_outside.mp3", volume);
		h = 2;
	}
	
	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	chelTexture = loadTexture("resources/textures/sprites/chel.png");
	vitalikTexture = loadTexture("resources/textures/sprites/vitalik_8fr.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_outdoors.bmp");
	currentBg = 4;
	
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
	
	if (PREV_LEVEL == 4) DEV = SCREEN_WIDTH / 2 + PLAYER_WIDTH / 2;
	else if (PREV_LEVEL == 5) DEV = SCREEN_WIDTH - PLAYER_WIDTH / 2;
	else DEV = 0;
	
	InDoorRect.x = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2 - DEV;
	InDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	InDoorRect.w = DOOR_WIDTH;
	InDoorRect.h = DOOR_HEIGHT;
	
	ToGardenDoorRect.x = SCREEN_WIDTH - DEV;
	ToGardenDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	ToGardenDoorRect.w = DOOR_WIDTH;
	ToGardenDoorRect.h = DOOR_HEIGHT;
	
	ToGateDoorRect.x = SCREEN_WIDTH + SCREEN_WIDTH / 4 - DEV;
	ToGateDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	ToGateDoorRect.w = DOOR_WIDTH;
	ToGateDoorRect.h = DOOR_HEIGHT;
	
	chelRect.x = -SCREEN_WIDTH / 2 - DEV;
	chelRect.y = SCREEN_HEIGHT - TEEN_HEIGHT;
	chelRect.w = TEEN_WIDTH;
	chelRect.h = TEEN_HEIGHT;
	
	if (MET_VITALIK == 0) vitalikRect.x = SCREEN_WIDTH;
	else vitalikRect.x = -SCREEN_WIDTH;
	vitalikRect.y = SCREEN_HEIGHT - ADULT_HEIGHT;
	vitalikRect.w = ADULT_WIDTH;
	vitalikRect.h = ADULT_HEIGHT;

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
	
	if (PREV_LEVEL == 5) backgroundRect.x = -SCREEN_WIDTH + PLAYER_WIDTH / 2 - DEV;
	else backgroundRect.x = -SCREEN_WIDTH - DEV;
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}

