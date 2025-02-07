#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "sprite.hpp"
#include <iostream>
#include "window.hpp"

class Player {
	public:
		int Size;
        int X;
        int Y;
		int NewX;
		int NewY;
		bool RenderInt;
		Sprite Image;
		Player(int x, int y, int size, const char* image);
		void Init(SDL_Renderer* render, SDL_Window* window);
		void Draw(SDL_Renderer* render);
        void Input(SDL_Event event);
		void Place(SDL_Event event, Window& window, int (&map)[12][12]);
		int Colishen(int map[12][12]);
		void Mov();
};

#endif
