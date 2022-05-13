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

    //Guard

    //Check Row
    char row = strPos[0];
    if (rows.find(row) == rows.end() ) {
        throw std::invalid_argument("Invalid row entered.");
    }

    //Check column

    std::string colString = strPos.substr(1, -1);
    if (std::any_of(std::begin(colString), std::end(colString), ::isalpha)) {
            throw std::invalid_argument("Invalid column entered");         //Letter inside
        }

    int col = std::stoi(colString);

    if (col > 14 || col < 0) {
            throw std::invalid_argument("Invalid column entered.");
        }

    //If pass, place at board and increase player's score
    if (this->board[rows[row]][col] != ' ') {
        throw std::invalid_argument("You can't place a tile that is already filled in!");
    }
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

    std::string colString = strPos.substr(1, -1);
    if (std::any_of(std::begin(colString), std::end(colString), ::isalpha)) {
            throw std::invalid_argument("Invalid column entered");         //Letter inside
        }

    int col = std::stoi(colString);

    if (col > 14 || col < 0) {
            throw std::invalid_argument("Invalid column entered.");
        }

    if (this->board[rows[row]][col] != ' ') {
        throw std::invalid_argument("You can't place a tile that is already filled in!");
    }
    this->board[rows[row]][col] = node->tile.letter;
}


//Gets the state of the board
std::string Board::getBoardString(){
    std::string finalString = "";
    std::string topString = "    ";
    std::string bottomString = "----";
    // Generates the top of the table based on the size of the board
    for(unsigned int i = 0; i < COLS; i++){
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
    // Puts together the top of table
    finalString += topString + "\n";
    finalString += bottomString + "\n";

    char baseLetter = 'A';
    for (unsigned int i = 0; i < ROWS; i++) {
        char curLetter = baseLetter + i;
        // Generates the char of the corresponding row
        finalString.push_back(curLetter);
        finalString += " | ";
        // Generates the rest of the row based on the size of the board
        for (unsigned int j = 0; j < this->board[i].size(); j++) {
            finalString += this->board[i][j];
            finalString += " | ";
        }
        finalString += "\n";
    }
    return finalString;
}

std::vector<std::vector<char>> Board::getBoard() {
    return this->board;
}