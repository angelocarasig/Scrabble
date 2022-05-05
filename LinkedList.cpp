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

Node* LinkedList::get(int index) {
   if (index > length || index < 0) {
      std::cout << "Error" << std::endl;
      throw std::invalid_argument("Invalid index");
   }
   else {
      Node* currentNode = this->head;

      for (int i = 0; i < index; i++) {
         currentNode = currentNode->next;
      }

      return currentNode;
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
   else if (i < 0)     {std::cout << "Index is less than 0. Fail." << std::endl;}
   else {
      Node* currentNode = this->head;
      Node* prevNode = nullptr;

      for (int index = 0; index < i; index++) {
         if (currentNode == nullptr) {
            std::cout << "Error in position.\n";
            //TODO Raise Error
         }
         prevNode = currentNode;
         currentNode = currentNode->next;
      }
      //Insert node
      prevNode->next = node;
      node->next = currentNode;
   }

   this->length++;
}

void LinkedList::deleteFront() {
   if (this->length <= 0) {
      //TODO: Raise error
   }
   else {
      Node* newHead = this->head->next;
      delete this->head;
      this->head = newHead;      

      this->length--;
   }
}

void LinkedList::deleteBack() {
   if (this->length <= 0) {
      //TODO: Raise error
   }
   else {
      Node* currentNode = this->head;
      Node* prevNode = nullptr;
      while (currentNode->next != nullptr) {
         prevNode = currentNode;
         currentNode = currentNode->next;
      }
      std::cout << "Found last node!" << std::endl;
      currentNode->printNode();
      delete currentNode;
      currentNode = nullptr;
      prevNode->next = currentNode;

      this->length--;
   }
}

void LinkedList::deleteAt(int index) {
   if (index > length || index < 0) {
      std::cout << "Error! attempting to delete at an index that is invalid." << std::endl;
   }
   else {
      Node* currentNode = this->head;
      Node* prevNode = nullptr;
      if (index == 0) {
         deleteFront();
      } else {
         for (int i = 0; i < index; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;
         }

         prevNode->next = currentNode->next;
         delete currentNode;
         currentNode = nullptr;

         this->length--;
      }
   }
}

void LinkedList::clear() {
   Node* currentNode = this->head->next;
   
   while(currentNode != nullptr) {   
    this->head->next = currentNode->next;
    currentNode->next = nullptr;
    delete currentNode;
    currentNode = this->head->next;
   }

   delete this->head;
   this->head = nullptr;

   this->length = 0;
}

void LinkedList::printList() {
   Node* currentNode = this->head;
   
   int i = 0;
   std::cout << "\tPrinting NodeList:\nCurrent NodeList:\n";
   while (currentNode != nullptr) {
      std::cout << "Node " << i << ": ";
      std::cout << " Letter: " << currentNode->tile->letter << "    Value: " << currentNode->tile->value << std::endl;
      
      currentNode = currentNode->next;
      i++;
   }

   std::cout << "Nodelist Length: " << this->length << std::endl;
}

LinkedList* LinkedList::scrabbleList() {
   /*
   - Make new empty LinkedList
   - While originalList length > 0:
      - pick a random value from 0 to ogList length-1
      - make copy of that node and add to newList
      - delete at the given random value
   - print list
   */
   LinkedList* newLinkedList = new LinkedList();

   while (this->length > 0) {
      int randomVal = rand() % (this->length);
      std::cout << "Random Value: " << randomVal << std::endl;
      Node* newNode = new Node(*get(randomVal));
      newLinkedList->addBack(newNode);
      deleteAt(randomVal);
      std::cout << "Length: " << this->length << std::endl;
   }
   return newLinkedList;
}