#include "header.h"

void sentenceout(char* buf)
{
	const char *start = buf;
	const char *end = buf;
	char sentence[1000]; // Максимальная длина предложения
	int index = 0;

	while (*end)
	{
		if (*end == '.' || *end == '!' || *end == '?') 
		{
			while (start <= end) {
				sentence[index++] = *start++;
			}
			sentence[index] = '\0';
			TextSurface = TTF_RenderText_Blended_Wrapped(gFont, sentence, (SDL_Color){255,255,255,255}, 500);
			if (TextSurface == NULL) {
				printf("Surface creation failed: %s\n", TTF_GetError());
				exit(0);
			}
			TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
			if (TextSurface == NULL) {
				printf("Texture creation failed: %s\n", TTF_GetError());
				exit(0);
			}

			// Отображаем текстуру
			Text_Rect.x = 0;
			Text_Rect.y = 10;
			Text_Rect.w = TextSurface->w;
			Text_Rect.h = TextSurface->h;

			SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
			//Room
			if (currentBg == 1) {
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &RoomDoorRect);
			}
			//Corridor
			if (currentBg == 2) {
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &CorrRoomDoorRect);
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &MessDoorRect);
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &OutDoorRect);
				if (MET_HLOPETS == 0) SDL_RenderCopy(renderer, hlopetsTexture, &animationClipsHlopets[currentFrameHlopets], &hlopetsRect);
				SDL_RenderCopy(renderer, teacherTexture, &animationClipsTeacher[currentFrameTeacher], &teacherRect);
			}
			//Mess Hall
			if (currentBg == 3) {
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &CorrDoorRect);
				SDL_RenderCopy(renderer, chelkaTexture, NULL, &chelkaRect);
			}
			//Outdoors
			if (currentBg == 4) {
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &InDoorRect);
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &ToGardenDoorRect);
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &ToGateDoorRect);
				SDL_RenderCopy(renderer, chelTexture, NULL, &chelRect);
			}
			//Garden
			if (currentBg == 5) {
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &FromGardenDoorRect);
				SDL_RenderCopy(renderer, gardenerTexture, &animationClipsGardener[currentFrameGardener], &gardenerRect);
			}
			//Gate
			if (currentBg == 6) {
				SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &FromGateDoorRect);
			}
			SDL_RenderCopy(renderer, playerTexture, &animationClipsPlayer[currentFramePlayer], &playerRect);
			if (currentBg == 4) {
				if (MET_VITALIK == 0) SDL_RenderCopy(renderer, vitalikTexture, &animationClipsVitalik[currentFrameVitalik], &vitalikRect);
			}
			SDL_Texture* blackoutTexture = loadTexture("resources/blackout.png");
			SDL_RenderCopy(renderer, blackoutTexture, NULL, &(SDL_Rect){0, 0, SCREEN_WIDTH, Text_Rect.h + 50});

			SDL_DestroyTexture(blackoutTexture);
			// Отображаем текстуру
			SDL_RenderCopy(renderer, TextTexture, NULL, &Text_Rect);

			SDL_FreeSurface(TextSurface);

			//// Уничтожаем текстуру
			SDL_DestroyTexture(TextTexture);

			SDL_Texture* cuda = loadTexture("resources/cuda.png");

			SDL_Rect cudarect = {700, 0, 100, 100};

			int x,y;

			SDL_Event event;

			SDL_RenderCopy(renderer, cuda, NULL, &cudarect);
			SDL_RenderPresent(renderer);

			int quit = 1;
			while (quit)
			{
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
						case SDL_QUIT:
						SDL_RenderClear(renderer);
						exit(1);
						case SDL_MOUSEBUTTONDOWN:
						x = event.button.x;
						y = event.button.y;
						if (x >= cudarect.x && x <= cudarect.x + cudarect.w && y >= cudarect.y && y <= cudarect.y + cudarect.h)
						{  
							quit = 0;
						}
					}
				}
			}
			SDL_RenderClear(renderer);
			//// Задержка перед отображением следующей реплики (в миллисекундах)
			//SDL_Delay(2000);

			index = 0;
			while (*end && isspace(*end++));
			start = end;
		} else {
			++end;
		}
	}
}

