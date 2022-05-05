#include "Tile.h"

Tile::Tile(Letter letterToAdd, Value valueOfLetter) {
    this->letter = letterToAdd;
    this->value = valueOfLetter;
}

Tile::Tile(Tile& other) {
    this->letter = other.letter;
    this->value = other.value;
}

Tile::~Tile() {
}