#ifndef ASSIGN2_TILEBAG
#define ASSIGN2_TILEBAG

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

class TileBag {
public:
    TileBag();
    ~TileBag();

    //When this is called, will return a deep copy of the first tile in the linked list.
    //Calls deleteFront for the tile bag (deletes first element).
    Node* getTile();
    void printBag();

private:
    void shuffle(LinkedList* nodeList);
    LinkedList* tileBag;
};

#endif