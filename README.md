# TGoL
Welcome to TGoL, a text based interpretation of Conway's Game of Life. The rules of this simulation are simple:
If a cell has 2 or 3 nearby cells, it is considered Alive.
If a cell has more than 3 or less than 2 nearby cells, it Dies.
If a dead cell has exactly 3 nearby living cells, it is resurrected and considered Alive.
And thats all there is to it! This simulation stops when all cells are dead or if all cells are in a locked pattern.
Note that there are some configurations that will toggle indefinitely, but thats part of the game! Sometimes cell life can carry on forever
To run this program on Windows, simply run the executable
To run this on Linux, you likely will have to rebuild it using the Makefile provided in lib. If there is an error with it, try deleting the object files and rerunning it
