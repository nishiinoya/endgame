#include "header.h"

int intermenu(void) {
	Uint32 time;
	int NUMMENU = 5;
	int x, y;
	SDL_Texture* button[5];
	SDL_Rect pos[5];
	bool selected[5] = { 0, 0, 0, 0, 0 };
	char* unclickpath[] = {"resources/textures/buttons/menu/purple/new_game_button.png", "resources/textures/buttons/menu/purple/loadgame_button.png", "resources/textures/buttons/menu/purple/settings_button.png", "resources/textures/buttons/menu/purple/help_button.png", "resources/textures/buttons/menu/purple/exit_button.png"};
	char* clickpath[] = {"resources/textures/buttons/menu/grey/new_game_button.png", "resources/textures/buttons/menu/grey/loadgame_button.png", "resources/textures/buttons/menu/grey/settings_button.png", "resources/textures/buttons/menu/grey/help_button.png", "resources/textures/buttons/menu/grey/exit_button.png"};
	SDL_Texture* blackoutTexture = loadTexture("resources/blackout.png");
	SDL_Rect blackoutRect;
	blackoutRect.x = 0;
	blackoutRect.y = 0;
	blackoutRect.w = SCREEN_WIDTH;
	blackoutRect.h = SCREEN_HEIGHT;
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
	SDL_RenderClear(renderer);
	SDL_Event event;
	while (1)
	{
		time = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				SDL_RenderClear(renderer);
				closeSDL();
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
							button[i] = loadTexture(clickpath[i]);
						}
					}
					else
					{
						if (selected[i])
						{
							selected[i] = 0;
							SDL_RenderClear(renderer);
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
						case 0:/*
							SDL_DestroyTexture(backgroundTexture);
							loc_room_day();
							break;*/
						case 1:
							if(loadGame() == 1) {
								return 0;
							}
							break;
						case 2:
							settings();
							for (int i = 0; i < NUMMENU; i++) {
								button[i] = loadTexture(unclickpath[i]);
							}
							break;
						case 3:
							/*if (help_screen() == 1) {
								showmenu();
							}
							SDL_Delay(16);
							break;*/
						case 4:
							SDL_RenderClear(renderer);
							return 0;
							break;
						}
					}
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					SDL_RenderClear(renderer);
					return 0;
				}
				break;
			}
		}
		SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
		SDL_RenderCopy(renderer, playerTexture, &animationClipsPlayer[currentFramePlayer], &playerRect);
		SDL_RenderCopy(renderer, blackoutTexture, NULL, &blackoutRect);
		for (int i = 0; i < NUMMENU; i += 1) {
			SDL_RenderCopy(renderer, button[i], NULL, &pos[i]);
		}
		SDL_RenderPresent(renderer);
		if (1000 / 30 > (SDL_GetTicks() - time))
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
	}

	return 1;
}
