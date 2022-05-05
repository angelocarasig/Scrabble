
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Letter type
typedef char Letter;

// Define a Value type
typedef int Value;

class Tile {
public:
   // void buildTileMap();
   Tile(Letter letterToAdd, Value valueOfLetter);
   Tile(Tile& other);
   ~Tile();
   Letter letter;
   Value  value;

   // std::map<Letter, Value> tileMap;   
};

#endif // ASSIGN2_TILE_H
