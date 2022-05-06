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
void Board::placeTile(Node* node, std::string strPos) {

    //TODO: Need player to be passed in to evaluate score

    //Guard
    if (strPos.length() != 2) {
        throw std::invalid_argument("Position should only be two characters.");
    }

    //End of guard
    char row = strPos[0];
    int col = strPos[1] - ASCII_OFFSET;

    this->board[rows[row]][col] = node->tile.letter;
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