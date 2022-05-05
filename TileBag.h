#ifndef ASSIGN2_TILEBAG
#define ASSIGN2_TILEBAG

#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"
#include <iostream>
#include <string>
#include <fstream>

class TileBag {
public:
    TileBag();
    ~TileBag();
    void shuffle();
    void printBag();
private:
    LinkedList* tileBag;
};

#endif