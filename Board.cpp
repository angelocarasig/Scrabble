#include "Board.h"

//Constructor
Board::Board() {
    //Initialize Board
    for (int i = 0; i < ROWS; i++) {
        std::vector<char> tempVector;
        for (int j = 0; j < COLS; j++) {
            tempVector.push_back(' ');
        }
        this->board.push_back(tempVector);
    }

    //Initialize Row values

    //TODO: Autogenerate key-value pairs based on number of rows in #define
    rows['A'] = 0;
    rows['B'] = 1;
    rows['C'] = 2;
    rows['D'] = 3;
    rows['E'] = 4;
    rows['F'] = 5;
    rows['G'] = 6;
    rows['H'] = 7;
    rows['I'] = 8;
    rows['J'] = 9;
    rows['K'] = 10;
    rows['L'] = 11;
    rows['M'] = 12;
    rows['N'] = 13;
    rows['O'] = 14;
}

//Deconstructor
Board::~Board() {
}

//Places a node to a strPos.
//Assume position formatted to "row""column". i.e: placing node C-1 at A0
//@param node Node to place. 
//@param strPos will split the row and column within the function.
void Board::placeTile(Player* player, Node* node, std::string strPos) {

    //TODO: Need player to be passed in to evaluate score

    //Guard

    //Check Row
    char row = strPos[0];
    if (rows.find(row) == rows.end() ) {
        throw std::invalid_argument("Invalid row entered.");
    }

    //Check column
    int col = std::stoi(strPos.substr(1,-1));  
    //NOTE: stoi merely grabs the all the number values until a letter or end of string is reached.
    std::cout << "TODO: Validate that string position has no characters for the substring [1...-1]" << std::endl;
    if (col > 14 || col < 0) {
        throw std::invalid_argument("Invalid column entered.");
    }

    //If pass, place at board and increase player's score
    this->board[rows[row]][col] = node->tile.letter;

    //Remove tile from player
    player->increaseScore(node->tile.value);
    player->removeTile(node);
}

// Placing tile without player interaction (for load game)
void Board::placeTile(Node* node, std::string strPos) {

    char row = strPos[0];
    if (rows.find(row) == rows.end() ) {
        throw std::invalid_argument("Invalid row entered.");
    }
    std::cout << "TODO: Validate that string position has no characters for the substring [1...-1]" << std::endl;
    int col = std::stoi(strPos.substr(1,-1)); 

    if (col > 14 || col < 0) {
        throw std::invalid_argument("Invalid column entered.");
    }

    this->board[rows[row]][col] = node->tile.letter;
}

//Print Function.
//Prints according to assignment specification.
void Board::printBoard() {
    for (unsigned int i = 0; i < this->board.size(); i++) {
        if (i == 0) {

            std::cout << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  " << std::endl;
            std::cout << "---------------------------------------------------------------" << std::endl;
        }

        if (i == 0) {std::cout << "A | ";}
        if (i == 1) {std::cout << "B | ";}
        if (i == 2) {std::cout << "C | ";}
        if (i == 3) {std::cout << "D | ";}
        if (i == 4) {std::cout << "E | ";}
        if (i == 5) {std::cout << "F | ";}
        if (i == 6) {std::cout << "G | ";}
        if (i == 7) {std::cout << "H | ";}
        if (i == 8) {std::cout << "I | ";}
        if (i == 9) {std::cout << "J | ";}
        if (i == 10) {std::cout << "K | ";}
        if (i == 11) {std::cout << "L | ";}
        if (i == 12) {std::cout << "M | ";}
        if (i == 13) {std::cout << "N | ";}
        if (i == 14) {std::cout << "O | ";}

        for (unsigned int j = 0; j < this->board[i].size(); j++) {
            std::cout << this->board[i][j];
            std::cout << " | ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<char>> Board::getBoard() {
    return this->board;
}