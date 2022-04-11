#include <bits/stdc++.h>
using namespace std;

 
void buildSegmentTree(int *arr, int *ST, int rStart, int rEnd, int iCurrNode)      
{
	if(rStart == rEnd)
	{   ST[iCurrNode] = arr[rStart];
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildSegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildSegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);


	ST[iCurrNode] = min(ST[2*iCurrNode], ST[2*iCurrNode+1]); 
}

 
void updateSegmentTree(int *ST, int rStart, int rEnd, int iCurrNode, int rI, int newValue)
{
	if(rStart == rEnd)
	{   ST[iCurrNode] = newValue;
	    return;   }
	
	
	int rMid = (rStart+rEnd)/2;
	 
	if(rI <= rMid)
	updateSegmentTree(ST, rStart, rMid, 2*iCurrNode, rI, newValue);
	else
	updateSegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rI, newValue);

	
	ST[iCurrNode] = min(ST[2*iCurrNode], ST[2*iCurrNode+1]); 
}

   
int querySegmentTree(int *ST, int rStart, int rEnd, int iCurrNode, int rLeft, int rRight)
{
	if(rRight < rStart || rEnd < rLeft)             // [rStart,rEnd] completely outside ([rStart,rEnd] contains only extra ans)
    return -1;	
	else if(rLeft <= rStart  && rEnd <= rRight)     // [rStart,rEnd] completely inside ([rStart,rEnd] contains no extra ans)
	return ST[iCurrNode];
	
	
	int rMid = (rStart+rEnd)/2;                     // [rStart,rEnd] partially outside-inside ([rStart,rEnd] contains some extra ans)
	
	int ans1 = querySegmentTree(ST, rStart, rMid, 2*iCurrNode, rLeft, rRight);   
	int ans2 = querySegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rLeft, rRight);                          
	 
	if(ans1!=-1 && ans2!=-1) 
	return min(ans1, ans2);
	else if(ans1 != -1)
	return ans1;	
	else if(ans2 != -1) 
	return ans2;
	else
	return -1;
}


int main()                                          // SegmentTree to get minValueInGivenRange & applyUpdatesFast                  
{ 
    int n, nQ;
    cin >> n >> nQ;
    
	int arr[n];
	for(int i=0; i<n; i++)
	cin >> arr[i]; 
	  
	  
	int ST[4*n]; 
	for(int i=1; i<4*n; i++)
	ST[i] = -1;           
	         
	buildSegmentTree(arr, ST, 0, n-1, 1); 
	 
	while(nQ--)
    {
        char c;
	    int rLeft, rRight, rI, newValue;
	    	
        cin >> c;	
    	
        if(c == 'u')	
	    {   cin >> rI >> newValue;
	        updateSegmentTree(ST, 0, n-1, 1, rI-1, newValue);   }
	    else if(c == 'q')
	    {   cin >> rLeft >> rRight;
	        cout << querySegmentTree(ST, 0, n-1, 1, rLeft-1, rRight-1) << endl;   }
	} 

}


/*
 
ST = Segment Tree 
iCurrNode = indexNoOf nodeInCurrentFunctionCall/currentNode 
[rStart,rEnd] = rangeOf nodeInCurrentFunctionCall/currentNode 
rI = indexNoInRange"[rStart,rEnd]"  whereValueWillBeUpdatedTo"newValue"
queryIsToFindTheAnswer correspondingToTheRange"[rLeft,rRight]"

Here, (rLeft, rRight, rI) in input belongs to [1,n] as per question, thats why we have used (rLeft-1, rRight-1, rI-1) while function call 

*/







