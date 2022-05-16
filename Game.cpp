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
    this->gameFinished = false;
    this->placedTile = false;
    this->bingoCounter = 0;
    this->curTurn = 1;

    this->player1->fillHand(tilebag);
    this->player2->fillHand(tilebag);
    //Comment out when not needed
    // tilebag->clearBag();
}

//Load Game Constructor
//Overloads default constructor
Game::Game(std::string fileName) {
    std::string nameOfFile = fileName;
    this->gameLoaded = false;
    this->gameFinished = false;
    while (!gameLoaded) {
        try {
                loadGame(nameOfFile);
            }
            catch (std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                std::cout << "failed to find game name." << std::endl;
                
                std::cout << "Enter filename of the save file: ";
                if (!getline(std::cin, nameOfFile)) {throw eofException();}
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

//Main game operation.
//Turn based loop.
//Ends when a player quits or the game ends.
void Game::playGame() {
    while (!endGame) {
        try {
            if (this->curTurn == 1) {
                printScore(player1);
                getTurn(player1);
                this->curTurn = 2;
            }
            checkGameStatus();
            
            if (this->curTurn == 2) {
                printScore(player2);
                getTurn(player2);
                this->curTurn = 1;
            }

            checkGameStatus();
        }
        catch (std::exception& e) {
            if (gameFinished) {printGameResults();}
            this->endGame = true;
        }
    }
}

//Gets player input.
//In loop to consider "place commands" and for input validation.
void Game::getTurn(Player* player) {

    this->endTurn = false;

    while (!endTurn) {
        try {
            std::cout << "> ";
            std::string input;
            if (!getline(std::cin, input)) {throw eofException();}
            parseInput(player, input);
        }
        catch (std::invalid_argument& e) {
            std::cout << "\nInvalid Input\n" << std::endl;
            // std::cout << e.what() << std::endl;
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
    for (unsigned int i = 0; i < words.size(); i++) {
        std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
    }
    
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
    
    //If placing, only place commands should be allowed from here on out
    else if (this->placeCommand == true && placedTile) {
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
        if (this->tilebag->isEmpty()) {
            player->incrementPassCount();
        }

        if (player->getPassCount() == 2) {
            this->endGame = true;
            this->gameFinished = true;
            throw std::exception();
        }
    }

    //Quit command
    else if (words[0] == "quit") {
        std::cout << gameFinished << std::endl;
        this->endGame = true;
        throw std::exception();
    }

    //Invalid Argument
    else if (words[0] == "save") {
        //Do nothing rn, just skips else statement
    }

    //Invalid Arguement
    else {
        throw std::invalid_argument("Invalid Input");
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
        if (!placedTile) {
            throw std::invalid_argument("Invalid Input, please place a tile down before calling this command, otherwise pass.");
        }
        if (words.size() != 2) {
            throw std::invalid_argument("Argument length != 2");
        }
        this->endTurn = true;
        this->placeCommand = false;
        player->fillHand(tilebag);
        player->resetPassCount();
        //checkGameStatus();
        this->bingoCounter = 0;
        this->placedTile = false;
    }
    else if (words.size() != 4 && placeCommand == true) {
        throw std::invalid_argument("Invalid number of arguments. Number of arguments is not 4.");
    }

    if (words[1].length() != 1 && placeCommand == true) {
        throw std::invalid_argument("Invalid Argument for tile. Place command should be \"Place <tile letter> at <row position>");
    }
    //If passed, run command
    if (placeCommand) {
        char tile = toupper(words[1][0]);
        Node* nodeToPlace = player->getTile(tile);
        std::transform(words[3].begin(), words[3].end(),words[3].begin(), ::toupper);
        this->board->placeTile(player, nodeToPlace, words[3]);
        this->bingoCounter += 1;
        this->placedTile = true;
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
    saveGame << board->getBoardString();
    

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
    if(this->curTurn == 1){
        saveGame << player1->getName() << std::endl;
    }
    else if(this->curTurn == 2){
        saveGame << player2->getName() << std::endl;
    }
    
}

//If user selected loadgame in menu, this function is used to load game elements into play
void Game::loadGame(std::string fileName) {

    /*

    NOTE:

    IT IS ASSUMED THAT THE CONTENTS OF WHATEVER SAVE FILE TO BE LOADED INTO THE GAME IS UNTAMPERED WITH.
    AS OF RIGHT NOW THERE IS CURRENTLY NO ACTIONS IN PLACE TAKEN THAT AIM TO CHECK THAT A SAVEGAME IS VALID.
    IT IS ALSO ASSUMED THAT WHEN THE GAME IS LOADED, IT IS CURRENTLY PLAYER 1's TURN
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
    bool initializedTB = false;
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
        else if (counter == 8+COLS) {
            
            //Overload constructor
            this->tilebag = new TileBag(line);
            initializedTB = true;
        }
        else if (counter == 9+COLS) {
            if (line.compare(player2->getName()) == 0){
                this->curTurn = 2;
            }
            else{
                this->curTurn = 1;
            }
        }
        //Implies rest is part of the Board
        else {
            //Loop through each step of the board from it's first to last position
            //By default this is initial position 4, final position 60 and step size 4.
            for (int i = BOARD_FIRST_POS; i <= (BOARD_STEP_SIZE*COLS); i += BOARD_STEP_SIZE) {
                if (line[i] != ' ') {
                    std::string strPos = line[0] + std::to_string((i / 4) - 1);
                    // std::cout << strPos << std::endl;
                    
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
    //If tilebag is empty
    if (!initializedTB) {
        // std::cout << "creating tilebag"
        this->tilebag = new TileBag("");
    }
    gameLoaded = true;
    std::cout << "Scrabble game successfully loaded" << std::endl;
}

void Game::checkGameStatus() {
    if (this->player1->getHand()->size() == 0 || this->player2->getHand()->size() == 0) {
        this->endGame = true;
        this->gameFinished = true;
        throw std::exception();
    }
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

    std::cout << board->getBoardString();

    std::cout << std::endl;

    std::cout << "Your hand is" << std::endl;
    player->printHand();
    std::cout << std::endl;
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