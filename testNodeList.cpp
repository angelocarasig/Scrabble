#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include "TileBag.h"
#include <iostream>
#include <string>
#include <fstream>

int generateScrabbleTiles() {
    std::string line;
    LinkedList* scrabbleTilesList = new LinkedList();

    std::ifstream scrabbleTiles ("ScrabbleTiles.txt");
    
    if (scrabbleTiles.is_open()) {
        while (!scrabbleTiles.eof()) {
            getline(scrabbleTiles, line);
            if (line[0] != '\0') {
                Tile* currentTile = new Tile(line[0], std::stoi(line.substr(1, -1)));
                Node* currentNode = new Node(currentTile);
                scrabbleTilesList->addBack(currentNode);
            }
        }
        scrabbleTiles.close();
    }
    //Test printing the list
    scrabbleTilesList->printList();

    //Test adding to front of list
    std::cout << "Add at front" << std::endl;
    Tile* newTile = new Tile('Z', 69);
    Node* newNode = new Node(newTile);
    scrabbleTilesList->addFront(newNode);
    scrabbleTilesList->printList();

    //Adding at an index
    std::cout << "Add at an index" << std::endl;
    Tile* newNewTile = new Tile('X', 420);
    Node* newNewNode = new Node(newNewTile);
    scrabbleTilesList->addAt(newNewNode, 11);
    scrabbleTilesList->printList();

    //Get from a certain index
    std::cout << "Getting from index" << std::endl;
    Node* node = scrabbleTilesList->get(11); //Should grab "X"
    node->printNode();

    //Deleting front
    std::cout << "Deleting front" << std::endl;
    scrabbleTilesList->deleteFront();
    scrabbleTilesList->printList();

    //Deleting back
    std::cout << "Deleting back" << std::endl;
    scrabbleTilesList->deleteBack();
    scrabbleTilesList->printList();

    //Delete at
    std::cout << "Deleting at" << std::endl;
    scrabbleTilesList->deleteAt(10); //"X" Should be gone
    scrabbleTilesList->printList();




    //Scrabble new list
    std::cout << "Scrabble list" << std::endl;
    LinkedList* sl = scrabbleTilesList->scrabbleList();
    sl->printList();

    // //Clear list
    std::cout << "Clearing list" << std::endl;
    scrabbleTilesList->clear();
    scrabbleTilesList->printList();

    delete sl;
    delete scrabbleTilesList;
    return 0;
    }

int main() {
    TileBag* tb = new TileBag();
    tb->shuffle();
    tb->printBag();
}