# apt-assign2

Basic Structure

Player:
- name
- Hand is linkedlist of tiles
- Score

TileBag:
- nodeList of shuffled tiles

Board:
- tile display
- grid coords
- vector to store board

Game:
- Board
- Players 1 & 2
- Tile bag
- loadgame function

Changelog:
    - Created Tile, Node, LinkedList files and testNodeList file which tests implementation
    - Tile and Node class functions implemented
    - LinkedList functions implemented (unchecked for memory leaks)
    - TileBag adapted from testNodeList
    - TileBag shuffle function added
    - scrabble and scrabbleGame classes files created
    - scrabbleGame constructor created (creates Player objects)
    - scrabble menu, credits and newGame (partial) created
    - Added board, player and game files
    - Added unit testing various .cpp files in Test folder
    - Now working on scrabble.cpp -> New game read command and validate input length finished

TODO List:
    ~~- scrabbleList needs to delete the nodeList passed into it~~
    ~~- Cleanup code~~
    - File hierarchy
    - Error handling
    - Check for memory leaks


File specific todos:

LinkedList:
    - Copy constructor
    - Print statements at addAt
    - Error handling managed in try-catches in other functions


Player:
    - replace tile replacement index is default -1

Game:
    - validate game moves

- Finish assignment
