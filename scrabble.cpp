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

   while (EndGame == false) {
      
      getline(std::cin, UserInput);

      if (UserInput == "1") {
         newGame();
         printMenu();
      }
      else if (UserInput == "2") {
         loadGame();
         printMenu();
      }
      else if (UserInput == "3") {
         printCredits();
         printMenu();
      }
      else if (UserInput == "4") {
         std::cout << "\nGoodbye" << std::endl;
         EndGame = true;
      }
      else {
         std::cout << "Entered Else" << std::endl;
         std::cout << "Invalid Input" << std::endl;
      }
   }
   return EXIT_SUCCESS;
}

void printMenu(void) {
   std::cout << std::endl;
   std::cout << "Menu" << std::endl;
   std::cout << "---" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits (Show student information)" << std::endl;
   std::cout << "4. Quit\n" << std::endl;
   std::cout << std::endl;
}

void newGame() {
   std::cout << "Starting a New Game\n" << std::endl;

   std::string player1;
   bool foundUpper1 = false;
   std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
   while (foundUpper1 == false) {
      foundUpper1 = true;
      getline(std::cin, player1);
      for (unsigned int i = 0 ; i < player1.size() ; ++i) {
         if (isupper(player1[i]) == false) {
            foundUpper1 = false;     
         }
      }
      if (foundUpper1 == false){
         std::cout << "please enter a name with uppercase characters only" << std::endl;  
      }
   }

   std::cout << std::endl;

   std::string player2;
   bool foundUpper2 = false;
   std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   while (foundUpper2 == false) {
      foundUpper2 = true;
      getline(std::cin, player2);
      for (unsigned int i = 0 ; i < player2.size() ; ++i) {
         if (isupper(player2[i]) == false) {
            foundUpper2 = false;     
         }
      }
      if (foundUpper2 == false){
         std::cout << "please enter a name with uppercase characters only" << std::endl;  
      }
   }

   std::cout << std::endl;

   std::cout << "Let's Play!" << std::endl;
   Game* game = new Game(player1, player2);
   game->playGame();
   delete game;
}

void loadGame() {
   std::string fileName;
   std::cout << "Loading game..." << std::endl;
   std::cout << "Enter filename of the save file: ";
   getline(std::cin, fileName);
   Game* game = new Game(fileName);
   delete game;
}

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