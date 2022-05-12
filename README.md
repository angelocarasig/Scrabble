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
    - Game save function added
    - Game load function also added
    - expanded board size to 15
    - reformatted board print functions to loops
    - added game bingo function
    - added game checkgameconditions to check if a player has won

***

## Checklist:
    Game:
    - Print welcome message on launch
    - 4 menu options followed by user prompt
    - can create a game
    - start of each player's turn should show current game state (player scores, board, etc.)
    - player can place tile onto board          (place <tile> at <grid location>)
    - player replace tile in hand               (replace <tile>)
    - player pass                               (pass) 
    - all moves performed are error handled:
        - Invalid Argument errors handled properly
        - Empty TileBag handled properly
    - save with message displayed
    - loading game from file resumes gameplay from player's turn
    - at the end of a game the gameplay finishes (goodbye msg)
    - bingo if place all 7 tiles
    - EOF character immediately closes game (only goodbye msg)

    Game objects:
    - board displayed is 15x15
    - board uses a vector implementation
    - player's hand uses a linkedlist implementation
    - tilebag stored as linkedlist

    - Test cases




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
- Save current player's turn at the end of the file
- Reading file loads from the given player's turn

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
- ~~read game.txt to actual Game obj~~
- ~~BINGO Requirement (placing all 7 tiles prints bingo)~~
- ~~Check at end of player turn if they won~~

- Finish assignment ?? FINISHED??