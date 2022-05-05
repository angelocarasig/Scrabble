#include <iostream>
#include "Node.h"

Node::Node(Tile* tile) {
   this->tile = tile;       
   this->next = nullptr;   //Empty on init
}

Node::Node(Node &other) {
   this->tile = new Tile(*other.tile);
   this->next = nullptr;
}

Node::~Node() {
   delete tile;
   this->next = nullptr;
}

void Node::printNode() {
   std::cout << "Current Node:" << std::endl;
   std::cout << "\tLetter: " << this->tile->letter;
   std::cout << "\tValue: " << this->tile->value << std::endl;
}