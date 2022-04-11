#include <bits/stdc++.h>
using namespace std;


// (ST = Segment Tree) (iCurrNode = indexNoOf nodeInCurrentFunctionCall/currentNode) ([rStart,rEnd] = rangeOf nodeInCurrentFunctionCall/currentNode) 


void buildSegmentTree(int *arr, int *ST, int rStart, int rEnd, int iCurrNode)      
{
	if(rStart == rEnd)
	{   ST[iCurrNode] = arr[rStart];
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildSegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildSegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);


	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1]; 
}

 // rI = indexNoInRange"[rStart,rEnd]"  whereValueWillBeUpdatedTo"newValue"

void updateSegmentTree(int *arr, int *ST, int rStart, int rEnd, int iCurrNode, int rI, int newValue)
{
	if(rStart == rEnd)
	{   arr[rI] = newValue;
	    ST[iCurrNode] = newValue;
	    return;   }
	
	
	int rMid = (rStart+rEnd)/2;
	 
	if(rI <= rMid)
	updateSegmentTree(arr, ST, rStart, rMid, 2*iCurrNode, rI, newValue);
	else
	updateSegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1, rI, newValue);

	
	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1]; 
}

 // queryIsToFindTheAnswer correspondingToTheRange"[rLeft,rRight]"  

int querySegmentTree(int *ST, int rStart, int rEnd, int iCurrNode, int rLeft, int rRight)
{
	if(rRight < rStart || rEnd < rLeft)             // [rStart,rEnd] completely outside ([rStart,rEnd] contains only extra ans)
    return 0;	
	else if(rLeft <= rStart  && rEnd <= rRight)     // [rStart,rEnd] completely inside ([rStart,rEnd] contains no extra ans)
	return ST[iCurrNode];
	
	
	int rMid = (rStart+rEnd)/2;                     // [rStart,rEnd] partially outside-inside ([rStart,rEnd] contains some extra ans)
	
	int ans1 = querySegmentTree(ST, rStart, rMid, 2*iCurrNode, rLeft, rRight);   
	int ans2 = querySegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rLeft, rRight);                          
	 
	return (ans1 + ans2);
}


int main()                                          // SegmentTree to get sumInGivenRange & applyUpdatesFast                  
{ 
	int arr[] = {1,2,3,4,5,6}; 
	  
	  
	int ST[4*6] = {0};            
	   
	buildSegmentTree(arr, ST, 0, 5, 1); 
	
	for(int i=1; i<4*6; i++)
	cout << ST[i] << " ";
	cout << endl;
	 
	updateSegmentTree(arr, ST, 0, 5, 1, 2, 20);
	
	for(int i=1; i<4*6; i++)
	cout << ST[i] << " ";
	cout << endl;
	 
	cout << "Sum between interval [2,4] is: " << querySegmentTree(ST, 0, 5, 1, 2, 4) << endl; 
}


/*

Here, (rStart, rEnd, rMid, rLeft, rRight, rI) belongs to [0,n-1]
But if que says that, (rLeft, rRight, rI) in input belongs to [1,n] then use (rLeft-1, rRight-1, rI-1) in function call

*/


  






