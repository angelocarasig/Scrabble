#include "Player.h"

Player::Player(std::string playerName) {
    this->playerName = playerName;
    this->hand = new LinkedList();
}

Player::~Player() {
    delete hand;
}

std::string Player::getPlayerName() {
    return this->playerName;
}

void Player::printHand() {
    hand->printHand();
}

void Player::getTiles() {
    //Number of tiles to collect
    int handLength = 7 - (this->hand->size());

    for (int i = 0; i < handLength; i++) {
        //TODO: generate tileBag (from testNodeList) && take from front of tilebag
        // this->hand->addBack();
    }
}