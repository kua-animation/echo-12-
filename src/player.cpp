#include "headers/player.hpp"

Player::Player(int x, int y, int size, const char* image)
    :
    X(x),
    Y(y),
    Size(size),
    Image(image)
{}

void Player::Init(SDL_Renderer* render, SDL_Window* window){
    Image.CreateSprite(render, window);
}

void Player::Draw(SDL_Renderer* render){
    SDL_Rect player{X, Y, Size-2, Size-2};
    Image.Render(render, &player);
}

void Player::Input(SDL_Event event){
    NewX = X/Size;
    NewY = Y/Size;
    int x, y;
    if (event.type == SDL_MOUSEMOTION) {

        SDL_GetMouseState(&x, &y);
        if (RenderInt) {
            if (x/Size == NewX + 1 or x/Size == NewX - 1) {
                NewX = x / Size;
            }
        } else {
            if (y/Size == NewY + 1 or y/Size == NewY - 1) {
                NewY = y / Size;
            }
        }
    }
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym)
        {
        case SDLK_TAB:
            if (RenderInt) {
                RenderInt = false;
            } else {
                RenderInt = true;
            }
            break;
        default:
            break;
        }
    }
}
int Player::Colishen(int map[12][12]){
    return map[NewY][NewX];
}

void Player::Mov(){
	X = NewX*Size+2;
    Y = NewY*Size+2;
}