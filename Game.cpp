#include "Game.h"

Game::Game(std::string player1, std::string player2) {
    this->player1 = new Player(player1);
    this->player2 = new Player(player2);

    this->tilebag = new TileBag();
    this->board = new Board();
    this->endGame = false;
    this->endTurn = false;
    this->placeCommand = false;

    this->player1->fillHand(tilebag);
    this->player2->fillHand(tilebag);
}

Game::Game(std::string fileName) {
    try {
        loadGame(fileName);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

Game::~Game() {
    delete player1;
    delete player2;
    delete tilebag;
    delete board;
}

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

void Game::playGame() {
    while (!endGame) {
        try {
            printScore(player1);
            getTurn(player1);
            
            printScore(player2);
            getTurn(player2);
        }
        catch (std::exception& e) {
            //std::cout << "Ending game..." << std::endl;
            std::cout << "Game Over" << std::endl;
            std::cout << "Score for " << this->player1->getName() << ": " << this->player1->getScore() << std::endl;
            std::cout << "Score for " << this->player2->getName() << ": " << this->player2->getScore() << std::endl;

            if (this->player1->getScore() > this->player2->getScore()) {
                std::cout << "Player " << this->player1->getName() << " won!" << std::endl;
            }
            else if (this->player1->getScore() < this->player2->getScore()) {
                std::cout << "Player " << this->player2->getName() << " won!" << std::endl;
            }

            this->endGame = true;
            std::cout << std::endl;
        }
    }
}

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

        if (this->tilebag->isEmpty() == true) {
            player->incrementPassCount();
        }

        if (player->getPassCount() == 2) {
            this->endGame = true;
            throw std::exception();
        }
        //Continues with rest of code as they are just else ifs
    }

    //Save Game Command
    else if (words[0] == "save") {
        //Do nothing for now
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

    if (words[0] == "save") {
        if (words.size() != 2) {
            throw std::invalid_argument("Invalid number of arguments");
        }
        saveGame(words);
        this->endTurn = false;
        //Save then continue gameplay
    }
}


void Game::placeTurn(Player* player, std::vector<std::string> words) {
    //Guards
    if (words[1] == "done") {
        this->endTurn = true;
        this->placeCommand = false;
        player->fillHand(tilebag);
        checkGameStatus();
    }
    else if (words.size() != 4 && placeCommand == true) {
        throw std::invalid_argument("Invalid number of arguments. Number of arguments is not 4.");
    }

    // if (placeCommand == true) {
    //     std::cout << "TODO: Fix this throw error." << std::endl;
    //     throw std::invalid_argument("Invalid Area to place at.");
    // }

    if (words[1].length() != 1 && placeCommand == true) {
        throw std::invalid_argument("Invalid Argument for tile. Place command should be \"Place <tile letter> at <row position>");
    }
    //If passed, run command
    if (placeCommand) {
        char tile = words[1][0];
        Node* nodeToPlace = player->getTile(tile);
        this->board->placeTile(player, nodeToPlace, words[3]);
    }
}

void Game::replaceTurn(Player* player, std::vector<std::string> words) {

    if (words.size() != 2) {
        throw std::invalid_argument("Invalid number of arguments.");
    }

    if (words[1].length() != 1) {
        throw std::invalid_argument("Tile passed as argument is of incorrect length (should only be 1 character long).");
    }

    char tile = words[1][0];
    player->replaceTile(this->tilebag, tile);
}

void Game::checkGameStatus() {
    if (this->player1->getHand()->size() == 0 || this->player2->getHand()->size() == 0) {
        this->endGame = true;
        throw std::exception();
    }
}

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

void Game::loadGame(std::string fileName) {
    std::string line;
    std::ifstream infile;
    fileName += ".txt";
    infile.open(fileName);
    std::string player1name = ""; int player1score = 0;
    std::string player2name =  ""; int player2score = 0;
    this->board = new Board();

    //Check if file exists
    if (!infile) {
        throw std::invalid_argument("");
    }
    
    int counter = 0;
    while (getline (infile, line)) {
        // std::cout << line << std::endl;
        if (counter == 0) {
            player1name = line;
        }
        else if (counter == 1) {
            player1score = std::stoi(line);
        }
        else if (counter == 2) {
            LinkedList* player1hand = new LinkedList();
            player1hand->StringToList(line);
            this->player1 = new Player(player1name, player1score, player1hand);
            std::cout << "player1 loaded." << std::endl;
        }
        else if (counter == 3) {
            player2name = line;
        }
        else if (counter == 4) {
            player2score = std::stoi("" + line);
        }
        else if (counter == 5) {
            LinkedList* player2hand = new LinkedList();
            player2hand->StringToList(line);
            this->player2 = new Player(player2name, player2score, player2hand); 
            std::cout << "player2 loaded." << std::endl;
        }
        else if (counter == 23) {
            this->tilebag = new TileBag(line);
            std::cout << "tilebag loaded." << std::endl;
        }
        else {
            std::cout << "In else:" << std::endl;
            std::cout << line << std::endl;
            for (int i = 4; i <= 60; i+=4) {
                if (line[i] != ' ') {
                    std::string strpos = line[0] + std::to_string((i / 4) - 1);
                    std::cout << strpos << std::endl;
                    Tile currentTile;
                    currentTile.letter = line[i];
                    currentTile.value = 0;
                    Node* currentNode = new Node(currentTile);
                    try {
                        board->placeTile(currentNode, strpos);
                    }
                    catch (std::invalid_argument& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
            }
        }
        counter++;
    }
    board->printBoard();
    this->endGame = false;
    this->endTurn = false;
    this->placeCommand = false;
}