#include "headers/block.hpp"
#include "../world.hpp"


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

void Dialogue(int mapInt){
    if (2 == mapInt) {
		ReadFile("dialog/dialog2.txt");
	} 

}

			