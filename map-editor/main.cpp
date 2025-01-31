#include "../src/headers/window.hpp"
#include "editor.hpp"

#define BLOCKSIZE 50
const char* windowName = "map editor";

bool running = true;

int map[12][12]{0};

SDL_Event event;
Window window(13*BLOCKSIZE+2, 13*BLOCKSIZE+2, windowName, map, BLOCKSIZE);
Editor editor(BLOCKSIZE, map);

int main() {
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window.Create();
	window.CreateRender();

	if(!window.Win){ 
		SDL_Quit();
		return 1;
	}

	if(!window.Render){
		SDL_DestroyWindow(window.Win);
		SDL_Quit;
		return 1;
	}

	while (running) {
        while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			editor.Move(event, map);
			window.SetMap(map);
        }

		SDL_SetRenderDrawColor(window.Render, 60, 10, 30, 255);
		SDL_RenderClear(window.Render);
		
		window.WorldDraw();
		editor.Render(window.Render);

		SDL_RenderPresent(window.Render);

		SDL_Delay(10);
	}
	
	SDL_DestroyWindow(window.Win);
	SDL_DestroyRenderer(window.Render);
	SDL_Quit();
	return 0;
}