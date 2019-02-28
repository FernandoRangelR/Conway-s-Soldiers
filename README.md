# Conway-s-Soldiers

The one player game, Conway’s Soldiers (sometimes known as Solitaire Army), is similar to peg
solitaire. For this exercise, Conway’s board is a 7 (width) × 8 (height) board with tiles on it. The
lower half of the board is entirely filled with tiles (pegs), and the upper half is completely empty.
A tile can move by jumping another tile, either horizontally or vertically (but never diagonally)
onto an empty square. The jumped tile is then removed from the board.
The user enters the location of an empty square they’d like to get a tile into, and the program
demonstrates the moves that enables the tile to reach there (or warns them it’s impossible).

This program:
• Receives  target location for a tile to reach (x in argv[1], y in argv[2]).
• Demonstrates the correct solution (reverse order is fine) using plain text.
