#include <bits/stdc++.h>
using namespace std;


class node
{      public:
	int totalSum;        
	int maxPrefixSum;    
	int maxSuffixSum;  
	int maxSubarraySum;     
}; 


node mergeNodes(node cL, node cR)
{
    node n;
     
    n.totalSum = cL.totalSum + cR.totalSum;
    n.maxPrefixSum = max(cL.maxPrefixSum, cL.totalSum + cR.maxPrefixSum);
    n.maxSuffixSum = max(cR.maxSuffixSum, cL.maxSuffixSum + cR.totalSum);
    n.maxSubarraySum = max(cL.maxSubarraySum, max(cR.maxSubarraySum, cL.maxSuffixSum+cR.maxPrefixSum));
  
    return n;
}
  

void buildSegmentTree(int *arr, node *ST, int rStart, int rEnd, int iCurrNode)      
{
	if(rStart == rEnd)
	{   ST[iCurrNode].totalSum = arr[rStart];
	    ST[iCurrNode].maxPrefixSum = arr[rStart];
	    ST[iCurrNode].maxSuffixSum = arr[rStart];
	    ST[iCurrNode].maxSubarraySum = arr[rStart];
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildSegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildSegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);

 
	ST[iCurrNode] = mergeNodes(ST[2*iCurrNode], ST[2*iCurrNode+1]);	
}

 
void updateSegmentTree(node *ST, int rStart, int rEnd, int iCurrNode, int rI, int newValue)
{
	if(rStart == rEnd) 
	{   ST[iCurrNode].totalSum = newValue;
	    ST[iCurrNode].maxPrefixSum = newValue;
	    ST[iCurrNode].maxSuffixSum = newValue;
	    ST[iCurrNode].maxSubarraySum = newValue;
	    return;   }
	
	
	int rMid = (rStart+rEnd)/2;
	 
	if(rI <= rMid)
	updateSegmentTree(ST, rStart, rMid, 2*iCurrNode, rI, newValue);
	else
	updateSegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rI, newValue);

	
	ST[iCurrNode] = mergeNodes(ST[2*iCurrNode], ST[2*iCurrNode+1]);	
}

   
node querySegmentTree(node *ST, int rStart, int rEnd, int iCurrNode, int rLeft, int rRight)
{
	if(rRight < rStart || rEnd < rLeft)             // [rStart,rEnd] completely outside ([rStart,rEnd] contains only extra ans)
    return {-99999,-99999,-99999,-99999};   	
	else if(rLeft <= rStart  && rEnd <= rRight)     // [rStart,rEnd] completely inside ([rStart,rEnd] contains no extra ans)
	return ST[iCurrNode];
	
	
	int rMid = (rStart+rEnd)/2;                     // [rStart,rEnd] partially outside-inside ([rStart,rEnd] contains some extra ans)
	
	node ansL = querySegmentTree(ST, rStart, rMid, 2*iCurrNode, rLeft, rRight);   
	node ansR = querySegmentTree(ST, rMid+1, rEnd, 2*iCurrNode+1, rLeft, rRight);                          
	 
	  
	node ans = mergeNodes(ansL, ansR);  
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
	            
    int nQ;
    cin >> nQ;
	                   
	while(nQ--)
    { 
	    int rLeft, rRight;
	    cin >> rLeft >> rRight;
	    
	    node ans = querySegmentTree(ST, 0, n-1, 1, rLeft-1, rRight-1); 
		cout << ans.maxSubarraySum << endl;   
	} 
}


