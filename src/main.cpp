#include <iostream>
#include <vector>
#include <stdio.h>
#include <SDL3/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define PLAYER_WIDTH 75
#define PLAYER_HEIGHT 20
#define PLAYER_Y_OFFSET 50
#define PLAYER_X_DELTA 25

int main(){
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	// Create a window
	SDL_Window *window = SDL_CreateWindow("Arkanoid", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!window){
		SDL_Log("Failed to create window: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// Create a renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
	if (!renderer){
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	int player_x_offset = 0;

	// main loop
	while (1) {
		// event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_EVENT_QUIT){
				break;
			}
			else if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE){
				break;
			}
			else if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_A){
				player_x_offset -= 1;
			}
			else if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_D){
				player_x_offset += 1;
			}
		} 		

		// Clear the screen with black color
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Calculate rectangle position
		int player_x = PLAYER_X_DELTA * player_x_offset + (WINDOW_WIDTH - PLAYER_WIDTH) / 2; // Center horizontally
		int player_y = (WINDOW_HEIGHT - PLAYER_Y_OFFSET) - PLAYER_HEIGHT; // 200 pixels above the bottom

		// Draw a white rectangle
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_FRect rect = {player_x, player_y, PLAYER_WIDTH, PLAYER_HEIGHT}; // x, y, width, height
		SDL_RenderFillRect(renderer, &rect);

		// Update the screen to show the change
		SDL_RenderPresent(renderer);
	}
	
	// Clean up resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
    
    return 0;
}