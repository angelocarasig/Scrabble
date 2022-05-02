#include <string>

class scrabbleGame {
public:

   // Constructor/Destructor
   scrabbleGame(std::string player1, std::string player2, std::string gameName);
   ~scrabbleGame();

   std::string getPlayer1();
   std::string getPlayer2();
   std::string getGameName();
    
    
private:
    std::string player1;
    std::string player2;
    std::string gameName;
    

};

