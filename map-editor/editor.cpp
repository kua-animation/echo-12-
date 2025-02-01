#include "editor.hpp"

Editor::Editor(int block, int map[12][12]){
    BlockSize = block;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            Map[i][j] = map[i][j];
        }
    }

}
void Editor::Render(SDL_Renderer* Render){
    SDL_Rect block{X, Y, BlockSize, BlockSize};
    SDL_RenderDrawRect(Render, &block);
}

void Editor::Move(SDL_Event event, int (&map)[12][12]){
    NewX = X/BlockSize;
    NewY = Y/BlockSize;
    int x, y;
    if (event.type == SDL_MOUSEMOTION) {

        SDL_GetMouseState(&x, &y);
            NewY = y / BlockSize;
            NewX = x / BlockSize;
    }
    Edit(event, map);
    X = NewX*BlockSize;
    Y = NewY*BlockSize;
}

void Editor::Pres(){
    std::ofstream file("maps/UotMap.txt");

    if (file.is_open()){
        for (int i = 0; i < 12; i++){
            for (int j = 0; j < 12; j++){
                file << Map[i][j];
                file << " ";
            }
            file << std::endl;
        }
    }

}

void Editor::Edit(SDL_Event event, int map[12][12]){
    switch(event.type){
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym){
            case SDLK_KP_0:
                Map[NewY][NewX] = 0;
                break;
            case SDLK_KP_1:
                Map[NewY][NewX] = 1;
                break;
            case SDLK_KP_2:
                Map[NewY][NewX] = 2;
                break;
            case SDLK_KP_3:
                Map[NewY][NewX] = 3;
                break;
            case SDLK_KP_MINUS:
                Map[NewY][NewX] = -1;
                break;
            case SDLK_p:
                Pres();
        }
    }
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            map[i][j] = Map[i][j];
        }
    }
}

