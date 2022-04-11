#include<bits/stdc++.h>
using namespace std;


/*
 
PU[] = arrayStoringPendingUpdateData ofLazySegmentTreeNodes (LazyPropagation)
PU[i] = storesPendingUpdateOfNode'i'OfSegmentTree

*/


void buildLazySegmentTree(int *arr, int *ST, int rStart, int rEnd, int iCurrNode)     // code same as building Segment Tree  
{
	if(rStart == rEnd)
	{   ST[iCurrNode] = arr[rStart];
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildLazySegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildLazySegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);


	ST[iCurrNode] = min(ST[2*iCurrNode], ST[2*iCurrNode+1]); 
}


void rangeUpdate_inLazySegmentTree(int *ST, int *PU, int rStart, int rEnd, int rLeft, int rRight, int x, int iCurrNode)
{
	if(PU[iCurrNode] !=0)                                   // handling, ifThereIsAny oldPendingUpdate ofCurrentNode 
	{
		ST[iCurrNode] += PU[iCurrNode];

		if(rStart != rEnd)
		{	PU[2*iCurrNode] += PU[iCurrNode];
			PU[2*iCurrNode+1] += PU[iCurrNode];	  }
		
		PU[iCurrNode] = 0;
	}

	    
	if(rRight<rStart || rEnd<rLeft) 
	return;
	else if(rLeft<=rStart  && rEnd<=rRight)             // updateTheValueOfST[iCurrNode] & storePendingUpdateOfItsChildrenIfExist
	{	ST[iCurrNode] += x;                                  
		
		if(rStart != rEnd)                                 // PU[iCurrNode] is already handled
		{	PU[2*iCurrNode] += x;
			PU[2*iCurrNode+1] += x;   }
		
		return;	  }
		
	
	int rMid = (rStart+rEnd)/2;
	  
	rangeUpdate_inLazySegmentTree(ST, PU, rStart, rMid, rLeft, rRight, x, 2*iCurrNode);
	rangeUpdate_inLazySegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, x, 2*iCurrNode+1);
 
	ST[iCurrNode] = min(ST[2*iCurrNode], ST[2*iCurrNode+1]); 
}


int rangeQuery_inLazySegmentTree(int *ST, int *PU, int rStart, int rEnd, int rLeft, int rRight, int iCurrNode)     
{
	if(PU[iCurrNode] != 0)                                  // handling, ifThereIsAny oldPendingUpdate ofCurrentNode 
	{
		ST[iCurrNode] += PU[iCurrNode];
		 
		if(rStart != rEnd)
		{   PU[2*iCurrNode] += PU[iCurrNode];   
			PU[2*iCurrNode+1] += PU[iCurrNode];   }	 
	 
		PU[iCurrNode] = 0;
	}
	
	
	if(rRight<rStart || rEnd<rLeft) 
	return INT_MAX;
	else if(rLeft<=rStart  && rEnd<=rRight)
	return ST[iCurrNode];
	
	
	int rMid=(rStart+rEnd)/2;
	
	int ans1 = rangeQuery_inLazySegmentTree(ST, PU, rStart, rMid, rLeft, rRight, 2*iCurrNode);
	int ans2 = rangeQuery_inLazySegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, 2*iCurrNode+1);
	
	ST[iCurrNode] = min(ST[2*iCurrNode], ST[2*iCurrNode+1]);       // weAreHandlingPendingUpdatesAlso soWeNeedToDoTheUpdation 
	return min(ans1, ans2);
}
 	 
  
int main() 
{
	int n, nQ;
	cin>>n>>nQ;
		
	int *arr = new int[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
		
	int ST[4*n] = {0};
	int PU[4*n] = {0};
		
	buildLazySegmentTree(arr, ST, 0, n-1, 1);

	while(nQ--)
	{	
	    int type;
		cin>>type;
			
		if(type==1)                         // increases all elements in [rLeft,rRight] by x 
		{	int rLeft, rRight, x;
			cin >> rLeft >> rRight >> x;
			rangeUpdate_inLazySegmentTree(ST, PU, 0, n-1, rLeft, rRight, x, 1);   }   
		else if(type==2)                    // find min element in [rLeft,rRight]
		{	int rLeft, rRight;
			cin >> rLeft >> rRight;
			cout << rangeQuery_inLazySegmentTree(ST, PU, 0, n-1, rLeft, rRight, 1) << endl;   }
	}
	
	cout<< "\nSegmentTree(afterAllQueries): " <<endl;
	for(int i=0; i<4*n; i++)
	cout<<ST[i]<<" ";
	cout<<endl;

	cout<< "\nLazyTree(afterAllQueries): " <<endl;
	for(int i=0; i<4*n; i++)
	cout<<PU[i]<<" ";
	cout<<endl;
}


/*

8 4
-1 2 4 1 7 1 3 2
1 0 3 3
1 0 3 1
1 0 0 2
2 2 2

*/



/*

Here, (rStart, rEnd, rMid, rLeft, rRight, rI) belongs to [0,n-1]
But if que says that, (rLeft, rRight) in input belongs to [1,n] then use (rLeft-1, rRight-1) in function call

*/


  




