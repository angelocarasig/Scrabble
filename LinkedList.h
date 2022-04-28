
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

   void addFront(int data);
   void addBack(int data);

   void deleteFront();
   void deleteBack();

   void addAt(int i);
   void deleteAt(int i);

private:
   Node* head;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H
