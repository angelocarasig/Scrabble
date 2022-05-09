#include <iostream>
#include "Game.h"

#define EXIT_SUCCESS    0

void printMenu(void);
void printCredits(void);
void newGame();

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
         std::cout << "TODO: Check if the usernames are proper." <<std::endl;
         newGame();
         // std::cout << "printing menu..." << std::endl;
         printMenu();
      }
      else if (UserInput == "2") {
         std::cout << "TODO: Implement load game feature." << std::endl;
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
   std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
   getline(std::cin, player1);

   std::cout << std::endl;

   std::string player2;
   std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   getline(std::cin, player2);

   std::cout << std::endl;

   std::cout << "Let's Play!" << std::endl;
   Game* game = new Game(player1, player2);
   game->playGame();
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