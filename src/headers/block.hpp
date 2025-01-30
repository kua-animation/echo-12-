#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include "player.hpp"
#include "window.hpp"

void FalseWoll(Player &player);
void QuitBlock(bool &run);
void NewLevel(int &mapInt, Player &player, Window &window );
void Dialogue(int mapInt);

#endif