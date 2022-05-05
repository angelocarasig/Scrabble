#ifndef ASSIGN2_PLAYER
#define ASSIGN2_PLAYER

#include <string>
#include <iostream>

#include <LinkedList.h>

class Player {
public:
    Player(std::string playerName);
    ~Player();

    std::string getPlayerName();
    void printHand();
    void getTiles();

private:
    std::string playerName;
    LinkedList* hand;
};

#endif // ASSIGN2_PLAYER
