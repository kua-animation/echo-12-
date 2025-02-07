#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include "player.hpp"
#include "window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void FalseWoll(Player &player);
void QuitBlock(bool &run);
void NewLevel(int &mapInt, Player &player, Window &window );
void Dialogue(int mapInt, SDL_Event event);
void PlaceBlocks(SDL_Event event, Window& window, int mapInt, Player& player);

void PlayMusic(const char* name, SDL_Event event);

#endif