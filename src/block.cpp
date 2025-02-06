#include "headers/block.hpp"
#include "../world.hpp"


void PlayMusic(const char* name, SDL_Event event){


    Mix_Music* song =  Mix_LoadMUS(name);
	if (song == NULL) {
		std::cout << "erorr" << Mix_GetError() << std::endl; 
		return;
	}
    if (Mix_PlayMusic(song, 1) == -1) {
		std::cout << "erorr" << Mix_GetError() << std::endl;
		return;
	}

	while (Mix_PlayingMusic()){
		SDL_PollEvent(&event);
		SDL_Delay(10);
	}
	
    Mix_FreeMusic(song);

}


void FalseWoll(Player &player){
    player.Mov();
}


void QuitBlock(bool &run){
    run = false;
}

void NewLevel(int &mapInt, Player &player, Window &window ){
	
    if (0 == mapInt) {
		window.SetMap(map1);
		mapInt = 1;
		player.Mov();
	} 
		
	else if (1 == mapInt) {
		window.SetMap(map2);
		mapInt = 2;
		player.Mov();
	}

    else if (2 == mapInt) {
        window.SetMap(map3);
        mapInt = 0;
        player.Mov();
    }
}

void Dialogue(int mapInt, SDL_Event event){
	switch (mapInt) {
		case 1:
			PlayMusic("dialog/test.wav", event);
			break;
		default:
			break;
	}


}

void Level(Window &Window){
	Window.SetMap(mapMain);
}

			