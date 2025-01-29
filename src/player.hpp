#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>

class Player {
	public:
		int Size;
        int X;
        int Y;
		int NewX;
		int NewY;
		Player(int x, int y, int size);
		void Draw(SDL_Renderer* render);
        void Input(SDL_Event event);
		int Colishen(int map[12][12]);
		void Mov();
};

#endif
