#include <bits/stdc++.h>
using namespace std;


/*

In this code:
ConsiderAllTheCasesAndReachToLeafNode => ConsiderBothPlayOptimallyAndReturn'maximizer/minimizer'ScoreFromEachSubtree => ReturnBestScoreFromRootNode


Unmoved tile symbol = 0
Player1(maximizer) symbol = 1
Player2(minimizer) symbol = 2 


(maximizerTurn==true) => Player1 turn
(maximizerTurn==false) => Player2 turn

(CurrBoard) = Current Board after considering previous moves 

*/
 

int** makeMove(int **currBoard, int currMoveX, int currMoveY, int currPlayer, int flag) // returning currMoveBoard afterPerformingTheMove                               
{
	int **currMoveBoard;
	
	if(flag==true)                                                                      // (flag==true) = checkThePossibilityOfMoveOn currBoard
	currMoveBoard = currBoard;
	else                                                                                // (flag==false) = performTheMoveOn newBoard 
	{	currMoveBoard = new int*[4]; 
	    for(int i=0; i<4; i++)
	    {   currMoveBoard[i] = new int[4]; 
	        for(int j=0; j<4; j++)
	    	currMoveBoard[i][j] = currBoard[i][j];   } 	}
	
	
	int arr1[] = {-1,-1,0,1,1,1,0,-1};                                                  // corresponding factors to explore moves in 8 directions 
	int arr2[] = {0,1,1,1,0,-1,-1,-1};                     
	
	if(currMoveX<0 || currMoveX>=4 || currMoveY<0 || currMoveY>=4 || currMoveBoard[currMoveX][currMoveY]!=0)
	return NULL;
		
	bool movePossible = false; 
	
	for(int i=0; i<8; i++)                                                              // updateInAll 8 directions ifMoveIsPossible w.r.t. it 
	{  	
	    int count = 0;  
	    int xFactor=arr1[i], yFactor=arr2[i];  
	    
	    int x = currMoveX + xFactor;
	    int y = currMoveY + yFactor;                                                 
	    while(x>=0 && x<4 && y>=0 && y<4)                   
  	    {
  	        if(currMoveBoard[x][y]==0)                                                  // move not possible (in current direction) 
			break;
			else if(currMoveBoard[x][y]!=currPlayer)                                    // move possible (in current direction) 
			{   x += xFactor;
				y += yFactor;   
				count++;   }
			else if(currMoveBoard[x][y]==currPlayer && count==0)                        // move not possible (in current direction) 
			break; 
			else if(currMoveBoard[x][y]==currPlayer && count>0)                         // valid move (in current direction) 
			{	movePossible = true;
			    
			    if(flag==true)
			    return currMoveBoard;
			    else
			    {  int prevX = x - xFactor;
				   int prevY = y - yFactor;  
				   
			   	   while(prevX!=currMoveX || prevY!=currMoveY)                          // performing the move                             
				   {  currMoveBoard[prevX][prevY] = currPlayer;                         // update opponent tiles
				   	  prevX -= xFactor;
 	                  prevY -= yFactor;	 }                                              
 	                  
				   currMoveBoard[currMoveX][currMoveY] = currPlayer;  }                 // place currPlayer on currMove position    
				break;	}	  
		}    
	}	
	
	if(movePossible==true)
	return currMoveBoard;
	else
	return NULL; 
}


vector<pair<int,int>*>* possibleMoves(int **currBoard, int currPlayer)                  // finding all valid (i,j) for currPlayer move  
{
	vector<pair<int,int>*> *options = new vector<pair<int,int>*>();     
	
	for(int i=0; i<4; i++)
	{   for(int j=0; j<4; j++)
	    {
	    	if(currBoard[i][j]==0 && makeMove(currBoard,i,j,currPlayer,true)!=NULL)     // moveIsPossible onUnoccupiedCurrent(i,j) by currPlayer
	    	{   pair<int,int> *p = new pair<int,int>(i,j);                              // dynamic pair to store {i,j} 
				options->push_back(p);   }                                              
		}  
	}
	
    return options; 
}


