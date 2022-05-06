#include "Game.h"

Game::Game(std::string player1, std::string player2) {
    this->player1 = new Player(player1);
    this->player2 = new Player(player2);

    this->tilebag = new TileBag();
    this->board = new Board();
}

Game::~Game() {
    delete player1;
    delete player2;
    delete tilebag;
    delete board;
}

void Game::playGame() {
    bool endGame = false;

    while (!endGame) {
        std::cout << std::endl;
        std::cout << player1->getName() << ", it's your turn" << std::endl;
        std::cout << "Score for " << player1->getName() << ": " << player1->getScore() << std::endl;
        std::cout << "Score for " << player2->getName() << ": " << player2->getScore() << std::endl;

        board->printBoard();
        
        std::cout << std::endl;

        std::string input;
        getline(std::cin, input);
        readInput(input);

        if (input == "finish") {
            endGame = true;
        }


    }
}

void Game::readInput(std::string input) {
    //Split the words into a vector
    std::vector<std::string> words{};
    std::string buffer;
    std::stringstream ss(input);

    while (ss >> buffer)
        words.push_back(buffer);


    std::transform(words[0].begin(), words[0].end(), words[0].begin(), ::tolower);
    
    if (words[0] == "place") {
        //First validate number of arguments
        if (words.size() != 4) {
            std::cout << "Invalid number of arguments." << std::endl;
        }
        else {
            std::cout << "Pass! Command: " << std::endl;
            std::cout << input << std::endl;
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
    else {
        std::cout << "Invalid argument." << std::endl;
    }
}