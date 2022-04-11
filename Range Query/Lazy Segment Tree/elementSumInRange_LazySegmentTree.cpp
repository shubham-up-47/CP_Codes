#include<bits/stdc++.h>
using namespace std;


void buildLazySegmentTree(int *arr, int *ST, int rStart, int rEnd, int iCurrNode)      
{
	if(rStart == rEnd)
	{   ST[iCurrNode] = arr[rStart];
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildLazySegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildLazySegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);


	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1]; 
}


void rangeUpdate_inLazySegmentTree(int *ST, int *PU, int rStart, int rEnd, int rLeft, int rRight, int x, int iCurrNode)
{
	if(PU[iCurrNode] !=0)                         // handlingPendingUpdates
	{
		ST[iCurrNode] += (rEnd-rStart+1)*PU[iCurrNode];

		if(rStart != rEnd)
		{	PU[2*iCurrNode] += PU[iCurrNode];
			PU[2*iCurrNode+1] += PU[iCurrNode];	  }
		
		PU[iCurrNode] = 0;
	}

	    
	if(rRight<rStart || rEnd<rLeft) 
	return;
	else if(rLeft<=rStart  && rEnd<=rRight)
	{	ST[iCurrNode] += (rEnd-rStart+1)*x;     // handlingCurrentUpdates
		
		if(rStart != rEnd)                      // PU[iCurrNode] is already handled
		{	PU[2*iCurrNode] += x;
			PU[2*iCurrNode+1] += x;   }
		
		return;	  }
		
	
	int rMid = (rStart+rEnd)/2;
	  
	rangeUpdate_inLazySegmentTree(ST, PU, rStart, rMid, rLeft, rRight, x, 2*iCurrNode);
	rangeUpdate_inLazySegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, x, 2*iCurrNode+1);
 
	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1]; 
}


int rangeQuery_inLazySegmentTree(int *ST, int *PU, int rStart, int rEnd, int rLeft, int rRight, int iCurrNode)     
{
	if(PU[iCurrNode] != 0)                       // handlingPendingUpdates
	{
		ST[iCurrNode] += (rEnd-rStart+1)*PU[iCurrNode];
		 
		if(rStart != rEnd)
		{   PU[2*iCurrNode] += PU[iCurrNode];   
			PU[2*iCurrNode+1] += PU[iCurrNode];   }	 
	 
		PU[iCurrNode] = 0;
	}
	
	
	if(rRight<rStart || rEnd<rLeft) 
	return 0;
	else if(rLeft<=rStart  && rEnd<=rRight)
	return ST[iCurrNode];
	
	
	int rMid=(rStart+rEnd)/2;
	
	int ans1 = rangeQuery_inLazySegmentTree(ST, PU, rStart, rMid, rLeft, rRight, 2*iCurrNode);
	int ans2 = rangeQuery_inLazySegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, 2*iCurrNode+1);
	
	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1];       // weAreHandlingPendingUpdatesAlso soWeNeedToDoTheUpdation 
	return (ans1 + ans2);
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

6 3
1 3 5 7 9 11
1 0 2 3
1 0 0 1
2 0 0

*/






