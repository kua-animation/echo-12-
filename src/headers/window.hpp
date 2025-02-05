#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>

class Window {
	private:
        int BlockSize;
		void Draw(int Ypos, int RenderInt);
	public:
		int Map[12][12];
		int width;
		int height;
		const char* Name;
		SDL_Window* Win;
		SDL_Renderer* Render;
		Window(int w, int h, const char* name, int map[12][12], int blocksize);
		void Create();
		void CreateRender();
		void WorldDraw(int Ypos, bool RenderInt);
		void SetMap(int map[12][12]);
};

#endif
