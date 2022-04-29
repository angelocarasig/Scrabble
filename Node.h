
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node {
public:

   Node(Tile* tile);
   Node(Node& other);
   void printNode();
   ~Node();

   Tile*    tile;
   Node*    next;
};

#endif // ASSIGN2_NODE_H
