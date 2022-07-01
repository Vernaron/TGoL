#include "Interface.h"
std::string printEdge(int size, char character);
void Board(){
	Node** newArray =  new Node*[MAX_X];
	for(int i=0;i<MAX_X;i++){
		newArray[i]= new Node[MAX_Y];
	}
	startRandom(newArray);
	std::string printedArray, lastPrint;
	printBoard(newArray, printedArray);
	int count = 0;
	std::cout<<"Press Enter to start the simulation"<<std::endl;
	std::cin.ignore();
	do{
		lastPrint=printedArray;
		count=updateBoard(newArray, printedArray);
	} while (count>0&&lastPrint!=printedArray);
	deleteBoard(newArray);
	cout<<"Simulation Completed, press Enter to exit"<std::endl
	std::cin.ignore();
}
void deleteBoard(Node** nodeArray){
	for (int i=0;i<MAX_X;i++){
		delete nodeArray[i];
	}
	delete nodeArray;
}
void startRandom(Node** nodeArray){
	for(int i=0;i<MAX_X;i++){
		for(int j=0;j<MAX_Y;j++){
		nodeArray[i][j].randomLive();
		}
	}
}
void printBoard(Node** nodeArray, std::string& printedArray){
	printedArray="";
	for(int i=0;i<MAX_X;i++){
		if(i==0){
			printedArray+=printEdge(MAX_X*2+2, '-')+"\n";
		}
		for(int j=0;j<MAX_Y;j++){
			if(j==0){
			printedArray+='|';
			}
			printedArray+=nodeArray[i][j].printAlive();
			printedArray+=' ';
			if(j==MAX_Y-1){
			printedArray+='|';
			}
		}
		printedArray+="\n";
		if(i==MAX_X-1){
			printedArray+=printEdge(MAX_X*2+2, '-');
		}
	}
	system("CLS");
	std::cout<<printedArray<<std::endl;
}
int updateBoard(Node** nodeArray, std::string& printedArray){
	int count=0;
	for(int i=0;i<MAX_X;i++){//sets the next state for all nodes
		for(int j=0;j<MAX_Y;j++){
			nodeArray[i][j].checkStatus(nodeArray, i, j);
			count+= (int)nodeArray[i][j].returnAlive();
		}
	}
	for(int i=0;i<MAX_X;i++){//switches to the next state for all nodesq
		for(int j=0;j<MAX_Y;j++){
			nodeArray[i][j].updateState();
		}
	}
	printBoard(nodeArray, printedArray);
	return count;
}
std::string printEdge(int size, char character){
	std::string border;
	for(int i=0;i<size;i++){
		border+=character;
	}
	border+="";
	return border;
}