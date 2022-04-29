#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
   this->head = nullptr;
   this->length = 0;
}

LinkedList::~LinkedList() {
   for (Node* currentNode = this->head; currentNode != nullptr; currentNode = currentNode->next) {
      std::cout << "Deleting node..." << std::endl;
      delete currentNode;
   }
}

int LinkedList::size() {
   return this->length;
}

void LinkedList::clear() {
}

void LinkedList::addBack(Node* node) {
   Node* currentNode = this->head;
   
   //If first node to add
   if (currentNode == nullptr) {
      this->head = node;
      node->next = nullptr;
   } else {
      Node* prevNode = nullptr;
         
      while (currentNode != nullptr) {
         prevNode = currentNode;
         currentNode = currentNode->next;
      }

      prevNode->next = node;
      node->next = nullptr;
   }
}

void LinkedList::printList() {
   Node* currentNode = this->head;
   
   int i = 1;

   std::cout << "Current NodeList:\n";
   while (currentNode != nullptr) {
      std::cout << "Node " << i << ":\t";
      std::cout << "Letter: " << currentNode->tile->letter << "\tValue: " << currentNode->tile->value << std::endl;
      
      currentNode = currentNode->next;
      i++;
   }
}