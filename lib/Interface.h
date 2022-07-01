#include "Node.h"
#include <string>
#include <iostream>
void Board();
void startRandom(Node** nodeArray);
void deleteBoard(Node** nodeArray);
void printBoard(Node** newArray, std::string& printedArray);
int updateBoard(Node** nodeArray, std::string& printedArray);