#include "headers/window.hpp"
#include <bits/stdc++.h> 

Window::Window(int w, int h, const char* name, int map[12][12], int blocksize) {
	width = w;
	height = h;
	Name = name;
	for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            Map[i][j] = map[i][j];
        }
    }
    BlockSize = blocksize;
}

void Window::Create(){
	Win = SDL_CreateWindow(Name,
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	width, height, SDL_WINDOW_SHOWN);
}

void Window::SetMap(int map[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            Map[i][j] = map[i][j];
        }
    }
}

void Window::CreateRender() {
	Render = SDL_CreateRenderer(Win,
	-1, SDL_RENDERER_SOFTWARE);
}

void Window::WorldDraw(int Ypos, int Xpos, bool RenderInt) {
    if (RenderInt) {
        for (int i = 0; i < 12; i++){
            Draw(Ypos, i);
        }
    } else {
        for (int i = 0; i < 12; i++){
            Draw(i, Xpos);
        }
    }


}

void Window::Draw(int Ypos, int Xpos) {
    SDL_Rect rect{0, 0, BlockSize-2, BlockSize-2};

            rect.x = Xpos* BlockSize + 2;
            rect.y = Ypos* BlockSize + 2;

            if (Map[Ypos][Xpos] == 1) {
                SDL_SetRenderDrawColor(Render, 68, 17, 81, 255);
            } else if (Map[Ypos][Xpos] == 6) {
                SDL_SetRenderDrawColor(Render, 255, 149, 140, 255);
            } else if (Map[Ypos][Xpos] == -1) {
                SDL_SetRenderDrawColor(Render, 136, 54, 119, 255);
            } else if (Map[Ypos][Xpos] == 3) {
                SDL_SetRenderDrawColor(Render, 238, 133, 181, 255);
            } else if (Map[Ypos][Xpos] == 2) {
                SDL_SetRenderDrawColor(Render, 84, 222, 253, 255);
            } else {
                SDL_SetRenderDrawColor(Render, 202, 97, 195, 255);
            }
            SDL_RenderFillRect(Render, &rect);
        
        

}