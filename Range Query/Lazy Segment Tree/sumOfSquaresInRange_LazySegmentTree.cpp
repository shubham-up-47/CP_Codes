#include<bits/stdc++.h>       
using namespace std;


class node               // node of LazySegmentTree
{        public:
	long squaredSum;
	long elementSum;
 
    node()
    {   squaredSum = 0;
        elementSum = 0;   }
};

class data               // PendingUpdate'data' of LazySegmentTree'node' (LazyPropagation)
{     public:
	int type;            // type of change
	int x;               // value of change
	
	data()
	{   type = -1;
        x = 0;   }
};

 
void buildLazySegmentTree(int *arr, node *ST, int rStart, int rEnd, int iCurrNode)            
{
	if(rStart == rEnd)
	{   ST[iCurrNode].elementSum = arr[rStart];
	    ST[iCurrNode].squaredSum = arr[rStart]*arr[rStart]; 
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildLazySegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildLazySegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);
 
	ST[iCurrNode].elementSum = ST[2*iCurrNode].elementSum + ST[2*iCurrNode+1].elementSum;
	ST[iCurrNode].squaredSum = ST[2*iCurrNode].squaredSum + ST[2*iCurrNode+1].squaredSum;		
}


void handlePendingUpdatesOfNode(node *ST, data *PU, int rStart, int rEnd, int iCurrNode)
{
    if(PU[iCurrNode].x == 0)          // type=-1 is noChange  
    return;
    
    
 	int typeP = PU[iCurrNode].type;
	int xP = PU[iCurrNode].x;
 
	if(typeP == 0)                        // type=0 is setValueTo'x'               
	{   
		ST[iCurrNode].elementSum = (rEnd-rStart+1)*xP;
		ST[iCurrNode].squaredSum = (rEnd-rStart+1)*xP*xP;
			
		if(rStart != rEnd)     // noNeedToHandleOldUpdatesOfChildren bczNowWeHaveToSetNewValue
		{	PU[2*iCurrNode].type = typeP;
		    PU[2*iCurrNode].x = xP;
            
            PU[2*iCurrNode+1].type = typeP; 
            PU[2*iCurrNode+1].x = xP;   }   
	}
	else if(typeP == 1)                   // type=1 is increaseValueBy'x'           
	{   
	    ST[iCurrNode].squaredSum += ((rEnd-rStart+1)*xP*xP + 2*xP*(ST[iCurrNode].elementSum));
	    ST[iCurrNode].elementSum += (rEnd-rStart+1)*xP;    // updateTheSumAfter'squaredSum' bczThisIsUsedInUpperEquation
			
		if(rStart != rEnd)
		{	if(PU[2*iCurrNode].type == -1)          // left child
		    PU[2*iCurrNode].type = 1; 
			PU[2*iCurrNode].x += xP;
				
			if(PU[2*iCurrNode+1].type == -1)      // right child 
			PU[2*iCurrNode+1].type = 1;    
			PU[2*iCurrNode+1].x += xP;   }
	}
		
	PU[iCurrNode].type = -1;
    PU[iCurrNode].x = 0;
}
	


