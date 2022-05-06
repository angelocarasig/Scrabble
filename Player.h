#ifndef ASSIGN2_PLAYER
#define ASSIGN2_PLAYER

#include <string>
#include <iostream>
#include "LinkedList.h"
#include "TileBag.h"

#define SCRABBLE_HAND 7

class Player {
public:

    //Constructor and Deconstructor

    Player(std::string name);
    ~Player();

    //Get methods

    std::string getName();
    int getScore();
    LinkedList* getHand();

    //Game functions

    void fillHand(TileBag* tb);
    void replaceTile(TileBag* tb, char letter);
    
    //Misc functions
    
    void printPlayer();

private:
    std::string name;
    int         score;
    LinkedList* hand;
};

#endif