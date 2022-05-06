#include "../Player.h"
#include "../TileBag.h"
#include <iostream>
#include <string>

/*
Compile: g++ -Wall -Werror -ggdb3 -std=c++14 -O -o testPlayer Test/testPlayer.cpp Node.cpp LinkedList.cpp Tile.cpp TileBag.cpp Player.cpp
Run: ./testPlayer
*/

int main() {
    std::cout << "\n+++++++++++++++++TESTING ADDFRONT+++++++++++++++++" << std::endl;
    TileBag* tb = new TileBag();
    Player* player1 = new Player("Angelo");
    player1->fillHand(tb);
    player1->printPlayer();

    std::cout << std::endl;

    char tile;
    std::cin >> tile;

    player1->replaceTile(tb, tile);
    player1->printPlayer();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete player1;
    delete tb;
}