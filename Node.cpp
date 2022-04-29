
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = next;
}

Node::~Node() {
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
