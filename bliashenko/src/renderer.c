#include "header.h"

void render(void) {
	// Clear the renderer
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_Delay(5);
	
	SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
	//Room
	if (currentBg == 1) {
		SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &RoomDoorRect);
		SDL_RenderCopy(renderer, bedTexture, NULL, &bedRect);
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
	if (currentBg == 4) {
		if (MET_VITALIK == 0) SDL_RenderCopy(renderer, vitalikTexture, &animationClipsVitalik[currentFrameVitalik], &vitalikRect);
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
	if (currentBg == 7) {
		SDL_RenderCopy(renderer, DoorTexture, &animationClipsDoor[currentFrameDoor], &NightGateDoorRect);
		//SDL_RenderCopy(renderer, vitalikTexture, &animationClipsVitalik[currentFrameVitalik], &vitalikRect);
	}
	SDL_RenderCopy(renderer, playerTexture, &animationClipsPlayer[currentFramePlayer], &playerRect);
	// Present the renderer
	SDL_RenderPresent(renderer);
}

