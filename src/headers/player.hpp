#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "sprite.hpp"
#include <iostream>

class Player {
	public:
		int Size;
        int X;
        int Y;
		int NewX;
		int NewY;
		Sprite Image;
		Player(int x, int y, int size);
		void Init(SDL_Renderer* render, SDL_Window* window);
		void Draw(SDL_Renderer* render);
        void Input(SDL_Event event);
		int Colishen(int map[12][12]);
		void Mov();
};

#endif
