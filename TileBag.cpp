#include "TileBag.h"

TileBag::TileBag() {

    std::cout << "Creating new Tile Bag!" << std::endl;
    std::string line;
    this->tileBag = new LinkedList();

    std::ifstream scrabbleTiles ("ScrabbleTiles.txt");
    
    if (scrabbleTiles.is_open()) {
        while (!scrabbleTiles.eof()) {
            getline(scrabbleTiles, line);
            std::cout << "Current Line: " << line << std::endl;
            if (line[0] != '\0') {
                Tile* currentTile = new Tile(line[0], std::stoi(line.substr(1, -1)));
                Node* currentNode = new Node(currentTile);
                this->tileBag->addBack(currentNode);
            }
        }
        scrabbleTiles.close();
    }

    std::cout << "Shuffling Tile Bag!" << std::endl;
    shuffle();
}

TileBag::~TileBag() {
    delete tileBag;
}

void TileBag::shuffle() {
    this->tileBag = this->tileBag->scrabbleList();
}

void TileBag::printBag() {
    this->tileBag->printList();
}