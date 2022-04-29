#include "Tile.h"
#include <iostream>

// void Tile::buildTileMap() {
//    tileMap['A'] = 1;
//    tileMap['B'] =  3;
//    tileMap['C'] =  3;
//    tileMap['D'] =  2;
//    tileMap['E'] =  1;
//    tileMap['F'] =  4;
//    tileMap['G'] =  2;
//    tileMap['H'] =  4;
//    tileMap['I'] =  1;
//    tileMap['J'] =  8;
//    tileMap['K'] =  5;
//    tileMap['L'] =  1;
//    tileMap['M'] =  3;
//    tileMap['N'] =  1;
//    tileMap['O'] =  1;
//    tileMap['P'] =  3;
//    tileMap['Q'] =  10;
//    tileMap['R'] =  1;
//    tileMap['S'] =  1;
//    tileMap['T'] =  1;
//    tileMap['U'] =  1;
//    tileMap['V'] =  4;
//    tileMap['W'] =  4;
//    tileMap['X'] =  8;
//    tileMap['Y'] =  4;
//    tileMap['Z'] =  10;
// }

Tile::Tile(Letter letterToAdd, Value valueOfLetter) {
    this->letter = letterToAdd;
    this->value = valueOfLetter;

    std::cout << "\nNew tile generated with properties:\n";
    std::cout << "\tLetter: " << this->letter << "\tValue: " << this->value << std::endl;
}

Tile::~Tile() {}