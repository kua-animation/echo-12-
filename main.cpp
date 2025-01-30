#include "src/echo[12].hpp"

#define BLOCKSIZE 58

const char* windowName = "--<ani + asm>--";

bool running = true;
int mapInt = 1;

SDL_Event event;
Player player(2*BLOCKSIZE, BLOCKSIZE, BLOCKSIZE);
Window window(12*BLOCKSIZE+2, 12*BLOCKSIZE+2, windowName, map1, BLOCKSIZE);

void initWorld(){
	SetMapFromFile("maps/map1.txt", &map1);
	SetMapFromFile("maps/map2.txt", &map2);
	SetMapFromFile("maps/map3.txt", &map3);
	window.SetMap(map1);
}

void GameLoop();

int main() {

	initWorld();
	
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
		GameLoop();

		SDL_SetRenderDrawColor(window.Render, 60, 10, 30, 255);
		SDL_RenderClear(window.Render);
		
		window.WorldDraw();
		player.Draw(window.Render);

		SDL_RenderPresent(window.Render);

		SDL_Delay(10);
	}
	
	SDL_DestroyWindow(window.Win);
	SDL_DestroyRenderer(window.Render);
	SDL_Quit();
	return 0;
}

//controls the key preses and player;
void GameLoop(){

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		player.Input(event);

		if (player.Colishen(window.Map) == 0 or player.Colishen(window.Map) == -1) {
			player.Mov();
		} 

		else if (player.Colishen(window.Map) == 2) {
			NewLevel(mapInt, player, window);
		} else if (player.Colishen(window.Map) == 3) {
			running = false;
		}
		else if (player.Colishen(window.Map) == 6) {
			Dialogue(mapInt);
		}
	}

}
