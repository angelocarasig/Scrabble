#include "Player.h"
#include "TileBag.h"

//Constructor.
//Player's hand is initially empty. Should call fillHand() once game starts.
Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
    this->hand = new LinkedList();
}

//Deconstructor
Player::~Player() {
    delete hand;
}

//Returns player's name.
std::string Player::getName() {
    return this->name;
}

//Returns player's score.
int Player::getScore() {
    return this->score;
}

//Returns player's hand.
LinkedList* Player::getHand() {
    return this->hand;
}

//Print Function.
//Should only be used for debugging purposes.
void Player::printPlayer() {
    std::cout << "Player: " << this->name << " Score: " << this->score << " Hand: " << std::endl;
    this->hand->printList();
}

void Player::increaseScore(int value) {
    this->score += value;
}

void Player::printHand() {
    for (int i = 0; i < this->hand->size(); i++) {
        std::cout << this->hand->get(i)->tile.letter << "-" << this->hand->get(i)->tile.value;
        if (i == this->hand->size() - 1) {
            std::cout << std::endl;
        }
        else {
            std::cout << ", ";
        }
    }
}

//Initialize player's hand
void Player::fillHand(TileBag* tb) {
    while (this->hand->size() < SCRABBLE_HAND) {
        Node* tile = tb->getTile();
        this->hand->addBack(tile);
    }
}

//Replace a tile by removing from hand and grabbing a new one from the Scrabble LinkedList.
void Player::replaceTile(TileBag* tb, char letter) {
    letter = toupper(letter);
    //Find position of tile to replace from hand
    int replacementIndex = -1;
    Tile tile;
    tile.letter = letter;
    tile.value = 0;
    
    Node* tempTile = new Node(tile);
    replacementIndex = this->hand->search(tempTile);

    if (replacementIndex == -1) {
        throw std::invalid_argument("Tile does not exist in player hand.");
    }

    delete tempTile;

    //Delete from hand
    this->hand->deleteAt(replacementIndex);

    //Get new tile and put in original index
    Node* newTile = tb->getTile();
    this->hand->addAt(newTile, replacementIndex);
}

Node* Player::getTile(char letter) {
    letter = toupper(letter);
    //Find position of tile to replace from hand
    int replacementIndex = -1;
    Tile tile;
    tile.letter = letter;
    tile.value = 0;
    
    Node* tempTile = new Node(tile);
    Node* returnTile = nullptr;
    replacementIndex = this->hand->search(tempTile);

    if (replacementIndex == -1) {
        throw std::invalid_argument("Tile entered does not exist in the player's hand.");
    }
    else {
        returnTile = this->hand->get(replacementIndex);
    }

    delete tempTile;
    return returnTile;
}

void Player::removeTile(Node* node) {
    //Find position of tile to replace from hand
    int replacementIndex = -1;

    replacementIndex = this->hand->search(node);

    if (replacementIndex == -1) {
        throw std::invalid_argument("Tile does not exist in player hand.");
    }

    //Delete from hand
    this->hand->deleteAt(replacementIndex);
}