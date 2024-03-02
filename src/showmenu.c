#include "header.h"

Mix_Chunk* sound = NULL;
Mix_Music* backgroundMusic = NULL;

int showmenu() {
	if (h != 0) {
		bg_music("resources/sounds/mainmenu.mp3", 1);
		h = 0;
	}
	
	int x, y;
	int NUMMENU = 5;
	SDL_Texture* button[5];
	SDL_Rect pos[5];
	bool selected[5] = {0, 0, 0, 0, 0};
	char* unclickpath[] = {"resources/textures/buttons/menu/purple/new_game_button.png", "resources/textures/buttons/menu/purple/loadgame_button.png", "resources/textures/buttons/menu/purple/settings_button.png", "resources/textures/buttons/menu/purple/help_button.png", "resources/textures/buttons/menu/purple/exit_button.png"};
	char* clickpath[] = {"resources/textures/buttons/menu/grey/new_game_button.png", "resources/textures/buttons/menu/grey/loadgame_button.png", "resources/textures/buttons/menu/grey/settings_button.png", "resources/textures/buttons/menu/grey/help_button.png", "resources/textures/buttons/menu/grey/exit_button.png"};
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	backgroundTexture = loadTexture("resources/textures/backgrounds/start_background.png");
	currentBg = 0;
	backgroundRect.x = 0;
	backgroundRect.y = 0;
	backgroundRect.w = SCREEN_WIDTH;
	backgroundRect.h = SCREEN_HEIGHT;
	
	for (int i = 0; i < NUMMENU; i++) {
		button[i] = loadTexture(unclickpath[i]);
		pos[i].h = 2 * (SCREEN_HEIGHT / 4) / NUMMENU;
		pos[i].w = 536 * pos[i].h / 200;
		pos[i].x = SCREEN_WIDTH / 2 - pos[i].w / 2;
		if (i == 0) {
			pos[i].y = SCREEN_HEIGHT / 3 - pos[i].h / 2;
		}
		else {
			pos[i].y = pos[i - 1].y + 5 * pos[i - 1].h / 4;
		}
	}
	
	SDL_Event event;
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				SDL_RenderClear(renderer);
				return 1;
			case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;
				for (int i = 0; i < NUMMENU; i += 1) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
					{
						if (!selected[i])
						{
							selected[i] = 1;
							SDL_RenderClear(renderer);
							SDL_DestroyTexture(button[i]);
							button[i] = loadTexture(clickpath[i]);
						}
					}
					else
					{
						if (selected[i])
						{
							selected[i] = 0;
							SDL_RenderClear(renderer);
							SDL_DestroyTexture(button[i]);
							button[i] = loadTexture(unclickpath[i]);
						}
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x;
				y = event.button.y;
				for (int i = 0; i < NUMMENU; i += 1) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
					{
						for (int i = 0; i < NUMMENU; i += 1) {
							SDL_DestroyTexture(button[i]);
						}
						//SDL_DestroyTexture(backgroundTexture);
						SDL_RenderClear(renderer);
						switch (i) {
						case 0:
							SDL_DestroyTexture(backgroundTexture);
							loc_room_day();
							break;
						case 1:
							loadGame();
							for (int i = 0; i < NUMMENU; i++) {
								button[i] = loadTexture(unclickpath[i]);
							}
							break;
						case 2:
							settings();
							for (int i = 0; i < NUMMENU; i++) {
								button[i] = loadTexture(unclickpath[i]);
							}
							break;
						case 3:
							//if (help_screen() == 1) {
								//showmenu();
							//} 
							help_screen();

							for (int i = 0; i < NUMMENU; i++) {
								button[i] = loadTexture(unclickpath[i]);
							}
							//SDL_Delay(16);
							break;
						case 4:
							closeSDL();
							break;
						}
					}
				}
				break;
			}
		}
		SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
		for (int i = 0; i < NUMMENU; i += 1) {
			SDL_RenderCopy(renderer, button[i], NULL, &pos[i]);
		}
		SDL_RenderPresent(renderer);
	}
	
	closeSDL();
	//return 0;
}

