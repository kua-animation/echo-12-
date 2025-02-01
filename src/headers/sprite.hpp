#ifndef SPRIRTE_H
#define SPRIRTE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Sprite {
    public:
    const char* Image;
    SDL_Surface* Surface;
    SDL_Texture* Texture;
    Sprite(const char* image);
    int CreateSprite(SDL_Renderer* render, SDL_Window* window);
    void Render(SDL_Renderer* render, SDL_Rect* rect);
};

#endif