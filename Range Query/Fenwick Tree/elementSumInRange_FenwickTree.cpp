#include<bits/stdc++.h>
using namespace std;


void update(int *BIT, int n, int i, int x)         // increase arr[i] by x
{ 
	for(int iCN=i+1 ; iCN<n+1; iCN+=(iCN&(-iCN)))  // leftShiftRightmostSetBitOf'iCN'(indexNoOfCurrentNode) toReachIt's/Ancestor'sRightSiblings                       
	BIT[iCN] += x;
}


int query(int* BIT, int i)                         // sum of elements in [0,i]
{
	int sum = 0;
	
	for(int iCN=i+1;  iCN>0;  iCN-=(iCN&(-iCN)))   // removeRightmostSetBitOf'iCN'(indexNoOfCurrentNode) toReachIt'sParent/Ancestor
	sum += BIT[iCN];  
	
	return sum;
}


int main()          // FenwickTree/BinaryIndexedTree/BIT (noNeedToImplementBuildTreeFunction butInitializeBITarrayByZero)
{ 
	int n;
	cin>>n;

	int* arr = new int[n]();                                                             // DynamicArrayInitializedByZero
	int* BIT = new int[n+1]();                                                           // DynamicArrayInitializedByZero
 
	for(int i=0; i<n; i++)
	{	cin >> arr[i];
		update(BIT, n, i, (arr[i]-0));   }                                               // update1 
	
	cout << "Sum of first 5 elements i.e. [0,4] is: " << query(BIT, 4) << endl;          // query1 
	
	update(BIT, n, 2, (11-arr[2]));                                                      // update2
	arr[2] = 11; 
	
	cout << "Sum of elements in [2,6] is: " << query(BIT, 6) - query(BIT, 1) << endl;    // query2                         
}


/*

7
1 2 3 4 5 6 7

*/









