#include "header.h"

TTF_Font* Comfortaa;

int help_screen(void) {
	Comfortaa = TTF_OpenFont("resources/fonts/ComfortaaRegular.ttf", 18); // Smaller text size
	if (Comfortaa == NULL) {
		printf("Font loading error: %s\n", TTF_GetError());
		return 0;
	}
	const char* move = "Navigate movements of your sprite by utilizing arrow keys";
	const char* down = "Press the arrow down key to prompt the sprite to sit";
	const char* save = "Save your progress by employing the \"save\" button";
	const char* engage = "Press E to engage with objects";
	const char* exitText = "Use \"exit\" button to return to the main menu";

	SDL_Color White = {255, 255, 255, 255};

	SDL_Surface* surfaceMove = TTF_RenderText_Solid(Comfortaa, move, White);
	SDL_Surface* surfaceDown = TTF_RenderText_Solid(Comfortaa, down, White);
	SDL_Surface* surfaceSave = TTF_RenderText_Solid(Comfortaa, save, White);
	SDL_Surface* surfaceEngage = TTF_RenderText_Solid(Comfortaa, engage, White);
	SDL_Surface* surfaceExit = TTF_RenderText_Solid(Comfortaa, exitText, White);

	// Convert surfaces to textures
	SDL_Texture* textureMove = SDL_CreateTextureFromSurface(renderer, surfaceMove);
	SDL_Texture* textureDown = SDL_CreateTextureFromSurface(renderer, surfaceDown);
	SDL_Texture* textureSave = SDL_CreateTextureFromSurface(renderer, surfaceSave);
	SDL_Texture* textureEngage = SDL_CreateTextureFromSurface(renderer, surfaceEngage);
	SDL_Texture* textureExit = SDL_CreateTextureFromSurface(renderer, surfaceExit);

	if (textureMove == NULL || textureDown == NULL || textureSave == NULL || textureEngage == NULL || textureExit == NULL) {
	printf("Texture creation error: %s\n", SDL_GetError());
	SDL_FreeSurface(surfaceMove);
	SDL_FreeSurface(surfaceDown);
	SDL_FreeSurface(surfaceSave);
	SDL_FreeSurface(surfaceEngage);
	SDL_FreeSurface(surfaceExit);
	TTF_CloseFont(Comfortaa);
	return 0;
	}

	int textWidth = surfaceMove->w;
	int textHeight = surfaceMove->h;

	// Load arrow image
	SDL_Texture* arrow = loadTexture("resources/textures/buttons/help/strelochki_rl.png");
	SDL_Texture* downImage = loadTexture("resources/textures/buttons/help/strelochki_down.png");
	SDL_Texture* saveImage = loadTexture("resources/textures/buttons/menu/purple/save_button.png");
	SDL_Texture* exitImage = loadTexture("resources/textures/buttons/menu/purple/exit_button.png");
	SDL_Texture* exitImageClick = loadTexture("resources/textures/buttons/menu/grey/exit_button.png");

	if (exitImageClick == NULL) {
		printf("Image loading error\n");
		SDL_DestroyTexture(textureMove);
		SDL_DestroyTexture(textureDown);
		SDL_DestroyTexture(textureSave);
		SDL_DestroyTexture(textureEngage);
		SDL_DestroyTexture(textureExit);
		SDL_DestroyTexture(arrow);
		SDL_DestroyTexture(downImage);
		SDL_DestroyTexture(saveImage);
		TTF_CloseFont(Comfortaa);
		return 0;
	}
	
	// Get the dimensions of the original images
	int originalArrowWidth, originalArrowHeight;
	SDL_QueryTexture(arrow, NULL, NULL, &originalArrowWidth, &originalArrowHeight);

	int originalDownWidth, originalDownHeight;
	SDL_QueryTexture(downImage, NULL, NULL, &originalDownWidth, &originalDownHeight);

	int originalSaveWidth, originalSaveHeight;
	SDL_QueryTexture(saveImage, NULL, NULL, &originalSaveWidth, &originalSaveHeight);

	int originalExitWidth, originalExitHeight;
	SDL_QueryTexture(exitImage, NULL, NULL, &originalExitWidth, &originalExitHeight);

	// Calculate proportional width based on aspect ratio
	int arrowWidth = SCREEN_WIDTH / 6;
	int arrowHeight = originalArrowHeight * arrowWidth / originalArrowWidth;

	int downWidth = SCREEN_WIDTH / 6;
	int downHeight = originalDownHeight * downWidth / originalDownWidth;

	int saveWidth = SCREEN_WIDTH / 6;
	int saveHeight = originalSaveHeight * saveWidth / originalSaveWidth;

	int exitWidth = SCREEN_WIDTH / 6;
	int exitHeight = originalExitHeight * exitWidth / originalExitWidth;

	// Calculate center positions
	int centerX = SCREEN_WIDTH / 2;
	int centerY = (SCREEN_HEIGHT - (5 * textHeight + 3 * arrowHeight + downHeight + saveHeight + exitHeight)) / 2;

	// Create SDL_Rect variables for each image
	SDL_Rect moveRect = {centerX - textWidth / 2, centerY, textWidth, textHeight};
	SDL_Rect arrowRect = {centerX - arrowWidth / 2, centerY + textHeight, arrowWidth, arrowHeight};

	SDL_Rect downRect = {centerX - textWidth / 2, centerY + (textHeight + arrowHeight), textWidth, textHeight};
	SDL_Rect downImageRect = {centerX - downWidth / 2, centerY + (textHeight + arrowHeight) + textHeight, downWidth, downHeight};

	SDL_Rect saveRect = {centerX - textWidth / 2, centerY + 2 * (textHeight + arrowHeight), textWidth, textHeight};
	SDL_Rect saveImageRect = {centerX - saveWidth / 2, centerY + 2 * (textHeight + arrowHeight) + saveHeight / 2 + textHeight, saveWidth, saveHeight};

	SDL_Rect engageRect = {centerX - textWidth / 2, centerY + 3 * (textHeight + arrowHeight), textWidth, textHeight};

	SDL_Rect exitImageRect = {centerX - exitWidth / 2, centerY + 4 * (textHeight + arrowHeight) + exitHeight / 2, exitWidth, exitHeight};
	SDL_Rect exitRect = {centerX - textWidth / 2, centerY + 5 * (textHeight + arrowHeight), textWidth, textHeight};

	// Rendering loop
	SDL_Event event;
	int quit = 0;

	  int cursorX, cursorY;
	  SDL_GetMouseState(&cursorX, &cursorY);
	  while (!quit) {
		  while (SDL_PollEvent(&event)) {
			  if (event.type == SDL_QUIT) {
				  quit = 1;
			  }
			  else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				  quit = 1;
			  }
			  else if (event.type == SDL_MOUSEMOTION) {
				  // Update cursor position
				  SDL_GetMouseState(&cursorX, &cursorY);
			  }
			  else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {

				  //SDL_GetMouseState(&cursorX, &cursorY);
				  // Check if the user clicked the exit button
				  if (isMouseOver(&exitImageRect, cursorX, cursorY)) {
					  return 1; // Return 1 to indicate that the user chose to exit help_screen
				  }
			  }
		  }

			  SDL_RenderClear(renderer);
			  SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);

			  // Render first text and image
			  SDL_RenderCopy(renderer, textureMove, NULL, &moveRect);
			  SDL_RenderCopy(renderer, arrow, NULL, &arrowRect);

			  // Render second text and image
			  SDL_RenderCopy(renderer, textureDown, NULL, &downRect);
			  SDL_RenderCopy(renderer, downImage, NULL, &downImageRect);

			  // Render third text and image
			  SDL_RenderCopy(renderer, textureSave, NULL, &saveRect);
			  SDL_RenderCopy(renderer, saveImage, NULL, &saveImageRect);

			  // Render fourth text and image
			  SDL_RenderCopy(renderer, textureEngage, NULL, &engageRect);

			  // Render exit text and image based on cursor position
			  if (isMouseOver(&exitImageRect, cursorX, cursorY)) {
				  SDL_RenderCopy(renderer, textureExit, NULL, &exitRect);
				  SDL_RenderCopy(renderer, exitImageClick, NULL, &exitImageRect);
			  }
			  else {
				  SDL_RenderCopy(renderer, textureExit, NULL, &exitRect);
				  SDL_RenderCopy(renderer, exitImage, NULL, &exitImageRect);
			  }

			  SDL_RenderPresent(renderer);
		}

	// Cleanup
	SDL_DestroyTexture(textureMove);
	SDL_DestroyTexture(textureDown);
	SDL_DestroyTexture(textureSave);
	SDL_DestroyTexture(textureEngage);
	SDL_DestroyTexture(textureExit);
	SDL_DestroyTexture(arrow);
	SDL_DestroyTexture(downImage);
	SDL_DestroyTexture(saveImage);
	SDL_DestroyTexture(exitImage);
	SDL_DestroyTexture(exitImageClick);
	TTF_CloseFont(Comfortaa);
	return -1;
}

