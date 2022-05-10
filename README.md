# apt-assign2

See `Class.md` for a rundown on how each file works

***

## Changelog:
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

***

## Memory leakage:
- ~~Tile~~
- ~~Node~~
- ~~LinkedList~~
- ~~TileBag~~
- ~~Board~~
- ~~Player~~
- ~~scrabble~~

***

## TODO List:
- ~~scrabbleList needs to delete the nodeList passed into it~~
- Cleanup code <-- Will never be crossed out lmao
- ~~File hierarchy~~ Probs not necessary
- ~~Error handling~~ Most are handled 
- ~~Check for memory leaks~~

***

## File specific todos:

### LinkedList:
- ~~Copy constructor~~
- ~~Print statements at addAt~~
- ~~Error handling managed in try-catches in other functions~~

### Player:
- ~~replace tile replacement index is default -1~~

### Game:
- ~~validate game moves~~
- ~~save game to .txt~~
- read game.txt to actual Game obj
- BINGO Requirement (placing all 7 tiles prints bingo)
- Check at end of player turn if they won

- Finish assignment
