#include "header.h"

int loadGame(void) {

       int fontSize = SCREEN_WIDTH / 20;
        int fontsize1 = SCREEN_WIDTH / 40;
   

    TTF_Font* Comfortaa = TTF_OpenFont("resources/fonts/ComfortaaRegular.ttf", fontSize);
    if (Comfortaa == NULL) {
        printf("Font loading error: %s\n", TTF_GetError());
        return 0;
    }
TTF_Font* Comfortaa1 = TTF_OpenFont("resources/fonts/ComfortaaRegular.ttf", fontsize1);
    if (Comfortaa1 == NULL) {
        printf("Font loading error: %s\n", TTF_GetError());
        return 0;
    }

    const char* loading_failed = "Game not found";
    const char* demo = "Demo version cannot be saved or loaded";

    SDL_Color White = {255, 255, 255, 255};
    SDL_Texture* exitImage = loadTexture("resources/textures/buttons/menu/purple/exit_button.png");
    SDL_Texture* exitImageClick = loadTexture("resources/textures/buttons/menu/grey/exit_button.png");

    if (exitImageClick == NULL) {
        printf("Image loading error\n");
        TTF_CloseFont(Comfortaa);
        return 0;
    }

    // Get the dimensions of the original exit button image
    int originalExitWidth, originalExitHeight;
    SDL_QueryTexture(exitImage, NULL, NULL, &originalExitWidth, &originalExitHeight);

    int exitWidth = SCREEN_WIDTH / 6;
    int exitHeight = originalExitHeight * exitWidth / originalExitWidth;

    SDL_Rect exitImageRect = {SCREEN_WIDTH / 2 - exitWidth / 2, SCREEN_HEIGHT - SCREEN_HEIGHT/4, exitWidth, exitHeight};
    SDL_Surface* surfaceError = TTF_RenderText_Solid(Comfortaa, loading_failed, White);
    SDL_Texture* textureError = SDL_CreateTextureFromSurface(renderer, surfaceError);
    SDL_Rect errorRect = {SCREEN_WIDTH / 2 - surfaceError->w / 2, SCREEN_HEIGHT / 2 - surfaceError->h / 2, surfaceError->w, surfaceError->h};

    SDL_Surface* surfaceDemo = TTF_RenderText_Solid(Comfortaa1, demo, White);
    SDL_Texture* textureDemo = SDL_CreateTextureFromSurface(renderer, surfaceDemo);
    SDL_Rect demoRect = {SCREEN_WIDTH / 2 - surfaceDemo->w / 2, SCREEN_HEIGHT / 2 + surfaceError->h, surfaceDemo->w, surfaceDemo->h};

    int quit = 0;
    int cursorX;
    int cursorY;
    SDL_GetMouseState(&cursorX, &cursorY);

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = 1;
            } else if (event.type == SDL_MOUSEMOTION) {
                // Update cursor position
                SDL_GetMouseState(&cursorX, &cursorY);
            } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                // Check if the user clicked the exit button
                if (isMouseOver(&exitImageRect, cursorX, cursorY)) {
                    return 1;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, exitImage, NULL, &exitImageRect);

        // Render exit text and image based on cursor position
        if (isMouseOver(&exitImageRect, cursorX, cursorY)) {
            SDL_RenderCopy(renderer, exitImageClick, NULL, &exitImageRect);
        } else {
            SDL_RenderCopy(renderer, exitImage, NULL, &exitImageRect);
        }
        SDL_RenderCopy(renderer, textureError, NULL, &errorRect);
        SDL_RenderCopy(renderer, textureDemo, NULL, &demoRect);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(exitImage);
    SDL_DestroyTexture(exitImageClick);
    SDL_DestroyTexture(textureError);
    SDL_FreeSurface(surfaceError);
    TTF_CloseFont(Comfortaa);

    printf("Error opening file for reading.\n");
    return -1;
}
