#include "Game.h"

Game::Game(std::string player1, std::string player2) {
    this->player1 = new Player(player1);
    this->player2 = new Player(player2);

    this->tilebag = new TileBag();
    this->board = new Board();
    this->endGame = false;

    this->player1->fillHand(tilebag);
    this->player2->fillHand(tilebag);
}

Game::~Game() {
    delete player1;
    delete player2;
    delete tilebag;
    delete board;
}

void Game::playGame() {
    while (!endGame) {
        try {
            getTurn(player1);
            getTurn(player2);
        }
        catch (std::exception& e) {
            std::cout << "Ending game..." << std::endl;
            std::cout << std::endl;
        }
    }
}

void Game::getTurn(Player* player) {
    std::cout << std::endl;
    std::cout << player->getName() << ", it's your turn" << std::endl;
    std::cout << "Score for " << this->player1->getName() << ": " << player1->getScore() << std::endl;
    std::cout << "Score for " << this->player2->getName() << ": " << player2->getScore() << std::endl;

    board->printBoard();
    
    std::cout << std::endl;

    std::cout << "Your hand is" << std::endl;
    player->printHand();

    std::cout << std::endl;

    std::string input;
    getline(std::cin, input);
    try {
        readInput(player, input);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        readInput(player, input);
    }
}

void Game::readInput(Player* player, std::string input) {
    //Split the words into a vector
    std::vector<std::string> words{};
    std::string buffer;
    std::stringstream ss(input);

    while (ss >> buffer)
        words.push_back(buffer);

    //Lower word to validate without cases
    std::transform(words[0].begin(), words[0].end(), words[0].begin(), ::tolower);
    
    if (words[0] == "place") {
        //First validate number of arguments
        if (words.size() != 4) {
            std::cout << "Invalid number of arguments." << std::endl;
        }
        else {
            std::cout << "Pass! Command: " << std::endl;
            std::cout << input << std::endl;

            if (words[1].length() == 1) {
                std::cout << "Attempting to place..." << std::endl;
                try {
                    char tile = words[1][0];
                    Node* nodeToPlace = player->getTile(tile);
                    if (words[3].length() != 2) {
                        std::cout << "Invalid Area to place at." << std::endl;
                    }
                    else {
                        std::cout << "TODO: PlaceTile command" << std::endl;
                        this->board->placeTile(player, nodeToPlace, words[3]);
                        player->replaceTile(tilebag, nodeToPlace->tile.letter);
                    }
                } catch (std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
            } else {
                std::cout << "Trying to place a tile but does not exist in player's hand." << std::endl;
            }
        }
    } 

    else if (words[0] == "replace") {
        //First validate number of arguments
        if (words.size() != 2) {
            std::cout << "Invalid number of arguments." << std::endl;
        }
        else {
            std::cout << "Pass! Command: " << std::endl;
            std::cout << input << std::endl;
            if (words[1].length() == 1) {
                std::cout << "Attempting to replace..." << std::endl;
                try {
                    char tile = words[1][0];
                    player->replaceTile(tilebag, tile);
                } catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            } else {
                std::cout << "Trying to replace a tile but argument passed is not valid." << std::endl;
            }
        }

    }
    else if (words[0] == "pass") {
        //Validate number of arguments
        if (words.size() != 1) {
            std::cout << "Invalid number of arguments." << std::endl;
        }
        else {
            std::cout << "Pass! Command: " << std::endl;
            std::cout << input << std::endl;
        }
        
    }
    else if (words[0] == "quit") {
        this->endGame = true;
        throw std::exception();
    }
    else {
        std::cout << "Invalid argument." << std::endl;
    }
}