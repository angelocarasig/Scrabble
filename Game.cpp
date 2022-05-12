#include "Game.h"

//Game Constructor.
//@param player1 Name of player1
//@param player2 Name of player2
Game::Game(std::string player1, std::string player2) {
    this->player1 = new Player(player1);
    this->player2 = new Player(player2);

    this->tilebag = new TileBag();
    this->board = new Board();
    this->endGame = false;
    this->endTurn = false;
    this->placeCommand = false;
    this->bingoCounter = 0;

    this->player1->fillHand(tilebag);
    this->player2->fillHand(tilebag);
    //Comment out when not needed
    tilebag->clearBag();
}

//Load Game Constructor.
//Overloads default constructor
Game::Game(std::string fileName) {
    std::string nameOfFile = fileName;
    this->gameLoaded = false;
    while (!gameLoaded) {
        try {
                loadGame(nameOfFile);
            }
            catch (std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                std::cout << "failed to find game name." << std::endl;
                
                std::cout << "Enter filename of the save file: ";
                getline(std::cin, nameOfFile);
            }
        }
}

//Destructor
Game::~Game() {
    delete player1;
    delete player2;
    delete tilebag;
    delete board;
}

//Prints current turn details for player.
//Prints according to assignment specifications:
//- Which player turn
//- Both player's scores
//- Current board state
//- Current player's hand
void Game::printScore(Player* player) {
    std::cout << std::endl;
    std::cout << player->getName() << ", it's your turn" << std::endl;
    std::cout << "Score for " << this->player1->getName() << ": " << player1->getScore() << std::endl;
    std::cout << "Score for " << this->player2->getName() << ": " << player2->getScore() << std::endl;

    board->printBoard();

    std::cout << std::endl;

    std::cout << "Your hand is" << std::endl;
    player->printHand();
}

void Game::printGameResults() {
    std::cout << "\nGame Over" << std::endl;
    std::cout << "Score for " << this->player1->getName() << ": " << this->player1->getScore() << std::endl;
    std::cout << "Score for " << this->player2->getName() << ": " << this->player2->getScore() << std::endl;

    if (this->player1->getScore() > this->player2->getScore()) {
        std::cout << "Player " << this->player1->getName() << " won!" << std::endl;
    }
    else if (this->player1->getScore() < this->player2->getScore()) {
        std::cout << "Player " << this->player2->getName() << " won!" << std::endl;
    }
    else {
        std::cout << "Draw!" << std::endl;
    }
}

//Main game operation.
//Turn based loop (always starts with player 1).
//Ends when a player quits or the game ends.
void Game::playGame() {
    while (!endGame) {
        try {
            printScore(player1);
            getTurn(player1);
            
            printScore(player2);
            getTurn(player2);
        }
        catch (std::exception& e) {
            // std::cout << "Ending game..." << std::endl;
            printGameResults();
            this->endGame = true;
            std::cout << std::endl;
        }
        // catch (int e) {
            //Should throw same exception as quit
        // }
    }
}

