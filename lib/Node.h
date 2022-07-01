#include <iostream> 
#include <stdlib.h>
#define MAX_X 40//edit these varables to change board size
#define MAX_Y 40
class Node {
	bool isAlive;
	bool nextState;
	public:
		bool returnAlive();
		char printAlive();//outputs " " if node is dead and "*" if node is alive
		void checkStatus(Node** nodeArray/*[x][y]*/, int x, int y);//checks the node's condition relative to other nodes
		void updateState();//function that moves the next state to the isAlive bool. This is used so that all nodes update at once, instead of one at a time
		//This all at once state change prevents cases where higher nodes update before lower nodes can react
		void randomLive();//makes the node randomly become alive or dead
		void setStatus(bool newStatus);//manually sets the status of the node
		Node();
};