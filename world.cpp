#include "world.hpp"

int map1[12][12];
int map2[12][12];
int map3[12][12];   
int mapMain[12][12];

int SetMapFromFile(std::string FileName, int (*map)[12][12]){
    std::ifstream file(FileName);

    if(!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			file >> (*map)[i][j];
		}
	}

    file.close();
    return 0;
}

void ReadFile(std::string FileName){
    std::string Text;
    std::ifstream file(FileName);

    while (std::getline(file, Text)) {
        std::cout << Text;
    }
    std::cout << std::endl;
    
}