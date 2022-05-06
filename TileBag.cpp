#include "TileBag.h"

TileBag::TileBag() {
    this->tileBag = new LinkedList();

    //Adds scrabbleTiles.txt to a linked list
    std::string line;
    std::ifstream scrabbleTiles ("ScrabbleTiles.txt");
    if (scrabbleTiles.is_open()) {
        while (!scrabbleTiles.eof()) {
            getline(scrabbleTiles, line);
            if (line[0] != '\0') {
                Tile currentTile;
                currentTile.letter = line[0];
                currentTile.value = std::stoi(line.substr(1,-1));
                Node* currentNode = new Node(currentTile);
                this->tileBag->addBack(currentNode);
            }
        }
        scrabbleTiles.close();
    }

    //Shuffle linkedlist
    
    shuffle(this->tileBag);
}

TileBag::~TileBag() {
    delete tileBag;
}

void TileBag::shuffle(LinkedList* nodeList) {
    this->tileBag->scrabbleList();
}

void TileBag::printBag() {
    Node* currentNode = this->tileBag->get(0);
    while (currentNode != nullptr) {
        if (currentNode->next != nullptr) {
            std::cout << currentNode->tile.letter << "-" << currentNode->tile.value << ", ";
        } 
        else {
            std::cout << currentNode->tile.letter << "-" << currentNode->tile.value << std::endl;
        }
        currentNode = currentNode->next;
    }
}

Node* TileBag::getTile() {
    Node* tile = new Node(*this->tileBag->get(0));
    this->tileBag->deleteFront();
    return tile;
}