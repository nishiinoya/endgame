#pragma once

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "animation.h"

#define NUM_RESOLUTIONS 5
#define NUM_FRAMES_PLAYER 8
#define NUM_FRAMES_VITALIK 8
#define NUM_FRAMES_TEACHER 8
#define NUM_FRAMES_GARDENER 2
#define NUM_FRAMES_HLOPETS 2
#define NUM_FRAMES_DOOR 2
#define FRAME_DELAY 10
#define FRAME_DELAY_SLOWER 200

extern bool All_dialog;
extern int LEVEL;
extern int PREV_LEVEL;

extern int MET_VITALIK;
extern int MET_HLOPETS;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int PLAYER_WIDTH;
extern int PLAYER_HEIGHT;

extern int ADULT_WIDTH;
extern int ADULT_HEIGHT;
extern int TEEN_WIDTH;
extern int TEEN_HEIGHT;

extern int PLAYER_SPEED;
extern int VITALIK_SPEED;

extern int DOOR_WIDTH;
extern int DOOR_HEIGHT;

extern int BG_WIDTH;

extern int currentBg;

extern double volume;
extern int h;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern SDL_Rect backgroundRect;

extern SDL_Rect RoomDoorRect;
extern SDL_Rect CorrRoomDoorRect;
extern SDL_Rect MessDoorRect;
extern SDL_Rect OutDoorRect;
extern SDL_Rect CorrDoorRect;
extern SDL_Rect InDoorRect;
extern SDL_Rect ToGardenDoorRect;
extern SDL_Rect FromGardenDoorRect;
extern SDL_Rect ToGateDoorRect;
extern SDL_Rect FromGateDoorRect;
extern SDL_Rect NightGateDoorRect;
extern SDL_Rect Text_Rect;

extern SDL_Rect bedRect;

extern SDL_Rect playerRect;
extern SDL_Rect gardenerRect;
extern SDL_Rect teacherRect;
extern SDL_Rect vitalikRect;
extern SDL_Rect chelRect;
extern SDL_Rect chelkaRect;
extern SDL_Rect hlopetsRect;

extern SDL_Texture* gardenerTexture;
extern SDL_Texture* teacherTexture;
extern SDL_Texture* vitalikTexture;
extern SDL_Texture* chelTexture;
extern SDL_Texture* chelkaTexture;
extern SDL_Texture* hlopetsTexture;

extern SDL_Texture* backgroundTexture;
extern SDL_Texture* DoorTexture;
extern SDL_Texture* bedTexture;
extern SDL_Texture* playerTexture;

extern Mix_Chunk* sound;
extern Mix_Music* backgroundMusic;

extern TTF_Font* gFont;
extern SDL_Texture *TextTexture;
extern SDL_Surface *TextSurface;

extern FILE *file;
extern long fileSize;
extern char *buffer;
extern int arr[9];

typedef struct {
    int width;
    int height;
} Resolution;

typedef struct {
    SDL_Texture* texture;
    int width;
    int height;
} LTexture;

//SDL_Texture* blackoutTexture;
SDL_Texture* loadTexture(const char* path);

int initializeSDL(void);
void arrinit(Resolution resolutions[]);
void adapUI(int position, Resolution arr[NUM_RESOLUTIONS]);
void closeSDL(void);
void render(void);
void sound_play(char *href, int volume);
void bg_music(char *href, double volume);
void handleInput(void);
bool isMouseOver(SDL_Rect* rect, int mouseX, int mouseY);
int showmenu(void);
int intermenu(void);
int settings(void);
int help_screen(void);
int loadGame(void);
int loc_room_day(void);
int loc_corridor_day(void);
int loc_messhall_day(void);
int loc_outdoors_day(void);
int loc_garden_day(void);
int loc_gate_day(void);
int loc_outdoors_night(void);
int loc_gate_night(void);

int flag_read(int level);
int is_flag(int flag);

FILE *ofile(char* path);
void loadText(char* href);
char *textbuf(FILE *txt);
void sentenceout(char* buf);

