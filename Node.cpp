#include <iostream>
#include "Node.h"

Node::Node(Tile* tile)
{
   this->tile = tile;       
   this->next = nullptr;   //Empty on init
}

Node::~Node() {
   // std::cout << "Deleting current node" << std::endl;
   delete tile;
   
   // Dereference as it will just disconnect from the linkedList
   // If deleting node 'C':
   // A -> B -> ' '    D -> ... CORRECT VER
   // Instead of 
   // A -> B -> ' ' -> D -> ... WRONG VER (NoneType Object points to something???)
   this->next = nullptr;
}

void Node::printNode() {
   std::cout << "Current Node:" << std::endl;
   std::cout << "\tLetter: " << this->tile->letter;
   std::cout << "\tValue: " << this->tile->value << std::endl;
}

Node::Node(Node& other)
{
   // TODO
}
