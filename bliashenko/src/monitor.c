#include "header.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int PLAYER_WIDTH = 200;
int PLAYER_HEIGHT = 200;
int ADULT_WIDTH = 225;
int ADULT_HEIGHT = 250;
int TEEN_WIDTH = 200;
int TEEN_HEIGHT = 200;

int DOOR_WIDTH = 225;
int DOOR_HEIGHT = 320;
int BG_WIDTH = 2400;

int PLAYER_SPEED = 7;
int VITALIK_SPEED = 5;

double proportion_w;
double proportion_h;

void arrinit(Resolution resolutions[]) 
{
    resolutions[0].width = 1920;
    resolutions[0].height = 1080;

    resolutions[1].width = 1366;
    resolutions[1].height = 768;

    resolutions[2].width = 1280;
    resolutions[2].height = 768;

    resolutions[3].width = 1280;
    resolutions[3].height = 720;

    resolutions[4].width = 800;
    resolutions[4].height = 600;
}

void adapUI(int position, Resolution arr[NUM_RESOLUTIONS])
{
	proportion_w = arr[position].width / 800;
	proportion_h = arr[position].height / 600;
	
	SCREEN_WIDTH = arr[position].width;
	SCREEN_HEIGHT = arr[position].height;
	
	/*PLAYER_WIDTH = 200 * (arr[position].width / 800);
	PLAYER_HEIGHT = 200 * (arr[position].height / 600);
	DOOR_WIDTH = 200 * (arr[position].width / 800);
	DOOR_HEIGHT = 200 * (arr[position].height / 600);
	BG_WIDTH = 2200 * (arr[position].width / 800);
	PLAYER_SPEED = 10 * (arr[position].width / 800);*/
	
	PLAYER_WIDTH = 200 * proportion_w;
	PLAYER_HEIGHT = 200 * proportion_h;
	ADULT_WIDTH = 225 * proportion_w;
	ADULT_HEIGHT = 250 * proportion_h;
	TEEN_WIDTH = 200 * proportion_w;
	TEEN_HEIGHT = 200 * proportion_h;
	
	DOOR_WIDTH = 225 * proportion_w;
	DOOR_HEIGHT = 320 * proportion_h;
	BG_WIDTH = 2200 * proportion_w;
	PLAYER_SPEED = 7 * proportion_w;
	VITALIK_SPEED = 5 * proportion_w;
	
	SDL_SetWindowSize(window, arr[position].width, arr[position].height);
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

