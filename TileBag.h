#ifndef ASSIGN2_TILEBAG
#define ASSIGN2_TILEBAG

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

class TileBag {
public:

    //Constructor and Deconstructor

    TileBag();
    ~TileBag();

    //Misc Functions

    Node* getTile();
    void printBag();
    LinkedList* getTileBag();

private:
    // Should not be called by other classes.
    void shuffle(LinkedList* nodeList);
    LinkedList* tileBag;
};

#endif