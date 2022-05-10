#include "../TileBag.h"
#include <iostream>
#include <string>

/*
Copmile: g++ -Wall -Werror -std=c++14 -O -o testTileBag Test/testTileBag.cpp Node.cpp LinkedList.cpp Tile.cpp TileBag.cpp
Run: ./testTileBag
*/

int main() {
    std::cout << "\n+++++++++++++++++TESTING GETSCRABBLETILES+++++++++++++++++" << std::endl;
    std::cout << "TileBag is scrambled in constructor." << std::endl;
    
    TileBag* tb = new TileBag();
    std::cout << "TileBag:" << std::endl;
    tb->printBag();
    std::cout << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    delete tb;
}