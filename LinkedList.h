
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

   void addAt(int i);
   void deleteAt(int i);

   void printList();

private:
   Node* head;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H
