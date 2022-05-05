
#include "LinkedList.h"
#include "scrabbleGame.h"

#include <iostream>

#define EXIT_SUCCESS    0

void printMenu(void);
void printCredits(void);
void newGame();

int main() {
   std::cout << "Welcome to Scrabble!" << std::endl;
   std::cout << "-------------------" << std::endl;

   bool EndGame = false;
   std::string UserInput;

   printMenu();

   while (EndGame == false) {
      
      std::cin >> UserInput;

      if (UserInput == "1") {
         std::cout << "TODO: Check if the usernames are proper." <<std::endl;
         newGame();
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
   std::cin >> player1;

   std::cout << std::endl;

   std::string player2;
   std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   std::cin >> player2;

   std::cout << std::endl;

   std::cout << "Let's Play!" << std::endl;
   scrabbleGame* game = new scrabbleGame(player1, player2);
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