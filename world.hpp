#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>

extern int map1[12][12];
extern int map2[12][12];
extern int map3[12][12];
extern int mapMain[12][12];

int SetMapFromFile(const std::string FileName, int (*map)[12][12]);

void ReadFile(std::string FileName);

#endif