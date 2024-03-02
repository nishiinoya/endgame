#include "header.h"

int loc_room_day(void) {
	int DEV = 0;
	if (h != 1) {
		bg_music("resources/sounds/day.mp3", volume);
		h = 1;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg.bmp");
	currentBg = 1;
	
	DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
	
	bedTexture = loadTexture("resources/textures/sprites/bed.png");
	
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
	
	if (PREV_LEVEL == 1) DEV = SCREEN_WIDTH / 2 + PLAYER_WIDTH / 2;
	else DEV = 0;
	
	RoomDoorRect.x = SCREEN_WIDTH - DEV;
	RoomDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	RoomDoorRect.w = DOOR_WIDTH;
	RoomDoorRect.h = DOOR_HEIGHT;
	
	bedRect.x = -SCREEN_WIDTH / 2 - DEV;
	bedRect.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	bedRect.w = PLAYER_WIDTH * 2;
	bedRect.h = PLAYER_HEIGHT;

	int frameWidthDoor = 177;
	int frameHeightDoor = 288;
	for (int i = 0; i < NUM_FRAMES_DOOR; ++i) {
		animationClipsDoor[i].x = i * frameWidthDoor;
		animationClipsDoor[i].y = 0;
		animationClipsDoor[i].w = frameWidthDoor;
		animationClipsDoor[i].h = frameHeightDoor;
	}
	
	backgroundRect.x = -SCREEN_WIDTH - DEV;
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}

