
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void clear();
   int get(int i);

   void addFront(Node* node);
   void addBack(Node* node);

   void deleteFront();
   void deleteBack();

   //Adds at the given index where 0 is the start (head) node, and index -1 is the end node.
   void addAt(Node* node, int i);

   //Deletes at the given index where 0 is the start (head) node, and index -1 is the end node.
   void deleteAt(Node* node, int i);

   void printList();
   void scrabbleList();

private:
   Node* head;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H
