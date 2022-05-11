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

    //Generates key-value pairs based on number of rows in #define, ROWS should be a value between 0 and 26 or this code will use weird charicters 
    char curLetter = 'A';
    for(int i = 0; i < ROWS; i++){
        rows[curLetter+i] = i;
    }
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

    std::string topString = "    ";
    std::string bottomString = "----";
    // Displays the top of the table based on the size of the board
    for(unsigned int i = 0; i < this->board[i].size(); i++){
        std::string iString = std::to_string(i);
        // This checks the number of digits and adjusts the formatting accordingly
        if(i < 10){
            topString = topString + iString;
            topString = topString + "   ";
        }
        else if(i < 100){
            topString = topString + iString;
            topString = topString + "  ";
        }
        else if(i < 1000){
            topString = topString + iString;
            topString = topString + " ";
        }
        bottomString = bottomString + "----";
    }
    // Trims off the end
    topString.pop_back();
    bottomString.pop_back();
    // Outputs the top of table
    std::cout << topString << std::endl;
    std::cout << bottomString << std::endl;

    char baseLetter = 'A';
    for (unsigned int i = 0; i < this->board.size(); i++) {
        char curLetter = baseLetter + i;
        // Prints the char of the corresponding row
        std::cout << curLetter << " | ";
        // Prints the rest of the row based on the size of the board
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