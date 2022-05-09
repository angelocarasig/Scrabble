#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

    std::string line;
    std::ifstream infile;
    infile.open("savegame.txt");

    //Check if file exists
    if (!infile) {
        throw std::invalid_argument("");
    }

    string val = "123a43";
    int val2 = std::stoi(val);
    std::cout << val2 << std::endl;
    
    int counter = 0;
    while (getline (infile, line)) {
        // std::cout << line << std::endl;
        if (counter == 0) {
            std::cout << "Player 1: " << line << std::endl;
        }
        else if (counter == 1) {
            std::cout << "Player 1 Score: " << line << std::endl;
        }
        else if (counter == 2) {
            std::cout << "Player 1 Hand: " << line << std::endl;
        }
        else if (counter == 3) {
            std::cout << "Player 2: " << line << std::endl;
        }
        else if (counter == 4) {
            std::cout << "Player 2 Score: " << line << std::endl;
        }
        else if (counter == 5) {
            std::cout << "Player 2 Hand: " << line << std::endl;
        }
        else if (counter == 14) {
            std::cout << "Tile bag: " << line << std::endl;
        }
        else {
            //Part of the board
            // std::cout << line[0] << std::endl;
            for (int i = 4; i <= 56; i+=4) {
                if (line[i] == ' ') {
                    //blank space, don't add
                    std::cout << "#";
                }
                else {
                    if (line[0] != '-' && line[0] != ' ') {
                        std::cout << "Row: " << line[0] << " ";
                        std::cout << "Col: " << (i/4) << std::endl;
                        std::cout << "Value: " << line[i] << std::endl;
                    }
                }
            }
            std::cout << std::endl;
        }
        counter++;
    }


    return EXIT_SUCCESS;
}