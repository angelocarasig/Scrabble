#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!" << endl;
    MyFile << "test2";
    // Close the file
    MyFile.close();
    return EXIT_SUCCESS;
}