#include "Player.h"
#include "TileBag.h"

Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
    this->hand = new LinkedList();
}

std::string Player::getName() {
    return this->name;
}

int Player::getScore() {
    return this->score;
}

LinkedList* Player::getHand() {
    return this->hand;
}

Player::~Player() {
    delete hand;
}

void Player::printPlayer() {
    std::cout << "Player: " << this->name << " Score: " << this->score << " Hand: " << std::endl;
    this->hand->printList();
}

void Player::fillHand(TileBag* tb) {
    while (this->hand->size() < SCRABBLE_HAND) {
        Node* tile = tb->getTile();
        this->hand->addBack(tile);
    }
}

//Replace a tile by removing from hand and grabbing a new one from the scrabble list
void Player::replaceTile(TileBag* tb, char letter) {
    letter = toupper(letter);
    //Find position of tile to replace from hand
    int replacementIndex = -1;
    Tile tile;
    tile.letter = letter;
    tile.value = 0;
    
    Node* tempTile = new Node(tile);
    replacementIndex = this->hand->search(tempTile);

    //TODO: If replacement index = -1, throw error

    std::cout << "Deleting at index: " << replacementIndex << std::endl;
    delete tempTile;

    //Delete from hand
    this->hand->deleteAt(replacementIndex);

    //Get new tile and put in original index
    Node* newTile = tb->getTile();
    this->hand->addAt(newTile, replacementIndex);
}