#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string line;
    LinkedList* scrabbleTilesList = new LinkedList();

    std::ifstream scrabbleTiles ("ScrabbleTiles.txt");
    
    if (scrabbleTiles.is_open()) {
        while (!scrabbleTiles.eof()) {
            getline(scrabbleTiles, line);
            if (line[0] == '\0') {
                std::cout << "empty line." << std::endl;
                } else {
                Tile* currentTile = new Tile(line[0], std::stoi(line.substr(1, -1)));
                Node* currentNode = new Node(currentTile);
                scrabbleTilesList->addBack(currentNode);
            }
        }
        scrabbleTiles.close();
    }
    scrabbleTilesList->printList();
    Tile* newTile = new Tile('Z', 69);
    Node* newNode = new Node(newTile);
    scrabbleTilesList->addFront(newNode);
    scrabbleTilesList->printList();

    std::cout << "Clearing list" << std::endl;
    scrabbleTilesList->clear();
    scrabbleTilesList->printList();
    }