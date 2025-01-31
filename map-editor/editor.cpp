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
        if (y/BlockSize == NewY + 1 or y/BlockSize == NewY - 1) {
            NewY = y / BlockSize;
        } if (x/BlockSize == NewX + 1 or x/BlockSize == NewX - 1) {
            NewX = x / BlockSize;
        }
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
            case SDLK_0:
                Map[NewY][NewX] = 1;
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

