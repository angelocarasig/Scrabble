#ifndef ASSIGN2_BOARD
#define ASSIGN2_BOARD

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#include "Node.h"
#include "Player.h"

#define ROWS 15
#define COLS 15

class Board {
public:

    //Constructor and Deconstructor

    Board();
    ~Board();

    //Game Functions
    
    void placeTile(Node* node, std::string position);
    void placeTile(Player* player, Node* node, std::string position);
    std::string getBoardString();
    std::vector<std::vector<char>> getBoard();

private:
    std::vector<std::vector<char>>  board;
    std::map<char, int>             rows;
};

#endif