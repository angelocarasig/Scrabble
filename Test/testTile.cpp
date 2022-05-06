#include "../Tile.h"

#include <iostream>

#define EXIT_SUCCESS 0

/*
Assuming that terminal is in main folder (not Test):

To compile, run the following command:
g++ -Wall -Werror -std=c++14 -O -o testTile Test/testTile.cpp Tile.cpp

To run: ./testTile
*/

int main() {
    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    std::cout << newTile.letter << "-" << newTile.value << std::endl;

    return EXIT_SUCCESS;
}