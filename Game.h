#ifndef ASSIGN2_GAME
#define ASSIGN2_GAME
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "TileBag.h"
#include "Player.h"
#include "Board.h"

class Game {
public:

    //Constructor/Destructor

    Game(std::string player1, std::string player2);
    ~Game();

    //Main Function

    void playGame();

    //Move processing functions

    void getTurn(Player* player);
    void readInput(Player* player, std::string input);

private:
    Player* player1;
    Player* player2;
    TileBag* tilebag;
    Board* board;
    bool endGame;
};

#endif // ASSIGN2_GAME