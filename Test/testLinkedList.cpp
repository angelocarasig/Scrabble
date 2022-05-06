#include "../LinkedList.h"
#include "../Node.h"
#include "../Tile.h"

#include <iostream>
#include <string>
#include <fstream>

#define EXIT_SUCCESS 0

/*
Assuming that terminal is in main folder (not Test):

To compile, run the following command:
g++ -Wall -Werror -std=c++14 -O -o testLinkedList Test/testLinkedList.cpp LinkedList.cpp Node.cpp Tile.cpp

To run: ./testLinkedList
*/

//Add functions
void testAddFront();
void testAddBack();
void testAddAt();

//Delete functions
void testDeleteFront();
void testDeleteBack();
void testDeleteAt();

//Misc
void getScrabbleTiles();

int main() {
    // testAddFront();
    // testAddBack();
    // testAddAt();
    // testDeleteFront();
    // testDeleteBack();
    // testDeleteAt();
    getScrabbleTiles();
    return EXIT_SUCCESS;
}

void testAddFront() {
    std::cout << "\n+++++++++++++++++TESTING ADDFRONT+++++++++++++++++" << std::endl;

    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    Node* node = new Node(newTile);
    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';

    LinkedList* linkedList1 = new LinkedList();
    linkedList1->addFront(node);
    linkedList1->addFront(copyNode);

    std::cout << "LinkedList Length: " << linkedList1->size() << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "Node: B-6\nNode: A-6" << std::endl;
    std::cout << std::endl;

    std::cout << "Actual Output:" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}

void testAddBack() {
    std::cout << "\n+++++++++++++++++TESTING ADDBACK+++++++++++++++++" << std::endl;
    
    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    Node* node = new Node(newTile);
    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';

    LinkedList* linkedList1 = new LinkedList();
    linkedList1->addBack(node);
    linkedList1->addBack(copyNode);

    std::cout << "LinkedList Length: " << linkedList1->size() << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "Node: A-6\nNode: B-6" << std::endl;
    std::cout << std::endl;

    std::cout << "Actual Output:" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}

void testAddAt() {
    std::cout << "\n+++++++++++++++++TESTING ADDAT+++++++++++++++++" << std::endl;
    std::cout << "\nInserting 'G-6' between nodes 'A-6' and 'B-6'" << std::endl;

    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    Node* node = new Node(newTile);
    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';

    LinkedList* linkedList1 = new LinkedList();
    linkedList1->addBack(node);
    linkedList1->addBack(copyNode);

    Node* addAtNode = new Node(newTile);
    addAtNode->tile.letter = 'G';
    linkedList1->addAt(addAtNode, 1);

    std::cout << "LinkedList Length: " << linkedList1->size() << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "Node: A-6\nNode: G-6\nNode: B-6" << std::endl;
    std::cout << std::endl;

    std::cout << "Actual Output:" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}

void testDeleteFront() {
    std::cout << "\n+++++++++++++++++TESTING DELETEFRONT+++++++++++++++++" << std::endl;
    std::cout << "\nDeleting 'A-6' for the linked list: 'A-6', 'G-6', 'B-6'" << std::endl;
    
    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    Node* node = new Node(newTile);
    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';

    LinkedList* linkedList1 = new LinkedList();
    linkedList1->addBack(node);
    linkedList1->addBack(copyNode);

    Node* addAtNode = new Node(newTile);
    addAtNode->tile.letter = 'G';
    linkedList1->addAt(addAtNode, 1);

    std::cout << "Original LinkedList" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    linkedList1->deleteFront();
    linkedList1->printList();
    std::cout << "LinkedList Length: " << linkedList1->size() << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "Node: G-6\nNode: B-6" << std::endl;
    std::cout << std::endl;

    std::cout << "Actual Output:" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}

void testDeleteBack() {
    std::cout << "\n+++++++++++++++++TESTING DELETEBACK+++++++++++++++++" << std::endl;
    std::cout << "\nDeleting 'B-6' for the linked list: 'A-6', 'G-6', 'B-6'" << std::endl;
    
    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    Node* node = new Node(newTile);
    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';

    LinkedList* linkedList1 = new LinkedList();
    linkedList1->addBack(node);
    linkedList1->addBack(copyNode);

    Node* addAtNode = new Node(newTile);
    addAtNode->tile.letter = 'G';
    linkedList1->addAt(addAtNode, 1);

    std::cout << "Original LinkedList" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    linkedList1->deleteBack();
    linkedList1->printList();
    std::cout << "LinkedList Length: " << linkedList1->size() << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "Node: A-6\nNode: G-6" << std::endl;
    std::cout << std::endl;

    std::cout << "Actual Output:" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}

void testDeleteAt() {
    std::cout << "\n+++++++++++++++++TESTING DELETEAT+++++++++++++++++" << std::endl;
    std::cout << "\nDeleting 'G-6' for the linked list: 'A-6', 'G-6', 'B-6'" << std::endl;
    
    Tile newTile;
    newTile.letter = 'A';
    newTile.value = 6;

    Node* node = new Node(newTile);
    Node* copyNode = new Node(*node);
    copyNode->tile.letter = 'B';

    LinkedList* linkedList1 = new LinkedList();
    linkedList1->addBack(node);
    linkedList1->addBack(copyNode);

    Node* addAtNode = new Node(newTile);
    addAtNode->tile.letter = 'G';
    linkedList1->addAt(addAtNode, 1);

    std::cout << "Original LinkedList" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    linkedList1->deleteAt(1);

    std::cout << "LinkedList Length: " << linkedList1->size() << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "Node: A-6\nNode: B-6" << std::endl;
    std::cout << std::endl;

    std::cout << "Actual Output:" << std::endl;
    linkedList1->printList();
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}

void getScrabbleTiles() {
    std::cout << "\n+++++++++++++++++TESTING GETSCRABBLETILES+++++++++++++++++" << std::endl;

    LinkedList* linkedList1 = new LinkedList();

    std::string line;

    std::ifstream scrabbleTiles ("ScrabbleTiles.txt");
    
    if (scrabbleTiles.is_open()) {
        while (!scrabbleTiles.eof()) {
            getline(scrabbleTiles, line);
            if (line[0] != '\0') {
                Tile currentTile;
                currentTile.letter = line[0];
                currentTile.value = std::stoi(line.substr(1,-1));
                Node* currentNode = new Node(currentTile);
                linkedList1->addBack(currentNode);
            }
        }
        scrabbleTiles.close();
    }

    linkedList1->printList();
    std::cout << "Length: " << linkedList1->size() << std::endl;

    std::cout << "\n\n\nScrabbling List...\n\n\n" << std::endl;

    linkedList1->scrabbleList();
    linkedList1->printList();
    std::cout << "Length: " << linkedList1->size() << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Clearing NodeList..." << std::endl;
    linkedList1->clear();
    std::cout << "---------------------------------------------------" << std::endl;
    
    delete linkedList1;
}