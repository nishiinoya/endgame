#include "header.h"

int position = 0;
double volume = 20;

int settings(void) {
	Resolution arr[NUM_RESOLUTIONS];
	arrinit(arr);
	int x, y;
	int NUMMENU = 3;
	SDL_Texture* button[3];
	SDL_Rect pos[3];
	bool selected[3] = {0, 0, 0};
	char* unclickpath[] = { "resources/textures/buttons/settings/screen/purple/screen800.png", "resources/textures/buttons/settings/music_v/purple/music_volume_20.png", "resources/textures/buttons/menu/purple/exit_button.png" };
	char* clickpath[] = { "resources/textures/buttons/settings/screen/grey/screen800.png", "resources/textures/buttons/settings/music_v/grey/music_volume_20.png", "resources/textures/buttons/menu/grey/exit_button.png" };
	SDL_RenderClear(renderer);
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
	while (1) {
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
							switch (i) {
							case 0:
								adapUI(position, arr);
								switch (position) {
								case 4:
									clickpath[0] = "resources/textures/buttons/settings/screen/grey/screen800.png";
									unclickpath[0] = "resources/textures/buttons/settings/screen/purple/screen800.png";
									break;
								case 3:
									clickpath[0] = "resources/textures/buttons/settings/screen/grey/screen128.png";
									unclickpath[0] = "resources/textures/buttons/settings/screen/purple/screen128.png";
									break;
								case 2:
									clickpath[0] = "resources/textures/buttons/settings/screen/grey/screen768.png";
									unclickpath[0] = "resources/textures/buttons/settings/screen/purple/screen768.png";
									break;
								case 1:
									clickpath[0] = "resources/textures/buttons/settings/screen/grey/screen136.png";
									unclickpath[0] = "resources/textures/buttons/settings/screen/purple/screen136.png";
									break;
								case 0:
									clickpath[0] = "resources/textures/buttons/settings/screen/grey/screen192.png";
									unclickpath[0] = "resources/textures/buttons/settings/screen/purple/screen192.png";
									break;
								default:
									break;
								}
								SDL_DestroyTexture(button[0]);
								button[0] = loadTexture(clickpath[0]);
								position++;
								if (position == NUM_RESOLUTIONS) {
									position = 0;
								}
								backgroundRect.w = SCREEN_WIDTH;
								backgroundRect.h = SCREEN_HEIGHT;
								for (int i = 0; i < NUMMENU; i++) {
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
								break;
							case 1:
								Mix_VolumeMusic(round(128 * volume));
								switch ((int)volume) {
								case 0:
									clickpath[1] = "resources/textures/buttons/settings/music_v/grey/music_volume_00.png";
									unclickpath[1] = "resources/textures/buttons/settings/music_v/purple/music_volume_00.png";
									break;
								case 20:
									clickpath[1] = "resources/textures/buttons/settings/music_v/grey/music_volume_20.png";
									unclickpath[1] = "resources/textures/buttons/settings/music_v/purple/music_volume_20.png";
									break;
								case 40:
									clickpath[1] = "resources/textures/buttons/settings/music_v/grey/music_volume_40.png";
									unclickpath[1] = "resources/textures/buttons/settings/music_v/purple/music_volume_40.png";
									break;
								case 60:
									clickpath[1] = "resources/textures/buttons/settings/music_v/grey/music_volume_60.png";
									unclickpath[1] = "resources/textures/buttons/settings/music_v/purple/music_volume_60.png";
									break;
								case 80:
									clickpath[1] = "resources/textures/buttons/settings/music_v/grey/music_volume_80.png";
									unclickpath[1] = "resources/textures/buttons/settings/music_v/purple/music_volume_80.png";
									break;
								case 100:
									clickpath[1] = "resources/textures/buttons/settings/music_v/grey/music_volume_100.png";
									unclickpath[1] = "resources/textures/buttons/settings/music_v/purple/music_volume_100.png";
									break;
								default:
									break;
								}
								SDL_DestroyTexture(button[1]);
								button[1] = loadTexture(clickpath[1]);
								volume += 20;
								if (volume > 100) {
									volume = 0;
								}
								break;
							case 2:
								return 0;
								break;
							}
							default:
								break;
						}
					}
					break;
				case SDL_KEYDOWN:
					SDL_RenderClear(renderer);
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						return 0;
					}
				}
			}
			SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
			for (int i = 0; i < NUMMENU; i += 1) {
				SDL_RenderCopy(renderer, button[i], NULL, &pos[i]);
			}
			SDL_RenderPresent(renderer);
		}
		closeSDL();
	}
	
