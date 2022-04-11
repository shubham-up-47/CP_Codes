#include <bits/stdc++.h>
using namespace std;


class node
{     public:
	int max1;      // first max in given range
	int max2;      // second max in given range 
}; 


void buildSegmentTree(int *arr, node *ST, int rStart, int rEnd, int iCurrNode)      
{
	if(rStart == rEnd)
	{   ST[iCurrNode].max1 = arr[rStart];
	    ST[iCurrNode].max2 = INT_MIN;
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildSegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildSegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);


	node childL = ST[2*iCurrNode];
	node childR = ST[2*iCurrNode+1];
	
	ST[iCurrNode].max1 = max(childL.max1, childR.max1);
	ST[iCurrNode].max2 = max(min(childL.max1,childR.max1), max(childL.max2,childR.max2)); 
}

 
void updateSegmentTree(node *ST, int rStart, int rEnd, int iCurrNode, int rI, int newValue)
{
	if(rStart == rEnd) 
	{   ST[iCurrNode].max1 = newValue;
	    ST[iCurrNode].max2 = INT_MIN;
	    return;   }
	
	
	int rMid = (rStart+rEnd)/2;
	 
	if(rI <= rMid)
	updateSegmentTree(ST, rStart, rMid, 2*iCurrNode, rI, newValue);
	else
	updateSegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rI, newValue);

	
	node childL = ST[2*iCurrNode];
	node childR = ST[2*iCurrNode+1];
	
	ST[iCurrNode].max1 = max(childL.max1, childR.max1);
	ST[iCurrNode].max2 = max(min(childL.max1,childR.max1), max(childL.max2,childR.max2)); 
}

   
node querySegmentTree(node *ST, int rStart, int rEnd, int iCurrNode, int rLeft, int rRight)
{
	if(rRight < rStart || rEnd < rLeft)             // [rStart,rEnd] completely outside ([rStart,rEnd] contains only extra ans)
    return {INT_MIN,INT_MIN};	
	else if(rLeft <= rStart  && rEnd <= rRight)     // [rStart,rEnd] completely inside ([rStart,rEnd] contains no extra ans)
	return ST[iCurrNode];
	
	
	int rMid = (rStart+rEnd)/2;                     // [rStart,rEnd] partially outside-inside ([rStart,rEnd] contains some extra ans)
	
	node ansL = querySegmentTree(ST, rStart, rMid, 2*iCurrNode, rLeft, rRight);   
	node ansR = querySegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rLeft, rRight);                          
	 
	 
	node ans; 
	ans.max1 = max(ansL.max1, ansR.max1);
	ans.max2 = max(min(ansL.max1,ansR.max1), max(ansL.max2,ansR.max2));  
	return ans; 
}


int main()             // SegmentTree to get maxPairSum/sumOfMaxAndSecondMax inGivenRange & applyUpdatesFast (arr[i] >= 0 for all i)                  
{ 
    int n;
    cin >> n;
                                  
	int arr[n];
	for(int i=0; i<n; i++)
	cin >> arr[i]; 
	         
	           
	node ST[4*n];            
	         
	buildSegmentTree(arr, ST, 0, n-1, 1); 
	            
    int nQ=0;
    cin >> nQ;
	                   
	while(nQ--)
    {
        char c;
	    int rLeft, rRight, rI, newValue;
	    	
        cin >> c;	
    	
        if(c == 'U')	
	    {   cin >> rI >> newValue;
	        updateSegmentTree(ST, 0, n-1, 1, rI-1, newValue);   }
	    else if(c == 'Q')
	    {   cin >> rLeft >> rRight;
	        node ans = querySegmentTree(ST, 0, n-1, 1, rLeft-1, rRight-1); 
			cout << (ans.max1 + ans.max2) << endl;   }
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








