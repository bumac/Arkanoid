#include <iostream>
#include <vector>
#include <stdio.h>
#include <SDL3/SDL.h>

#define WIDTH 800
#define HEIGHT 600
#define IMG_PATH "exit.png"

int main(){
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
			return 1;

	// create the window and renderer
	// note that the renderer is accelerated
	SDL_Window *win = SDL_CreateWindow("Arkanoid", WIDTH, HEIGHT, 0);

	std::vector<Uint32> pixels(WIDTH * HEIGHT, 0x00FF00FF);

	SDL_Renderer *renderer = SDL_CreateRenderer(win, nullptr);
	SDL_Surface *surface = SDL_CreateSurfaceFrom(WIDTH, HEIGHT, SDL_PIXELFORMAT_RGBA8888, pixels.data(), WIDTH *4);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	// main loop
	while (1) {
		
		// event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_EVENT_QUIT)
				break;
			else if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)
				break;
		} 		

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);
		// SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderTexture(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
    
    return 0;
}