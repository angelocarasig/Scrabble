#include <iostream>
#include "Node.h"

Node::Node(Tile tile) {
    this->tile = tile;
    this->next = nullptr;
}

Node::Node(Node& other) {
    this->tile = other.tile;
    this->next = nullptr;       //Don't want whatever their next pointer is
}

Node::~Node() {
}

void Node::printNode() {
    std::cout << "Node: " << this->tile.letter << "-" << this->tile.value << std::endl;
}