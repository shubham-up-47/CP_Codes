#include <bits/stdc++.h>
using namespace std;
 

int main()
{ 
	long n, a, b, xMin=LONG_MAX, xMax=LONG_MIN, minCost=LONG_MAX;
	cin>>n>>a>>b;
	
	
	long arr[n];
	for(long i=0; i<n; i++)
	{   cin>>arr[i];                                     // storing input sequence
	 
	    xMin = min(xMin, arr[i]);
	    xMax = max(xMax, arr[i]);	}
 
 
	for(long i=xMin; i<=xMax; i++)                       // checking the costCorrespondingToEachNumber in sequence range i.e. [xMin, xMax]  
	{   
	    long incr=0, decr=0, cost;
	    
	    for(int j=0; j<n; j++)
	    {
	    	if(i > arr[j])                               // increment needed (to reach to number 'i')
	    	incr += (i-arr[j]);
	    	else                                         // decrement needed (to reach to number 'i')
	    	decr += (arr[j]-i);
		}
	
	
	    if(decr <= incr)                                 // allTheRequiredDecrement (to reach to number 'i') willBeDoneAlongWith sameAmountOfIncrement byPaying'a'Coins                              
	    {   cost = decr*a + (incr-decr)*b;               // (a = costForIncreaseOneDecreaseOne) & (b = costForIncreaseOne) 
		    
		    minCost = min(minCost, cost);   } 
	}
 
    cout << minCost << endl; 
}




/*

5 2 1
1 2 3 4 5

*/


/*

3 2 1
5 5 5

*/


/*

4 1 2
3 4 2 2

*/














