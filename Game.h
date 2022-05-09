#ifndef ASSIGN2_GAME
#define ASSIGN2_GAME
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

#include "TileBag.h"
#include "Player.h"
#include "Board.h"

class Game {
public:

    //Constructor/Destructor

    Game(std::string player1, std::string player2);
    Game(std::string fileName);
    ~Game();

    //Main Function

    void playGame();

    //Move processing functions

    void printScore(Player* player);

    void getTurn(Player* player);
    void parseInput(Player* player, std::string input);
    
    void placeTurn(Player* player, std::vector<std::string> words);
    void replaceTurn(Player* player, std::vector<std::string> words);
    
    void saveGame(std::vector<std::string> words);
    void loadGame(std::string fileName);

private:
    Player*     player1;
    Player*     player2;
    TileBag*    tilebag;
    Board*      board;
    bool        endGame;
    bool        endTurn;
    bool        placeCommand;
};

#endif // ASSIGN2_GAME