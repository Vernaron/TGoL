#include "Node.h"
#include <string>
#include <iostream>
void Board();//the main function for the entire program
void startRandom(Node** nodeArray);//starts all the cells either randomly alive or dead
void deleteBoard(Node** nodeArray);//clears the array when the simulation is finished
void printBoard(Node** newArray, std::string& printedArray);//outputs and formats the board with all the cells
int updateBoard(Node** nodeArray, std::string& printedArray);//updates all cell states