void rangeUpdate_inLazySegmentTree(int *arr, node *ST, data *PU, int rStart, int rEnd, int rLeft, int rRight, int type, int x, int iCurrNode)  
{
	if(rStart > rEnd)
    return;
	
    handlePendingUpdatesOfNode(ST, PU, rStart, rEnd, iCurrNode);
	
	
	if(rRight<rStart || rEnd<rLeft)              // [rStart,rEnd] completely outside ([rStart,rEnd] contains only extra ans)
	return;
    else if(rLeft<=rStart  && rEnd<=rRight)      // [rStart,rEnd] completely inside ([rStart,rEnd] contains no extra ans)
	{
		if(type == 0)                            // type=0 is setValueTo'x'  
		{
			ST[iCurrNode].elementSum = (rEnd-rStart+1)*x;
			ST[iCurrNode].squaredSum = (rEnd-rStart+1)*x*x;
			
			if(rStart != rEnd)
			{	PU[2*iCurrNode].type = 0;
			    PU[2*iCurrNode].x = x;
             
				PU[2*iCurrNode+1].type = 0; 
				PU[2*iCurrNode+1].x = x;   }   
		}
		else if(type == 1)                        // type=1 is increaseValueBy'x' 
		{

			ST[iCurrNode].squaredSum += ((rEnd-rStart+1)*x*x + 2*x*(ST[iCurrNode].elementSum));
			ST[iCurrNode].elementSum += (rEnd-rStart+1)*x;    // updateTheSumAfter'squaredSum' bczThisIsUsedInUpperEquation
			
			if(rStart != rEnd)
			{	if(PU[2*iCurrNode].type == -1)     // left child
				PU[2*iCurrNode].type = 1;  
             
				PU[2*iCurrNode].x += x;
  				
				if(PU[2*iCurrNode+1].type == -1)     // right child     
				PU[2*iCurrNode+1].type = 1; 
             
				PU[2*iCurrNode+1].x += x;   }
		}
		
		return;
	}
	
	       
	int rMid = (rStart+rEnd)/2;                    // [rStart,rEnd] partially outside-inside ([rStart,rEnd] contains some extra ans)
  	
	rangeUpdate_inLazySegmentTree(arr, ST, PU, rStart, rMid, rLeft, rRight, type, x, 2*iCurrNode);
	rangeUpdate_inLazySegmentTree(arr, ST, PU, rMid+1, rEnd, rLeft, rRight, type, x, 2*iCurrNode+1);
	
	
	ST[iCurrNode].elementSum = ST[2*iCurrNode].elementSum + ST[2*iCurrNode+1].elementSum;
	ST[iCurrNode].squaredSum = ST[2*iCurrNode].squaredSum + ST[2*iCurrNode+1].squaredSum;	
}

 
int rangeQuery_inSegmentTree(node *ST, data *PU, int rStart, int rEnd, int rLeft, int rRight, int iCurrNode)      
{
	if(rStart > rEnd)
    return 0;
	
    handlePendingUpdatesOfNode(ST, PU, rStart, rEnd, iCurrNode);

	
	if(rRight<rStart || rEnd<rLeft) 
	return 0;
	else if(rLeft<=rStart  && rEnd<=rRight)
	return ST[iCurrNode].squaredSum;
	
	
	int rMid=(rStart+rEnd)/2;
	
	int ans1 = rangeQuery_inSegmentTree(ST, PU, rStart, rMid, rLeft, rRight,2*iCurrNode);
	int ans2 = rangeQuery_inSegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, 2*iCurrNode+1);
 	
    // weAreHandlingPendingUpdatesAlso soWeNeedTo doTheUpdation 
	ST[iCurrNode].elementSum = ST[2*iCurrNode].elementSum + ST[2*iCurrNode+1].elementSum;
	ST[iCurrNode].squaredSum = ST[2*iCurrNode].squaredSum + ST[2*iCurrNode+1].squaredSum;
 	 
	return (ans1+ans2);
}

 
int main() 
{
	int t;
	cin>>t;
 
	while(t--)
	{ 
		int n, nQ;
		cin>>n>>nQ;
		
		int *arr = new int[n];
		for(int i=0; i<n; i++)
		cin>>arr[i];
		
		node *ST = new node[4*n];
		data *PU = new data[4*n];
	 
		buildLazySegmentTree(arr, ST, 0, n-1, 1);
		
		
		while(nQ--)
		{	int type;
			cin>>type;
			
			if(type==0 || type==1)           // type=0 is setValueTo'x',  type=1 is increaseValueBy'x'
			{	int rLeft, rRight, x;
				cin >> rLeft >> rRight >> x;
				rangeUpdate_inLazySegmentTree(arr, ST, PU, 0, n-1, rLeft-1, rRight-1, type, x, 1);   }	 
			else if(type==2)                 // type=2 is findTheSquaredSum 
			{	int rLeft, rRight;
				cin >> rLeft >> rRight;
				cout<<rangeQuery_inSegmentTree(ST, PU, 0, n-1, rLeft-1, rRight-1, 1)<<endl;	  }	  }
	}
}


/*

Here, (rStart, rEnd, rMid, rLeft, rRight) belongs to [0,n-1]
But if que says that, (rLeft, rRight) in input belongs to [1,n] then use (rLeft-1, rRight-1) in function call

*/


  






