#include "scrabbleGame.h"

#include <iostream>
#include <string>

scrabbleGame::scrabbleGame(std::string player1, std::string player2, std::string gameName) {
   this->player1 = player1;
   this->player2 = player2;
   this->gameName = gameName;
}

scrabbleGame::~scrabbleGame() {

}

std::string scrabbleGame::getPlayer1() {
    return player1;
}

std::string scrabbleGame::getPlayer2() {
    return player2;
}

std::string scrabbleGame::getGameName() {
    return gameName;
}

