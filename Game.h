#ifndef ASSIGN2_GAME
#define ASSIGN2_GAME
#include <string>
#include "TileBag.h"
#include "Player.h"
#include "Board.h"

class Game {
public:

   // Constructor/Destructor
   Game(std::string player1, std::string player2);
   ~Game();


    
private:
    Player* player1;
    Player* player2;
    TileBag* tilebag;
    Board* board;
};

#endif // ASSIGN2_GAME