#include <iostream>
#include <cctype>
#include "Game.h"

#define EXIT_SUCCESS    0

void printMenu(void);
void printCredits(void);
void newGame();
void loadGame();

/*

Compile: g++ -Wall -Werror -std=c++14 -O -o scrabble scrabble.cpp Tile.cpp Node.cpp LinkedList.cpp TileBag.cpp Player.cpp Board.cpp Game.cpp
Run: ./scrabble
*/

int main() {
   std::cout << "Welcome to Scrabble!" << std::endl;
   std::cout << "-------------------" << std::endl;

   bool EndGame = false;
   std::string UserInput;

   printMenu();

   try {
      while (EndGame == false) {
         std::cout << "> ";
         if (getline(std::cin, UserInput)) {
            // New Game
            if (UserInput == "1") {
               newGame();
               EndGame = true;
            }
            // Load Game
            else if (UserInput == "2") {
               loadGame();
               EndGame = true;
            }
            // Credits (Show student information)
            else if (UserInput == "3") {
               printCredits();
               printMenu();
            }
            // Quit
            else if (UserInput == "4") {
               EndGame = true;
            }
            // Invalid Input
            else {
               std::cout << "Invalid Input, Please Enter A Number Between 1 And 4" << std::endl;
            }
         }
         else {
            EndGame = true;
         }
      }
   }
   catch (Game::eofException& e) {
      std::cout << e.what() << std::endl;
   }
   std::cout << std::endl;
   std::cout << "Goodbye" << std::endl;
   return EXIT_SUCCESS;
}

// Prints the main menu
void printMenu(void) {  
   std::cout << "Menu" << std::endl;
   std::cout << "---" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits (Show student information)" << std::endl;
   std::cout << "4. Quit\n" << std::endl;
   std::cout << std::endl;
}

// Starts a new game
void newGame() {
   std::cout << "Starting a New Game\n" << std::endl;

   std::string player1;
   bool isAllUpper = false;
   std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
   // Loops until the inputed line is all uppercase
   while (isAllUpper == false) {
      isAllUpper = true;
      // Retreives the input
      if (!getline(std::cin, player1)) {throw Game::eofException();}
      // Loops through the input charicter by charicter and checks if they are uppercase
      for (unsigned int i = 0 ; i < player1.size() ; ++i) {
         // If the given char is not uppercase
         if (isupper(player1[i]) == false) {
            isAllUpper = false;     
         }
      }
      // Prints error if input contains lower case 
      if (isAllUpper == false){
         std::cout << "please enter a name with uppercase characters only" << std::endl;  
      }
   }

   std::cout << std::endl;

   std::string player2;
   isAllUpper = false;
   std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   // Loops until the inputed line is all uppercase
   while (isAllUpper == false) {
      isAllUpper = true;
      // Retreives the input
      if (!getline(std::cin, player2)) {throw Game::eofException();}
      // Loops through the input charicter by charicter and checks if they are uppercase
      for (unsigned int i = 0 ; i < player2.size() ; ++i) {
         // If the given char is not uppercase
         if (isupper(player2[i]) == false) {
            isAllUpper = false;     
         }
      }
      // Prints error if input contains lower case 
      if (isAllUpper == false){
         std::cout << "please enter a name with uppercase characters only" << std::endl;  
      }
   }

   std::cout << std::endl;

   std::cout << "Let's Play!" << std::endl;
   // Creates a new game object on the heap
   Game* game = new Game(player1, player2);
   game->playGame();
   // Cleanup
   delete game;
}

// Loads the game using a users file
void loadGame() {
   std::string fileName;
   std::cout << "Enter the filename from which load a game: " << std::endl;
   std::cout << "> ";
   // Gets the file name from input (relative path)
   if (!getline(std::cin, fileName)) {throw Game::eofException();}
   // Creates a game object on the heap using file name as input
   Game* game = new Game(fileName);
   game->playGame();
   // Cleanup
   delete game;
}

// Simply prints the credits
void printCredits(void) {
   std::string names[4] = {"Anton Angelo Carasig", "Henry Huynh", "Patrick Rivera", "Oliver Guzowski"};
   std::string studentID[4] = {"s3906344", "s3905838", "s3721043", "s3897734"};
   std::string email[4] = {"s3906344@student.rmit.edu.au", "s3905838@student.rmit.edu.au", "s3721043@student.rmit.edu.au", "s3897734@student.rmit.edu.au"};

   std::cout << "----------------------------------" << std::endl;

   for (int i = 0 ; i < 4 ; ++i) {
      std::cout << "Name: " << names[i] << std::endl;
      std::cout << "Student ID: " << studentID[i] << std::endl;
      std::cout << "Email: " << email[i] << std::endl;
      if (i < 3) {
         std::cout << "\n";
      }
   }
   std::cout << "----------------------------------" << std::endl;
}