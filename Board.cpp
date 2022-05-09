#include "Board.h"

//Constructor
Board::Board() {
    //Initialize Board
    this->board = {
        {' ', '0', '1', '2', '3', '4', '5'},
        {'A', ' ', ' ', ' ', ' ', ' ', ' '},
        {'B', ' ', ' ', ' ', ' ', ' ', ' '},
        {'C', ' ', ' ', ' ', ' ', ' ', ' '},
        {'D', ' ', ' ', ' ', ' ', ' ', ' '},
        {'E', ' ', ' ', ' ', ' ', ' ', ' '},
        {'F', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    //Initialize Row values
    rows['A'] = 1;
    rows['B'] = 2;
    rows['C'] = 3;
    rows['D'] = 4;
    rows['E'] = 5;
    rows['F'] = 6;
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
    if (strPos.length() != 2) {
        throw std::invalid_argument("Position should only be two characters.");
    }

    //Check Row
    char row = strPos[0];
    if (rows.find(row) == rows.end() ) {
        throw std::invalid_argument("Invalid row entered.");
    }

    //Check column
    int col = strPos[1] - ASCII_OFFSET;
    if (col > 5 || col < 0) {
        throw std::invalid_argument("Invalid column entered.");
    }

    //If pass, place at board and increase player's score
    this->board[rows[row]][col] = node->tile.letter;

    //Remove tile from player
    player->removeTile(node);
    player->increaseScore(node->tile.value);
}

//Print Function.
//Prints according to assignment specification.
void Board::printBoard() {
    for (unsigned int i = 0; i < this->board.size(); i++) {
        if (i == 1) {
            std::cout << "---------------------------" << std::endl;
        }

        for (unsigned int j = 0; j < this->board[i].size(); j++) {
            std::cout << this->board[i][j];
            if (i != 0) {
                std::cout << " | ";
            }
            else {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
        
    }
}

std::vector<std::vector<char>> Board::getBoard() {
    return this->board;
}