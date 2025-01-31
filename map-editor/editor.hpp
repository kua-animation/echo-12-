#ifndef EDITOR_H
#define EDITOR_H

#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>


class Editor{
    private:
    int NewX;
    int NewY;
    int X;
    int Y;
    void Pres();
    void Edit(SDL_Event event, int map[12][12]);
    
    public:
    int BlockSize;
    int Map[12][12];
    Editor(int block, int map[12][12]);
    void Render(SDL_Renderer* Render);
    void Move(SDL_Event event, int (&map)[12][12]);
    
    
};

#endif