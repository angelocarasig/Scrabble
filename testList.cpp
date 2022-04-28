#include "LinkedList.h"
#include "Tile.h"
#include <iostream>
#include <string>

int main() {
    std::string data = "EUROPA";

    // LinkedList* testList = new LinkedList();

    for(int i = 0; i < data.length(); i++) {
        Tile* tempTile = new Tile(data[i], 0);
        std::cout << tempTile->letter << std::endl;
        delete tempTile;
    }
}