//Gets player input.
//In loop to consider "place commands" and for input validation.
void Game::getTurn(Player* player) {

    this->endTurn = false;

    while (!endTurn) {
        try {
            std::cout << std::endl;
            std::cout << "> ";
            std::string input;
            getline(std::cin, input);
            parseInput(player, input);
        }
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

//Converts player input arguments into vector, validate the arguments and process the command given.
void Game::parseInput(Player* player, std::string input) {

    //Split the words into a vector
    std::vector<std::string> words{};
    std::string buffer;
    std::stringstream ss(input);

    while (ss >> buffer)
        words.push_back(buffer);

    //Lower word to validate without cases
    std::transform(words[0].begin(), words[0].end(), words[0].begin(), ::tolower);
    
    //Parse arguments

    //Place Command
    if (words[0] == "place") {
        if (!placeCommand) {
            this->bingoCounter = 0;
        }
        this->placeCommand = true;
        placeTurn(player, words);
        
        //Continue getting commands if placecommand is continuing
        if (placeCommand) {
            getTurn(player);
        }
    }
    
    else if (this->placeCommand == true) {
        throw std::invalid_argument("Only place commands are allowed. If finished, enter \"place done\"");
    }

    //Replace command
    else if (words[0] == "replace") {
        replaceTurn(player, words);
    }

    //Pass command
    else if (words[0] == "pass") {
        //Validate number of arguments
        if (words.size() != 1) {
            throw std::invalid_argument("Invalid number of arguments");
        }

        //Lose conditions
        if (this->tilebag->isEmpty() == true) {
            player->incrementPassCount();
            std::cout << "Warning!" << std::endl;
            std::cout << "Passes available left before losing: " << (2 - player->getPassCount()) << std::endl;
        }

        if (player->getPassCount() == 2) {
            std::cout << "!!!" << std::endl;
            this->endGame = true;
            throw std::exception();
        }
    }

    //Quit command
    else if (words[0] == "quit") {
        this->endGame = true;
        throw std::exception();
    }

    //Invalid Arguement
    else {
        throw std::invalid_argument("Invalid argument in input.");
    }

    //If nothing was thrown
    this->endTurn = true;

    //Turn does not end if user saves game
    if (words[0] == "save") {
        if (words.size() != 2) {
            throw std::invalid_argument("Invalid number of arguments");
        }
        saveGame(words);
        this->endTurn = false;
        //Save then continue gameplay
    }
}

//If a place turn command was parsed, this function is called
void Game::placeTurn(Player* player, std::vector<std::string> words) {
    //Guards
    if (words[1] == "done") {
        this->endTurn = true;
        this->placeCommand = false;
        player->fillHand(tilebag);
        player->resetPassCount();
        checkGameStatus();
        this->bingoCounter = 0;
    }
    else if (words.size() != 4 && placeCommand == true) {
        throw std::invalid_argument("Invalid number of arguments. Number of arguments is not 4.");
    }

    if (words[1].length() != 1 && placeCommand == true) {
        throw std::invalid_argument("Invalid Argument for tile. Place command should be \"Place <tile letter> at <row position>");
    }
    //If passed, run command
    if (placeCommand) {
        char tile = words[1][0];
        Node* nodeToPlace = player->getTile(tile);
        this->board->placeTile(player, nodeToPlace, words[3]);
        this->bingoCounter += 1;
    }

    if (bingoCounter >= 7) {
        std::cout << "BINGO!" << std::endl;
        player->increaseScore(50);
    }
}

//If a replace turn command was parsed, this function is called
void Game::replaceTurn(Player* player, std::vector<std::string> words) {

    if (words.size() != 2) {
        throw std::invalid_argument("Invalid number of arguments.");
    }

    if (words[1].length() != 1) {
        throw std::invalid_argument("Tile passed as argument is of incorrect length (should only be 1 character long).");
    }

    char tile = words[1][0];
    try {
        player->replaceTile(this->tilebag, tile);
    } catch (std::out_of_range& e) {
        throw std::invalid_argument("There are no tiles left in the tilebag.");
    }
}

void Game::checkGameStatus() {
    if (this->player1->getHand()->size() == 0 || this->player2->getHand()->size() == 0) {
        this->endGame = true;
        throw std::exception();
    }
}

//If a save command was parsed, this function is called
void Game::saveGame(std::vector<std::string> words) {
    std::cout << "Saving game..." << std::endl;

    std::string saveGameTitle = words[1] + ".txt";
    std::ofstream saveGame(saveGameTitle);

    //Save Player details
    saveGame << player1->getName() << std::endl;
    saveGame << player1->getScore() << std::endl;
    for (int i = 0; i < player1->getHand()->size(); i++) {
        saveGame << player1->getHand()->get(i)->tile.letter << "-" << player1->getHand()->get(i)->tile.value;
        if (i == player1->getHand()->size() - 1) {
            saveGame << std::endl;
        }
        else {
            saveGame << ", ";
        }
    }

    saveGame << player2->getName() << std::endl;
    saveGame << player2->getScore() << std::endl;
    for (int i = 0; i < player2->getHand()->size(); i++) {
        saveGame << player2->getHand()->get(i)->tile.letter << "-" << player2->getHand()->get(i)->tile.value;
        if (i == player2->getHand()->size() - 1) {
            saveGame << std::endl;
        }
        else {
            saveGame << ", ";
        }
    }

    //Get Board state
    for (unsigned int i = 0; i < board->getBoard().size(); i++) {
        if (i == 0) {
            saveGame << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  " << std::endl;
            saveGame << "---------------------------------------------------------------" << std::endl;
        }

        if (i == 0) {saveGame << "A | ";}
        if (i == 1) {saveGame << "B | ";}
        if (i == 2) {saveGame << "C | ";}
        if (i == 3) {saveGame << "D | ";}
        if (i == 4) {saveGame << "E | ";}
        if (i == 5) {saveGame << "F | ";}
        if (i == 6) {saveGame << "G | ";}
        if (i == 7) {saveGame << "H | ";}
        if (i == 8) {saveGame << "I | ";}
        if (i == 9) {saveGame << "J | ";}
        if (i == 10) {saveGame << "K | ";}
        if (i == 11) {saveGame << "L | ";}
        if (i == 12) {saveGame << "M | ";}
        if (i == 13) {saveGame << "N | ";}
        if (i == 14) {saveGame << "O | ";}

        // saveGame << "Reached here." << std::endl;

        for (unsigned int j = 0; j < board->getBoard().size(); j++) {
            // saveGame << "Entered." << std::endl;
            saveGame << board->getBoard()[i][j];

            saveGame << " | ";
        }
        saveGame << std::endl;
        
    }

    //Get TileBag state
    LinkedList* tb = tilebag->getTileBag();
    for (int i = 0; i < tb->size(); i++) {
        saveGame << tb->get(i)->tile.letter << "-" << tb->get(i)->tile.value;
        if (i == tb->size() - 1) {
            saveGame << std::endl;
        }
        else {
            saveGame << ", ";
        }
    }
}

//If user selected loadgame in menu, this function is used to load game elements into play
void Game::loadGame(std::string fileName) {

    /*

    NOTE:

    IT IS ASSUMED THAT THE CONTENTS OF WHATEVER SAVE FILE TO BE LOADED INTO THE GAME IS UNTAMPERED WITH.
    AS OF RIGHT NOW THERE IS CURRENTLY NO ACTIONS IN PLACE TAKEN THAT AIM TO CHECK THAT A SAVEGAME IS VALID.

    */

    std::string line;
    std::ifstream infile;
    fileName += ".txt";
    infile.open(fileName);

    //Check if file exists
    //If thrown here, no objects created yet
    if (!infile) {
        throw std::invalid_argument("");
    }

    //Initialize player details
    std::string player1Name = ""; 
    int player1Score = 0;
    std::string player2Name =  ""; 
    int player2Score = 0;
    
    //Initialize what needs to be initalized
    this->board = new Board();
    this->endGame = false;
    this->endTurn = false;
    this->placeCommand = false;
    
    int counter = 0;
    /*
    NOTE: COUNTER INDICATES WHICH LINE REPRESENTS WHAT KIND OF INFORMATION
    */
    while (getline (infile, line)) {
        if (counter == 0) {
            player1Name = line;
        }
        else if (counter == 1) {
            player1Score = std::stoi(line);
        }
        else if (counter == 2) {
            LinkedList* player1hand = new LinkedList();
            player1hand->stringToList(line);

            //Overload constructor
            this->player1 = new Player(player1Name, player1Score, player1hand);
            delete player1hand;
        }
        else if (counter == 3) {
            player2Name = line;
        }
        else if (counter == 4) {
            player2Score = std::stoi("" + line);
        }
        else if (counter == 5) {
            LinkedList* player2hand = new LinkedList();
            player2hand->stringToList(line);
            
            //Overload constructor
            this->player2 = new Player(player2Name, player2Score, player2hand); 
            delete player2hand;
        }
        else if (counter == 23) {
            
            //Overload constructor
            this->tilebag = new TileBag(line);
        }
        //Implies rest is part of the Board
        else {
            //Loop through each step of the board from it's first to last position
            //By default this is initial position 4, final position 60 and step size 4.
            for (int i = BOARD_FIRST_POS; i <= BOARD_LAST_POS; i += BOARD_STEP_SIZE) {
                if (line[i] != ' ') {
                    std::string strPos = line[0] + std::to_string((i / 4) - 1);
                    std::cout << strPos << std::endl;
                    
                    Tile currentTile;
                    currentTile.letter = line[i];
                    currentTile.value = 0;
                    Node* currentNode = new Node(currentTile);
                    
                    try {
                        board->placeTile(currentNode, strPos);
                        delete currentNode;
                    }
                    //Invalid tile
                    catch (std::invalid_argument& e) {
                        delete currentNode;
                    }
                }
            }
        }
        counter++;
    }
    player1->printPlayer();
    player2->printPlayer();
    gameLoaded = true;
}