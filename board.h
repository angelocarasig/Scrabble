#ifndef ASSIGN2_BOARD
#define ASSIGN2_BOARD

#include <vector>
#include <iostream>
#include <string>
#include "Node.h"
#include <map>

#define ASCII_OFFSET 47

class Board {
public:
    Board();
    ~Board();

    //Passes a node from a player's hand onto the board
    void placeTile(Node* node, std::string position);
    void printBoard();

private:
    std::vector<std::vector<char>> board;
    std::map<char, int> rows;
};

#endif