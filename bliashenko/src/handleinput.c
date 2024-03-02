#include "header.h"
#include "animation.h"

int currentFramePlayer = 0;
int frameCounterPlayer = 0;
int currentFrameDoor = 0;
int frameCounterDoor = 0;
int currentFrameTeacher = 0;
int frameCounterTeacher = 0;
int currentFrameVitalik = 0;
int frameCounterVitalik = 0;
int currentFrameGardener = 0;
int frameCounterGardener = 0;
int currentFrameHlopets = 0;
int frameCounterHlopets = 0;

int lastMoveLeft = 0;
int lastMoveRight = 1;
int MET_VITALIK = 0;
int MET_HLOPETS = 0;
int crawl = 0;

bool All_dialog = 0;

void handleInput(void) {
	int counter = 0;
	int quit = 1;
	//Uint32 time;
	bool is_player_near;
	SDL_Event event;
	//loc_room_day();
	//int x, y;
	while (quit)
	{
		//time = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				return;
			/*case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;
				if (currentBg == 1) {
					if (isMouseOver(&RoomDoorRect, x, y)) {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					} else {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					}
				}
				if (currentBg == 2) {
					if (isMouseOver(&CorrRoomDoorRect, x, y)) {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					} else {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					}
					if (isMouseOver(&MessDoorRect, x, y)) {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					} else {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					}
					if (isMouseOver(&OutDoorRect, x, y)) {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					} else {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					}
				}
				if (currentBg == 3) {
					if (isMouseOver(&CorrDoorRect, x, y)) {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					} else {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					}
				}
				if (currentBg == 4) {
					if (isMouseOver(&InDoorRect, x, y)) {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					} else {
						SDL_DestroyTexture(DoorTexture);
						DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					}
				}*/
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = intermenu();
					if (intermenu() == 0) {
						return;
					}
				}
				if (event.key.keysym.sym == SDLK_e && is_player_near) {/*
					if(All_dialog && LEVEL == 1) spy();
					if (LEVEL == 0) loc_room_day();
					if (LEVEL == 1 && !All_dialog) loc_corridor_day();
					if (LEVEL == 2) loc_messhall_day();
					if (LEVEL == 3) loc_outdoors_day();
					if (LEVEL == 4) loc_garden_day();
					if (LEVEL == 5) loc_gate_day();*/
					quit = 0;
				}
			}
		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

		//if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
		//	*quit = 1;
		//	closeSDL();
		//}

		if (currentKeyStates[SDL_SCANCODE_LEFT]) {
			if (backgroundRect.x < 0 && playerRect.x == SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2 && playerRect.x == SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2) {
				backgroundRect.x += PLAYER_SPEED;
				RoomDoorRect.x += PLAYER_SPEED;
				CorrRoomDoorRect.x += PLAYER_SPEED;
				MessDoorRect.x += PLAYER_SPEED;
				OutDoorRect.x += PLAYER_SPEED;
				CorrDoorRect.x += PLAYER_SPEED;
				InDoorRect.x += PLAYER_SPEED;
				ToGardenDoorRect.x += PLAYER_SPEED;
				ToGateDoorRect.x += PLAYER_SPEED;
				FromGardenDoorRect.x += PLAYER_SPEED;
				FromGateDoorRect.x += PLAYER_SPEED;
				NightGateDoorRect.x += PLAYER_SPEED;
				bedRect.x += PLAYER_SPEED;
				
				teacherRect.x += PLAYER_SPEED;
				chelRect.x += PLAYER_SPEED;
				chelkaRect.x += PLAYER_SPEED;
				hlopetsRect.x += PLAYER_SPEED;
				vitalikRect.x += PLAYER_SPEED;
				gardenerRect.x += PLAYER_SPEED;
			}
			else if (playerRect.x > 0) {
				playerRect.x -= PLAYER_SPEED;
			}
			lastMoveLeft = 1;
			lastMoveRight = 0;
			
			// Update animation frame
			if (crawl == 1) {
				frameCounterPlayer++;
				if (frameCounterPlayer >= FRAME_DELAY) {
					currentFramePlayer = (currentFramePlayer + 1) % 2 + 2;
					frameCounterPlayer = 0;
				}
			} else {
				frameCounterPlayer++;
				if (frameCounterPlayer >= FRAME_DELAY) {
					currentFramePlayer = (currentFramePlayer + 1) % 3 + 4;
					frameCounterPlayer = 0;
				}
			}
		} else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
			if (backgroundRect.x > SCREEN_WIDTH - BG_WIDTH + PLAYER_WIDTH / 2 && playerRect.x == SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2) {
				backgroundRect.x -= PLAYER_SPEED;
				RoomDoorRect.x -= PLAYER_SPEED;
				CorrRoomDoorRect.x -= PLAYER_SPEED;
				MessDoorRect.x -= PLAYER_SPEED;
				OutDoorRect.x -= PLAYER_SPEED;
				CorrDoorRect.x -= PLAYER_SPEED;
				InDoorRect.x -= PLAYER_SPEED;
				ToGardenDoorRect.x -= PLAYER_SPEED;
				ToGateDoorRect.x -= PLAYER_SPEED;
				FromGardenDoorRect.x -= PLAYER_SPEED;
				FromGateDoorRect.x -= PLAYER_SPEED;
				NightGateDoorRect.x -= PLAYER_SPEED;
				bedRect.x -= PLAYER_SPEED;
				
				teacherRect.x -= PLAYER_SPEED;
				chelRect.x -= PLAYER_SPEED;
				chelkaRect.x -= PLAYER_SPEED;
				hlopetsRect.x -= PLAYER_SPEED;
				vitalikRect.x -= PLAYER_SPEED;
				gardenerRect.x -= PLAYER_SPEED;
			}
			else if (playerRect.x < SCREEN_WIDTH - PLAYER_WIDTH) {
				playerRect.x += PLAYER_SPEED;
			}
			lastMoveLeft = 0;
			lastMoveRight = 1;
			
			// Update animation frame
			if (crawl == 1) {
				frameCounterPlayer++;
				if (frameCounterPlayer >= FRAME_DELAY) {
					currentFramePlayer = (currentFramePlayer + 1) % 2 + 0;
					frameCounterPlayer = 0;
				}
			} else {
				frameCounterPlayer++;
				if (frameCounterPlayer >= FRAME_DELAY) {
					currentFramePlayer = (currentFramePlayer + 1) % 3 + 1;
					frameCounterPlayer = 0;
				}
			}
		} else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
			/*if (crawl == 1) {
				// Update animation frame
				SDL_DestroyTexture(playerTexture);
				playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
				frameCounterPlayer++;
				if (frameCounterPlayer >= FRAME_DELAY) {
					if (lastMoveLeft == 0) { 
						currentFramePlayer = 1;
					} else {
						currentFramePlayer = 6;
					}
					frameCounterPlayer = 0;
				}
				crawl = 0;
			}
			else {*/
				// Update animation frame
				SDL_DestroyTexture(playerTexture);
				playerTexture = loadTexture("resources/textures/sprites/main_sit_4fr.png");
				frameCounterPlayer++;
				if (frameCounterPlayer >= FRAME_DELAY) {
					if (lastMoveLeft == 0) { 
						currentFramePlayer = 1;
					} else {
						currentFramePlayer = 2;
					}
					frameCounterPlayer = 0;
				}
				crawl = 1;
			//}
		} else if (currentKeyStates[SDL_SCANCODE_UP]) {
			// Update animation frame
			SDL_DestroyTexture(playerTexture);
			playerTexture = loadTexture("resources/textures/sprites/main_walk_8fr.png");
			frameCounterPlayer++;
			if (frameCounterPlayer >= FRAME_DELAY) {
				if (lastMoveLeft == 0) { 
					currentFramePlayer = 1;
				} else {
					currentFramePlayer = 6;
				}
				frameCounterPlayer = 0;
			}
			crawl = 0;
		} else if (crawl == 1) {
			frameCounterPlayer++;
			if (frameCounterPlayer >= FRAME_DELAY) {
				if (lastMoveLeft == 0) { 
					currentFramePlayer = 1;
				} else {
					currentFramePlayer = 2;
				}
				frameCounterPlayer = 0;
				vitalikRect.x -= VITALIK_SPEED;
			}
		} else if (crawl == 0) {
			currentFramePlayer = 0;
		} else { }



		SDL_RenderClear(renderer);
		SDL_Delay(5);
		//SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
		if (currentBg == 1) {
			if (abs(playerRect.x - RoomDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				//DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
				LEVEL = 1;
				PREV_LEVEL = 0;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				//DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
				LEVEL = 0;
				PREV_LEVEL = 0;
			}
			
			if (All_dialog == 1) {
				if (abs(playerRect.x - bedRect.x) < 100) {
					is_player_near = true;
					//DoorTexture = loadTexture("resources/textures/sprites/door_open.png");
					LEVEL = 6;
					PREV_LEVEL = 0;
				}
				else {
					is_player_near = false;
					//DoorTexture = loadTexture("resources/textures/sprites/door_open_2fr.png");
					LEVEL = 0;
					PREV_LEVEL = 0;
				}
			}
		}
		if (currentBg == 2) {
			//SDL_RenderCopy(renderer, DoorTexture, NULL, &RoomDoorRect);
			
			if (abs(playerRect.x - CorrRoomDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 0;
				PREV_LEVEL = 1;
			}			
			else if (abs(playerRect.x - MessDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 2;
				PREV_LEVEL = 1;
			}
			else if (abs(playerRect.x - OutDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 3;
				PREV_LEVEL = 1;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				LEVEL = 1;
				PREV_LEVEL = 1;
			}
		}
		if (currentBg == 3) {
			//SDL_RenderCopy(renderer, DoorTexture, NULL, &RoomDoorRect);
			if (abs(playerRect.x - CorrDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 1;
				PREV_LEVEL = 2;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				LEVEL = 2;
				PREV_LEVEL = 1;
			}
		}
		if (currentBg == 4) {
			//SDL_RenderCopy(renderer, DoorTexture, NULL, &RoomDoorRect);
			
				frameCounterVitalik++;
				if (frameCounterVitalik >= FRAME_DELAY) {
					currentFrameVitalik = (currentFrameVitalik + 1) % 3 + 4;
					frameCounterVitalik = 0;
				}
				vitalikRect.x -= VITALIK_SPEED;
				if (vitalikRect.x == 0) MET_VITALIK++;
			
			if (abs(playerRect.x - InDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 1;
				PREV_LEVEL = 3;
			}			
			else if (abs(playerRect.x - ToGardenDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 4;
				PREV_LEVEL = 3;
			}
			else if (abs(playerRect.x - ToGateDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 5;
				PREV_LEVEL = 3;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				LEVEL = 3;
				PREV_LEVEL = 1;
			}
		}
		if (currentBg == 5) {
			
			//SDL_DestroyTexture(gardenerTexture);
			//gardenerTexture = loadTexture("resources/textures/sprites/gardener_2fr.png");
			
			//SDL_RenderCopy(renderer, DoorTexture, NULL, &RoomDoorRect);
			if (abs(playerRect.x - FromGardenDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 3;
				PREV_LEVEL = 4;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				LEVEL = 4;
				PREV_LEVEL = 3;
			}
		}
		if (currentBg == 6) {
			//SDL_RenderCopy(renderer, DoorTexture, NULL, &RoomDoorRect);
			if (abs(playerRect.x - FromGateDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 3;
				PREV_LEVEL = 5;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				LEVEL = 5;
				PREV_LEVEL = 3;
			}
			All_dialog = 1;
		}
		if (currentBg == 7) {
			/*if (vitalikRect.x < RoomDoorRect.x) {
				//vitalikRect.x += 5 * PLAYER_SPEED / 6 - temp + playerRect.x;
				//vitalikRect.x += PLAYER_SPEED / 3 - temp + backgroundRect.x;
				//vitalikRect.x += -temp + backgroundRect.x;
				frameCounterVitalik++;
				if (frameCounterVitalik >= FRAME_DELAY) {
					currentFrameVitalik = (currentFrameVitalik + 1) % 3 + 1;
					frameCounterVitalik = 0;
				}
				vitalikRect.x += VITALIK_SPEED;
			}
			else {
				SDL_DestroyTexture(vitalikTexture);
			}
			if (abs(playerRect.x - vitalikRect.x) < 250 && crawl == 0) {
				//printf("Gameover\n");
				backgroundTexture = loadTexture("resources/textures/backgrounds/YOU_DIED.png");
				backgroundRect.x = 0;
				backgroundRect.y = 0;
				backgroundRect.w = SCREEN_WIDTH;
				backgroundRect.h = SCREEN_HEIGHT;
				//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				sound_play("resources/sounds/skrimer2-more_horrable.mp3", 20);
				SDL_RenderClear(renderer);
				while (1) {
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
						case SDL_QUIT:
							return;
						case SDL_KEYDOWN:
							if (event.key.keysym.sym == SDLK_ESCAPE) {
								intermenu();
							}
						}
					}
					SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
					SDL_RenderPresent(renderer);

				}
			}
			if (abs(playerRect.x - vitalikRect.x) < 100 && crawl == 1) {
				//printf("Gameover\n");
				backgroundTexture = loadTexture("resources/textures/backgrounds/YOU_DIED.png");
				backgroundRect.x = 0;
				backgroundRect.y = 0;
				backgroundRect.w = SCREEN_WIDTH;
				backgroundRect.h = SCREEN_HEIGHT;
				//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				sound_play("resources/sounds/skrimer2-more_horrable.mp3", 20);
				SDL_RenderClear(renderer);
				while (1) {
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
						case SDL_QUIT:
							return;
						case SDL_KEYDOWN:
							if (event.key.keysym.sym == SDLK_ESCAPE) {
								intermenu();
							}
						}
					}
					SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
					SDL_RenderPresent(renderer);

				}
			}
			frameCounterVitalik++;
			if (frameCounterVitalik >= FRAME_DELAY) {
				currentFrameVitalik = (currentFrameVitalik + 1) % 3 + 1;
				frameCounterVitalik = 0;
			}
			vitalikRect.x += VITALIK_SPEED;*/
		
			//SDL_RenderCopy(renderer, DoorTexture, NULL, &RoomDoorRect);
			if (abs(playerRect.x - NightGateDoorRect.x) < 100) {
				is_player_near = true;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 1;
					frameCounterDoor = 0;
				}
				LEVEL = 7;
				PREV_LEVEL = 6;
			}
			else {
				is_player_near = false;
				frameCounterDoor++;
				if (frameCounterDoor >= FRAME_DELAY) {
					currentFrameDoor = 0;
					frameCounterDoor = 0;
				}
				LEVEL = 6;
				PREV_LEVEL = 5;
			}

		}
		if (currentBg == 8) {
			counter++;
			if (counter == 100) {
				backgroundTexture = loadTexture("resources/textures/backgrounds/YOU_DIED.png");
				backgroundRect.x = 0;
				backgroundRect.y = 0;
				backgroundRect.w = SCREEN_WIDTH;
				backgroundRect.h = SCREEN_HEIGHT;
				//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				sound_play("resources/sounds/skrimer2-more_horrable.mp3", 20);
				SDL_RenderClear(renderer);
				while (1) {
					while (SDL_PollEvent(&event))
					{
						switch (event.type)
						{
						case SDL_QUIT:
							return;
						case SDL_KEYDOWN:
							if (event.key.keysym.sym == SDLK_ESCAPE) {
								intermenu();
							}
						}
					}
					SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
					SDL_RenderPresent(renderer);

				}
			}
		}
		

		if (abs(playerRect.x - teacherRect.x) < 50 && LEVEL == 1 && arr[0] == 0) {
			loadText("resources/dialogs/educator.txt");
			arr[0] = 1;
		}
		if (abs(playerRect.x - gardenerRect.x) < 50 && LEVEL == 4 && arr[1] == 0) {
			loadText("resources/dialogs/gardener.txt");
			arr[1] = 1;
		}
		if (abs(playerRect.x - chelRect.x) < 50 && LEVEL == 3 && arr[2] == 0) {
			loadText("resources/dialogs/boyfriend(pm).txt");
			arr[2] = 1;
		}
		if (abs(playerRect.x - chelkaRect.x) < 50 && LEVEL == 2 && arr[3] == 0) {
			loadText("resources/dialogs/charlie.txt");
			arr[3] = 1;
		}
		if (abs(playerRect.x - hlopetsRect.x) < 50 && LEVEL == 1 && arr[4] == 0) {
			loadText("resources/dialogs/kitchenroom.txt");
			arr[4] = 1;
		}
		//SDL_RenderCopy(renderer, playerTexture, &animationClipsPlayer[currentFramePlayer], &playerRect);

		// Present the renderer
		//SDL_RenderPresent(renderer);
		
		render();
	}

	if (LEVEL == 0) loc_room_day();
	if (LEVEL == 1) loc_corridor_day();
	if (LEVEL == 2) loc_messhall_day();
	if (LEVEL == 3) loc_outdoors_day();
	if (LEVEL == 4) loc_garden_day();
	if (LEVEL == 5) loc_gate_day();
	if (LEVEL == 6) loc_outdoors_night();
	if (LEVEL == 7) loc_gate_night();
}

