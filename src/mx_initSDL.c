#include "header.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* playerTexture = NULL;
SDL_Texture* gardenerTexture = NULL;
SDL_Texture* teacherTexture = NULL;
SDL_Texture* vitalikTexture = NULL;
SDL_Texture* chelTexture = NULL;
SDL_Texture* chelkaTexture = NULL;
SDL_Texture* hlopetsTexture = NULL;

SDL_Texture* DoorTexture = NULL;
SDL_Texture* bedTexture = NULL;

SDL_Rect playerRect;
SDL_Rect gardenerRect;
SDL_Rect teacherRect;
SDL_Rect vitalikRect;
SDL_Rect chelRect;
SDL_Rect chelkaRect;
SDL_Rect hlopetsRect;
SDL_Rect Text_Rect;

SDL_Rect bedRect;

//https://www.youtube.com/watch?v=cVxWzNQlcxo
SDL_Rect RoomDoorRect;
SDL_Rect CorrRoomDoorRect;
SDL_Rect MessDoorRect;
SDL_Rect OutDoorRect;
SDL_Rect CorrDoorRect;
SDL_Rect InDoorRect;
SDL_Rect ToGardenDoorRect;
SDL_Rect FromGardenDoorRect;
SDL_Rect ToGateDoorRect;
SDL_Rect FromGateDoorRect;
SDL_Rect NightGateDoorRect;

SDL_Rect animationClipsPlayer[NUM_FRAMES_PLAYER];
SDL_Rect animationClipsDoor[NUM_FRAMES_DOOR];
SDL_Rect animationClipsVitalik[NUM_FRAMES_VITALIK];
SDL_Rect animationClipsGardener[NUM_FRAMES_GARDENER];
SDL_Rect animationClipsTeacher[NUM_FRAMES_TEACHER];
SDL_Rect animationClipsHlopets[NUM_FRAMES_HLOPETS];

SDL_Rect backgroundRect;
SDL_Texture* backgroundTexture = NULL;

TTF_Font* gFont = NULL;
SDL_Surface *TextSurface = NULL;
SDL_Texture *TextTexture = NULL;

char *buffer = NULL;
long fileSize = 0;

int arr[9] = {0,0,0,0,0,0,0,0,0};

int flag_read(int level)
{
	arr[level] = 1;
	return arr[level];
}

int is_flag(int flag)
{
	return arr[flag];
}

void loadText(char* href) {

	//if (TTF_Init() != 0) {
	//	printf("SDL_ttf initialization failed: %s\n", TTF_GetError());
	//	SDL_Quit();
	//	//return 0;
	//}

	//if (TTF_Init() == -1) {
	//	printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	//	//return 0;
	//}

	gFont = TTF_OpenFont("resources/fonts/ToThePointRegular.ttf", 28);
	if (gFont == NULL) {
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		//return 0;
	}

	FILE* cup = ofile(href);

	buffer = textbuf(cup);

	fclose(cup);

	sentenceout(buffer);
}

int initializeSDL() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return 0;
	}

	window = SDL_CreateWindow("Hidden Fears", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return 0;
	}
	if (TTF_Init() != 0) {
		printf("SDL_ttf initialization failed: %s\n", TTF_GetError());
		SDL_Quit();
		//return 0;
	}

	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		//return 0;
	}
	return 1;
}

