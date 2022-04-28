
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = nullptr;
}



Node::Node(Node& other)
{
   // TODO
}
