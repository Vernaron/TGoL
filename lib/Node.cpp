#include "Node.h"
Node::Node(){
	isAlive=false;
	nextState=false;
}
char Node::printAlive(){//outputs " " if node is dead and "#" if node is alive
return isAlive ? '#' : ' ';
}
void Node::checkStatus(Node** nodeArray/*[x][y]*/, int x, int y){//checks the node's condition relative to other nodes
	int numNodes=0;
	for(int i=x-1;i<=x+1;i++){
		if(i<0||i>=MAX_X){//if looking outside the board
			continue;
		}
		for(int j=y-1;j<=y+1;j++){
			if(j<0||j>=MAX_Y){//if looking outside the board
				continue;
			}
			if(i==x&&j==y){//if checking self
				continue;
			}
			if(nodeArray[i][j].returnAlive()){//if cell being checked is alive
			numNodes+=1;
			}
		}
		
	}
	nextState=numNodes==3||(isAlive&&numNodes==2);//the rules for living
}
void Node::randomLive(){//makes the node randomly become alive or dead
isAlive = std::rand()%RAND_MAX > RAND_MAX/1.7;
}
void Node::setStatus(bool newStatus){//manually sets the status of the node
	isAlive = newStatus;
}
bool Node::returnAlive(){
	return isAlive;
}
void Node::updateState(){
	isAlive=nextState;
}