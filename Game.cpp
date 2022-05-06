#include "Game.h"

#include <iostream>
#include <string>

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

