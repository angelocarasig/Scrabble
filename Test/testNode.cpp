#include "../Node.h"

#include <iostream>

#define EXIT_SUCCESS 0

/*
Assuming that terminal is in main folder (not Test):

Compile: g++ -Wall -Werror -std=c++14 -O -o testNode Test/testNode.cpp Node.cpp Tile.cpp

Run: ./testNode
*/

int main() {
    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;
    
    Node* node = new Node(newTile);
    node->printNode();

    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';
    copyNode->printNode();

    delete node;
    delete copyNode;
    
    return EXIT_SUCCESS;
}