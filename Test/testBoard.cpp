#include "Board.h"
#include "Node.h"

//TODO: Fix memory leaks

int main() {
    std::cout << "\n+++++++++++++++++TESTING BOARD+++++++++++++++++" << std::endl;

    Board* board = new Board();
    std::cout << "Empty Board:" << std::endl;
    board->printBoard();

    std::cout << std::endl;

    Tile tile;
    tile.letter = 'A';
    tile.value = 1;

    std::cout << "Filling Board..." << std::endl;
    Node* node = new Node(tile);
    board->placeTile(node, "A0");
    board->placeTile(node, "B1");
    board->placeTile(node, "C2");
    board->placeTile(node, "D3");
    board->placeTile(node, "E4");
    board->placeTile(node, "F5");
    board->printBoard();

    std::cout << std::endl;

    delete node;
    delete board;
    std::cout << "---------------------------------------------------" << std::endl;
}