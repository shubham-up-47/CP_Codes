#include<bits/stdc++.h>
using namespace std;


/*

consideringArray(size=yMax+1) {arr[0],arr[1],arr[2]...arr[yMax]} inWhich (arr[y]==y ifRating'y'IsPresentInCoder[]Array) (arr[y]==0 otherwise)  
implementingBIT(size=yMax+2) ofTheAboveArray toTrackNoOf'y'InRange[0,yCurr]PresentInCoder[]Array = sumOfIts&AncestorBIT[]valuesOfNode(yCurr+1)     

BIT[iCN](whoseCorrspondingRangeIs[y1,y2]) = noOfNonZeroValuesIn{arr[y1],arr[y1+1],arr[y1+2]...arr[y2]} = noOf'y'InRange[y1,y2]LessThanOrEqualTo'y2'
BIT[iCN](whoseCorrspondingRangeIs[0,yCurr]) = noOfNonZeroValuesIn{arr[0],arr[1],arr[2]...arr[yCurr]} = noOf'y'InRange[0,yCurr]LessThanOrEqualTo'yCurr'
 
NoOf'y'InRange[0,yCurr]PresentInCoder[]Array = sumOfItsAndAncestorBIT[]valuesOfNode(yCurr+1) 
NodesInBIT[]whoseCorrespondingRangeContains'yCurr' = it'sAndAncestor'sRightSiblingBIT[]valuesOfNodeIndex(yCurr+1) 
 
*/


struct Coder
{
	int iCI;                                            // iCI = indexOfCoderInitially
	int x;
	int y;
};

 
void update(int *BIT, int yMax, int yCurr)              // do'++'InAllTheRangesOf[y1,y2]Containing'yCurr'    
{  
	for(int iCN=yCurr+1; iCN<yMax+2; iCN+=(iCN&(-iCN))) // leftShiftRightmostSetBitOf'iCN'(indexNoOfCurrentNode) toReachIt's/Ancestor'sRightSiblings
	BIT[iCN]++;
}


int query(int *BIT, int yCurr)                          // getCountOfNonZero'y'CorrespondingToRange[0,yCurr]' = noOf'y'LessThanOrEqualTo'yCurr'   
{
	int count = 0;
	
	for(int iCN=yCurr+1;  iCN>0;  iCN-=(iCN&(-iCN)))    // removeRightmostSetBitOf'iCN'(indexNoOfCurrentNode) toReachItsParent/Ancestor
	count += BIT[iCN];  
	
	return count;
}
 

bool compare(Coder A, Coder B)                          // sortOnTheBasisOf'x' & if'x'EqualsThenOnTheBasisOf'y' 
{
	if(A.x != B.x)
	return (A.x < B.x); 
	else  
	return (A.y < B.y); 
}


/*
 
nLC[i] = noOfLowerCoders than'i'thCoder (i=indexOfCoderInitially)

BITcontains countCorrespondingTo'y'sOf[Coder[0],Coder[i-1]] 
 
*/


int main()                                              // here (x=speed) & (y=accuracy) i.e. (x>0) & (y>0)                        
{ 
	int n;
	cin>>n;
	
	Coder arr[n];
	int yMax=INT_MIN;
	
	for(int i=0; i<n; i++)
	{	arr[i].iCI = i;
		cin >> arr[i].x >> arr[i].y;
		
		yMax = max(yMax, arr[i].y);   }


	sort(arr, arr+n, compare);                           
	 
    int BIT[yMax+1]={0}, nLC[n];                       
	
	for(int i=0; i<n; )                               
	{
		int j=i, xCurr=arr[i].x, yCurr=arr[i].y;       // CodersIn[i,j) haveSame(x,y)as(xCurr,yCurr)  {delta'x'==0 & delta'y'==0}      

		while(j<n && arr[j].x==xCurr && arr[j].y==yCurr)
		j++;
  
   
		for(int k=i; k<j; k++)        // query toFindNoOf'y'sLessThanOrEqualTo'yCurr' {(delta'x'==0 & delta'y'>0) || (delta'x'>0)}
		nLC[arr[k].iCI] = query(BIT, yCurr);
	 
		for(int k=i; k<j; k++)        // update theBITbyAdding'j-i'CountsCorrespondingTo'yCurr'      
		update(BIT, yMax, yCurr); 


		i=j;       	
	}
	

	for(int i=0; i<n; i++)
	cout << "Points of Coder" << i << " is: " << nLC[i] << endl; 
}
 

/*

7
5 6
6 7
5 5
7 6
5 6
3 6
7 8

*/







