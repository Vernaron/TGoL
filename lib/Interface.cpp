#include "Interface.h"
void wait(double waitTime);
std::string printEdge(int size, char character);
void board(){
	Node** newArray =  new Node*[MAX_X];//initialize new 2d array
	for(int i=0;i<MAX_X;i++){
		newArray[i]= new Node[MAX_Y];
	}
	std::cout<<"Welcome to TGoL, a text based interpretation of Conway's Game of Life. The rules of this simulation are simple:"
	<<std::endl<<"If a cell has 2 or 3 nearby cells, it is considered Alive."
	<<std::endl<<"If a cell has more than 3 or less than 2 nearby cells, it Dies."
	<<std::endl<<"If a dead cell has exactly 3 nearby living cells, it is resurrected and considered Alive."
	<<std::endl<<"And thats all there is to it! This simulation stops when all cells are dead or if all cells are in a locked pattern."
	<<std::endl<<"Note that there are some configurations that will toggle indefinitely, but thats part of the game! Sometimes cell life can carry on forever"
	<<std::endl<<"And with that out of the way, simply press Enter to start the simulation";
	std::cin.ignore();
	startRandom(newArray);
	std::string printedArray, lastPrint, lastPrint2;
	printBoard(newArray, printedArray);
	int count = 0, numLoop=30;
	do{
		if(lastPrint2==printedArray){
			numLoop-=1;
		}
		lastPrint2=lastPrint;
		lastPrint=printedArray;//keeps track of what the last board looked like
		count=updateBoard(newArray, printedArray);//keeps track of total cells on the board
	} while (count>0&&lastPrint!=printedArray&&numLoop>0);//terminate if nothing on the board or board didnt change between cycles
	deleteBoard(newArray);
	char continueLife;
	std::cout<<"Simulation Completed, start another simulation? (y/n)"<<std::endl;
	std::cin>>continueLife;
	if(continueLife=='y'||continueLife=='Y'){
	board(); 
	}
}
void deleteBoard(Node** nodeArray){//function to delete the 2d array
	for (int i=0;i<MAX_X;i++){
		delete nodeArray[i];
	}
	delete nodeArray;
}
void startRandom(Node** nodeArray){
	char density;
	float numCells;
	densityGet: std::cout<<"Please enter the density of initial cells that you want, Low, Medium, High, or Extreme (l,m,h,e): ";
	std::cin>>density;
	switch(density){
	case 'l':
		numCells=1.2f;
		break;
	case 'm':
		numCells=1.5f;
		break;
	case 'h':
		numCells=1.7f;
		break;
	case 'e':
		numCells=3.0f;
		break; 
	default:
	std::cout<<"Invalid Character"<<std::endl;
	std::cin.ignore();
	goto densityGet;
	}
	for(int i=0;i<MAX_X;i++){
		for(int j=0;j<MAX_Y;j++){
		nodeArray[i][j].randomLive(numCells, nodeArray, i, j);
		}
	}
}
void printBoard(Node** nodeArray, std::string& printedArray){
	printedArray="";
	for(int i=0;i<MAX_X;i++){ 
		if(i==0){//border
			printedArray+=printEdge(MAX_X*2+2, '-')+"\n";
		}
		for(int j=0;j<MAX_Y;j++){
			if(j==0){//border
			printedArray+='|';
			}
			printedArray+=nodeArray[i][j].printAlive();//gets the living or dead character from every cell
			printedArray+=' ';//spacing
			if(j==MAX_Y-1){//border
			printedArray+='|';
			}
		}
		printedArray+="\n";
		if(i==MAX_X-1){//border
			printedArray+=printEdge(MAX_X*2+2, '-');
		}
	}
	std::cout<<"\033[2J\033[1;1H "<<printedArray;
	wait(0.03);
}
int updateBoard(Node** nodeArray, std::string& printedArray){
	int count=0;
	for(int i=0;i<MAX_X;i++){//sets the next state for all nodes
		for(int j=0;j<MAX_Y;j++){
			nodeArray[i][j].checkStatus(nodeArray, i, j);//makes every cell update their next state
			count+= (int)nodeArray[i][j].returnAlive();
		}
	}
	for(int i=0;i<MAX_X;i++){//switches to the next state for all nodesq
		for(int j=0;j<MAX_Y;j++){
			nodeArray[i][j].updateState();//updates the states
		}
	}
	printBoard(nodeArray, printedArray);
	return count;
}
std::string printEdge(int size, char character){//returns a string of characters x long
	std::string border;
	for(int i=0;i<size;i++){
		border+=character;
	}
	border+="";
	return border;
}
void wait(double waitTime){
	std::chrono::time_point<std::chrono::system_clock> startFrame, endFrame;
	startFrame = std::chrono::system_clock::now();
	endFrame = std::chrono::system_clock::now();
	std::chrono::duration<double> deltaT = endFrame - startFrame;
	while(deltaT.count()<waitTime){
		endFrame = std::chrono::system_clock::now();
		deltaT = endFrame - startFrame;
	}
}