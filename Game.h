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

//These #defines are used mainly in loading a game
#define BOARD_FIRST_POS     4
#define BOARD_STEP_SIZE     4
#define BOARD_LAST_POS      60

class Game {
public:

    //Constructor/Destructor

    Game(std::string player1, std::string player2);
    Game(std::string fileName);
    ~Game();

    //Main Function

    void playGame();

private:
    //These functions should only be internally called
    void printScore(Player* player);
    void printGameResults();

    //Turn processors
    void getTurn(Player* player);
    void parseInput(Player* player, std::string input);
    void placeTurn(Player* player, std::vector<std::string> words);
    void replaceTurn(Player* player, std::vector<std::string> words);

    void checkGameStatus();
    
    //Save/Load functions
    void saveGame(std::vector<std::string> words);
    void loadGame(std::string fileName);


    Player*     player1;
    Player*     player2;
    TileBag*    tilebag;
    Board*      board;
    bool        endGame;
    bool        endTurn;
    bool        placeCommand;
    bool        gameLoaded;
    bool        gameFinished;
    int         bingoCounter;
};

#endif // ASSIGN2_GAME