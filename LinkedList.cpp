#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;
   this->length = 0;
}

LinkedList::~LinkedList() {
}

int LinkedList::size() {
   return this->length;
}

void LinkedList::clear() {
   Node* currentNode = this->head;

   // while (currentNode != nullptr) {
   //    currentNode->tile = '\0';
   // }
}