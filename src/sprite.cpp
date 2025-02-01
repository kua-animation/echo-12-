#include "headers/sprite.hpp"

Sprite::Sprite(const char* image)
    :
    Image(image)
{}

int Sprite::CreateSprite(SDL_Renderer* render, SDL_Window* window){
    Surface = IMG_Load(Image);
    if (Surface == nullptr) {
        std::cerr << "Unable to load image! IMG_Error: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    // Create texture from the surface
    Texture = SDL_CreateTextureFromSurface(render, Surface);
    SDL_FreeSurface(Surface); // No longer need the surface after creating the texture
    if (Texture == nullptr) {
        std::cerr << "Unable to create texture from surface! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }
    return 0;
}

void Sprite::Render(SDL_Renderer* render, SDL_Rect* rect){
    SDL_RenderCopy(render, Texture, nullptr, rect);

}