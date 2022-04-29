#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string data = "europa";

    LinkedList* testList = new LinkedList();
    Node* prevNode = nullptr;

    Tile buildTileMap();

    for(unsigned int i = 0; i < data.length(); i++) {
        Tile* tempTile = new Tile(toupper(data[i]));
        std::cout << "Tile: " << tempTile->letter;
        std::cout << "\tValue: " << tempTile->value << std::endl;
        Node* tempNode = new Node(tempTile, prevNode);

        testList->addBack(tempNode);
    }

    testList->printList();
    delete testList;
}