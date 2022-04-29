#include <iostream>
#include "Node.h"

Node::Node(Tile* tile)
{
   this->tile = tile;
   this->next = nullptr; //Empty on init
}

Node::~Node() {
   std::cout << "Deleting current node" << std::endl;
   delete tile;

   // Dereference as it will just disconnect from the linkedList
   // If deleting node 'C':
   // A -> B -> ' '    D -> ...
   // Instead of 
   // A -> B -> ' ' -> D -> ...
   this->next = nullptr;
}

Node::Node(Node& other)
{
   // TODO
}
