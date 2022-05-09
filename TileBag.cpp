#include "TileBag.h"

//Constructor.
//Initialized by reading the scrabbleTiles.txt file and randomizing the order.
TileBag::TileBag() {
    this->tileBag = new LinkedList();

    //Parses scrabbleTiles.txt to a LinkedList
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

//Deconstructor.
TileBag::~TileBag() {
    delete tileBag;
}

//Calls LinkedList scrabbleList() function.
void TileBag::shuffle(LinkedList* nodeList) {
    this->tileBag->scrabbleList();
}

//Print Function.
//Prints to the assignment specifications
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

//Returns a copy of the  head node and deletes the head node.
//Used by Player class to fill hand
Node* TileBag::getTile() {
    Node* tile = new Node(*this->tileBag->get(0));
    this->tileBag->deleteFront();
    return tile;
}

LinkedList* TileBag::getTileBag() {
    return this->tileBag;
}