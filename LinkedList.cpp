#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
   this->head = nullptr;
   this->length = 0;
}

LinkedList::~LinkedList() {
   for (Node* currentNode = this->head; currentNode != nullptr; currentNode = currentNode->next) {
      delete currentNode;
   }
}

int LinkedList::size() {
   return this->length;
}

void LinkedList::addFront(Node* node) {
   Node* currentNode = this->head;

   //Check for empty nodelist
   if (currentNode == nullptr) {
      this->head = node;
      node->next = nullptr;
   } else {
      Node* temp = currentNode;
      this->head = node;
      node->next = temp;
   }

   this->length++;
}

void LinkedList::addBack(Node* node) {
   Node* currentNode = this->head;
   
   //Check for empty nodelist
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
   this->length++;
}

void LinkedList::addAt(Node* node, int i) {
   if (i == 0)         {addFront(node);}
   else if (i == -1)   {addBack(node);}
   else {
      Node* currentNode = this->head;
      Node* prevNode = nullptr;

      for (int index = 0; index < i; index++) {
         // std::cout << index << std::endl;
         if (currentNode == nullptr) {
            std::cout << "Error in position.\n";
            //TODO Raise Error
         }
         prevNode = currentNode;
         currentNode = currentNode->next;
      }
      std::cout << "Inserting node.";
      // currentNode->printNode();
      prevNode->next = node;
      node->next = currentNode;
   }

   this->length++;
}

void LinkedList::clear() {
   Node* currentNode = head->next;
   
   while(currentNode != nullptr) {   
    head->next = currentNode->next;
    currentNode->next = nullptr;
    delete currentNode;
    currentNode = head->next;
   }

   delete this->head;
   this->head = nullptr;

   this->length = 0;
}

void LinkedList::printList() {
   Node* currentNode = this->head;
   
   int i = 1;
   std::cout << "\n\tPrinting NodeList:\nCurrent NodeList:\n";
   while (currentNode != nullptr) {
      std::cout << "Node " << i << ":\t";
      std::cout << "Letter: " << currentNode->tile->letter << "\tValue: " << currentNode->tile->value << std::endl;
      
      currentNode = currentNode->next;
      i++;
   }

   std::cout << "Nodelist Length: " << this->length << std::endl;
}

void LinkedList::scrabbleList() {

}