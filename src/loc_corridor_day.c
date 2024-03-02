#include "header.h"

int loc_corridor_day(void) {
	int DEV = 0;
	if (h != 1) {
		bg_music("resources/sounds/day.mp3", volume);
		h = 1;
	}

	// Load player texture
	playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
	teacherTexture = loadTexture("resources/textures/sprites/teacher_8fr.png");
	hlopetsTexture = loadTexture("resources/textures/sprites/hlopets_2fr.png");
	backgroundTexture = loadTexture("resources/textures/backgrounds/bg_corridor.bmp");
	currentBg = 2;
	
	DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");

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
	
	if (PREV_LEVEL == 2) DEV = SCREEN_WIDTH / 2 + PLAYER_WIDTH / 2;
	else if (PREV_LEVEL == 3) DEV = SCREEN_WIDTH - PLAYER_WIDTH / 2;
	else DEV = 0;
	
	hlopetsRect.x = -SCREEN_WIDTH / 2 - DEV;
	hlopetsRect.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	hlopetsRect.w = TEEN_WIDTH;
	hlopetsRect.h = TEEN_HEIGHT;
	
	teacherRect.x = SCREEN_WIDTH - PLAYER_WIDTH / 2 - DEV;
	teacherRect.y = SCREEN_HEIGHT - ADULT_HEIGHT;
	teacherRect.w = ADULT_WIDTH;
	teacherRect.h = ADULT_HEIGHT;
	
	CorrRoomDoorRect.x = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2 - DEV;
	CorrRoomDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	CorrRoomDoorRect.w = DOOR_WIDTH;
	CorrRoomDoorRect.h = DOOR_HEIGHT;
	
	MessDoorRect.x = SCREEN_WIDTH - DEV;
	MessDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	MessDoorRect.w = DOOR_WIDTH;
	MessDoorRect.h = DOOR_HEIGHT;
	
	OutDoorRect.x = SCREEN_WIDTH + SCREEN_WIDTH / 4 - DEV;
	OutDoorRect.y = SCREEN_HEIGHT - DOOR_HEIGHT;
	OutDoorRect.w = DOOR_WIDTH;
	OutDoorRect.h = DOOR_HEIGHT;

	int frameWidthDoor = 177;
	int frameHeightDoor = 288;
	for (int i = 0; i < NUM_FRAMES_DOOR; ++i) {
		animationClipsDoor[i].x = i * frameWidthDoor;
		animationClipsDoor[i].y = 0;
		animationClipsDoor[i].w = frameWidthDoor;
		animationClipsDoor[i].h = frameHeightDoor;
	}
	
	int frameWidthTeacher = 70;
	int frameHeightTeacher = 70;
	for (int i = 0; i < NUM_FRAMES_TEACHER; ++i) {
		animationClipsTeacher[i].x = i * frameWidthTeacher;
		animationClipsTeacher[i].y = 0;
		animationClipsTeacher[i].w = frameWidthTeacher;
		animationClipsTeacher[i].h = frameHeightTeacher;
	}
	
	int frameWidthHlopets = 60;
	int frameHeightHlopets = 60;
	for (int i = 0; i < NUM_FRAMES_HLOPETS; ++i) {
		animationClipsHlopets[i].x = i * frameWidthHlopets;
		animationClipsHlopets[i].y = 0;
		animationClipsHlopets[i].w = frameWidthHlopets;
		animationClipsHlopets[i].h = frameHeightHlopets;
	}
	
	if (PREV_LEVEL == 3) backgroundRect.x = -SCREEN_WIDTH + PLAYER_WIDTH / 2 - DEV;
	else backgroundRect.x = -SCREEN_WIDTH - DEV;
	backgroundRect.y = 0;
	backgroundRect.w = BG_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;

	handleInput();
		
	closeSDL();
	return 0;
}

