#include "player.hpp"

Player::Player(int x, int y, int size){ 
    X = x;
    Y = y;
    Size = size;

}

void Player::Draw(SDL_Renderer* render){
    SDL_Rect player{X, Y, Size-2, Size-2};
    SDL_SetRenderDrawColor(render, 246, 247, 248, 255);
    SDL_RenderFillRect(render, &player);
}

void Player::Input(SDL_Event event){
    NewX = X/Size;
    NewY = Y/Size;
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_w:
            NewY -= 1;
            break;

        case SDLK_s:
            NewY += 1;
            break;

        case SDLK_a:
            NewX -= 1;
            break;

        case SDLK_d:
            NewX += 1;
            break;
            
        default:
            break;
        }
        break;
    }
}
int Player::Colishen(int map[12][12]){
    return map[NewY][NewX];
}

void Player::Mov(){
	X = NewX*Size+2;
    Y = NewY*Size+2;
}