int evaluateBoard(int **currBoard, bool &gameCompleted)                                 // returnsScore when NoValidMovesLeft/GameCompleted/LeafNode 
{
	if(possibleMoves(currBoard,1)->size()!=0 || possibleMoves(currBoard,2)->size()!=0)                  
    {   gameCompleted = false;  
		return 0;   }
		
	gameCompleted = true;
	
	int count[3] = {0};                                                                 // count[i] = count of i's tiles in current board   
	for(int i=0; i<4; i++)
	{   for(int j=0; j<4; j++)
	    count[currBoard[i][j]]++;	}
		
	return (count[1]-count[2]);			
}
 

void printBoard(int **currBoard)
{
	for(int i=0; i<4; i++)
	{   for(int j=0; j<4; j++)
	    cout<<currBoard[i][j]<<" ";	  } 
	cout<<endl; 
}


int findBestScore(int **currBoard, bool maximizerTurn, int &bestMoveX, int &bestMoveY)  // itUpdatesCorrespondingBestMove in (bestMoveX,bestMoveY) 
{ 
    int bestScore;
	bool gameCompleted;                                                                 // boolean telling game ended or not
	
	int currScore = evaluateBoard(currBoard,gameCompleted);
//	printBoard(currBoard); 
	if(gameCompleted==true)                                                             // if game ended (leaf node), then return the score
	return currScore; 


	int currPlayer = (maximizerTurn==true) ? 1 : 2;                                     // getting symbol of current player
	vector<pair<int,int>*> *options = possibleMoves(currBoard,currPlayer);              // all options for currPlayer (as array of dynamicPairs)   
                    	
	if(options->size()==0)                                                              // if currPlayer can't make move, toggle the turn 
	{	bestMoveX=-1, bestMoveY=-1;
	 
	 	int tempX, tempY;                                                              
		bestScore = findBestScore(currBoard,!maximizerTurn,tempX,tempY);                // finding bestMove-bestScore for currPlayer w.r.t. currBoard
		return bestScore;   }
		             
	bestScore = (maximizerTurn==true) ? INT_MIN : INT_MAX;    
	
	for(int i=0; i<options->size(); i++)                                                // finding bestScore (from some leaf node of currentSubtree)   
	{ 
		int currMoveX = options->at(i)->first;	
		int currMoveY = options->at(i)->second;	
		int **currMoveBoard = makeMove(currBoard,currMoveX,currMoveY,currPlayer,false); // board corresponding to (currentMoveX,currentMoveY)
 
		int tempX, tempY;                                                              
		int currScore = findBestScore(currMoveBoard,!maximizerTurn,tempX,tempY);        // finding bestMove-bestScore for currPlayer w.r.t. currMoveBoard
		
		bestScore = (maximizerTurn==true) ? max(bestScore,currScore) : min(bestScore,currScore);
		
		if(currScore == bestScore) 
		{	bestMoveX = currMoveX;
			bestMoveY = currMoveY;   }
		
		for(int i=0; i<4; i++)                                                          // delete after using its best score (from its leaf node)
		delete [] currMoveBoard[i];
		delete [] currMoveBoard;
	}
	
	return bestScore;                                                                   // returning bestScore (which is generated on a leaf node)
}


int main()                                       
{
	int **currBoard = new int*[4];                                                      // creating 4X4 Othello (instead of 8X8) for fast output 
	for(int i=0; i<4; i++) 
	{	currBoard[i] = new int[4];  
		for(int j=0; j<4; j++) 
		cin>>currBoard[i][j];   }         
 
	
	int bestMoveX, bestMoveY;                                                           // finding (bestMoveX,bestMoveY) if both play optimally  
	int bestScore = findBestScore(currBoard,true,bestMoveX,bestMoveY);                  // finding bestMove for maximizer & corresponding bestScore  
	cout<< "\nBestMove for maximizer w.r.t. CurrentBoard: ("<< bestMoveX <<", "<< bestMoveY <<")"<<endl;
	cout<< "\nFinal Othello Score (atRootNode) corresponding to BestMove of maximizer: "<< bestScore <<endl;
}


/*

CurrentBoard1
   0 0 0 0
   0 1 2 0 
   0 2 1 0
   0 0 0 0 
   
   
CurrentBoard2
   0 0 0 0
   0 1 2 0 
   0 1 2 0
   0 1 2 0 
   
   
CurrentBoard3
   0 0 0 0
   0 1 2 0 
   0 0 1 0
   0 2 0 0 
   
   
If we will print the Board also corresponding to eachNodeOfTree/eachMove, then output will come so late 

*/













