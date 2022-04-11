#include <bits/stdc++.h>
using namespace std;


/*

In OrderdSet, dataIsStored inSortedOrder & duplicateValues areNotAllowed (bcz it uses BST implementation)   
In UnorderedSet, dataIsStored inUnsortedOrder & duplicateValues areNotAllowed (bcz it uses Hash Table implementation)   
           
In MultiSet, dataIsStored inSortedOrder & duplicateValues areAllowed (bcz it uses BST implementation)  
In MultiSet, insert() erase() binary_search() lower_bound() upper_bound() takes O(logn) time  

*/


bool compare(const pair<int,int> &a, const pair<int,int> &b)      // sortingTheArray onTheBasisOfValues ofPieces
{
    if(a.second != b.second)
	return (a.second > b.second);
	else	
	return (a.first < b.first);
}


int main()
{
	int n, k, mMax, vMax=0;                        // n = noOfPieces, k = noOfBags, mMax=maxMass'ith'BagCanStore, vMax = maxValueThatTheifCanTheft 
	cin>>n>>k;
	
	
	pair<int,int> p[n]; 
	for(int i=0; i<n; i++)                         // (p[i].first = mass) & (p[i].first = value) of the Piece 'i'
	{   cin>> p[i].first >> p[i].second;   }


	multiset<int> h;
	for(int i=0; i<k; i++)                         // O(k*logk)
	{	cin>>mMax;
		h.insert(mMax);   }
	
 
	sort(p, p+n, compare);                         // O(n*logn) 
	
	
	for(int i=0;  i<n && h.size()>0;  i++)         // O(n*logk)
	{ 
	    multiset<int>::iterator it = h.lower_bound(p[i].first);   // lower_bound(x) returns iterator pointing to 1st element which has value >= x 
		
	 	// useLeastEligibleBags(usingLowerBound) forHighValuePiece, bcz someLowValuePiece canHaveHighMass
		
		if(it != h.end())    
		{   vMax += p[i].second;
		    h.erase(it);   }		
	}
	
	cout << vMax << endl;
}














