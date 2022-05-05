
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <random>

class LinkedList {
public:

   LinkedList();
   LinkedList(LinkedList& other);
   ~LinkedList();

   int size();
   void clear();
   Node* get(int i);

   void addFront(Node* node);
   void addBack(Node* node);

   void deleteFront();
   void deleteBack();
   
   //Pops head element
   Node* pop();

   //Adds at the given index where 0 is the start (head) node, and index -1 is the end node.
   void addAt(Node* node, int i);

   //Deletes at the given index where 0 is the start (head) node, and index -1 is the end node.
   void deleteAt(int i);

   void printList();
   void printHand();

   //Should return a new, 'scrabbled' list with all tiles in a random order
   LinkedList* scrabbleList();

private:
   Node* head;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H
