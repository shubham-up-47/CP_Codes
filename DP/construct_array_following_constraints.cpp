#include <bits/stdc++.h>
using namespace std;


class Count
{      public:
   long fillOne;
   long fillNonOne;	 
};


int main()
{ 
	long n=4, k=3, x=2;                  // [1 2 1 2], [1 2 3 2], [1 3 1 2]       
	
	
	
	Count dp[n];                         // applying DP by creating array                  
	
	dp[0].fillOne = 1;
	dp[0].fillNonOne = 0;
	
	for(long i=1; i<n; i++)
	{
		dp[i].fillOne = dp[i-1].fillNonOne*(k-1);
	    dp[i].fillNonOne = dp[i-1].fillOne + dp[i-1].fillNonOne*(k-2);                               
	}
	
	if(x==1)
	cout << dp[n-1].fillOne << endl;
	else
	cout << dp[n-1].fillNonOne << endl;
	
	

 // whenever noOfWaysIsAsked then weDon'tNeedToConstructTheArray, tryToThinkLogically more & more toBecomeExpertInCP 
 
	long oneCount = 1;                   // applying DP without creating array  
	long nonOneCount = 0;                                                      
	
	for(long i=1; i<n; i++)              // pI = previous index
	{
	    long pIoneCount = oneCount;
	    long pInonOneCount = nonOneCount;
		
		
		oneCount = pInonOneCount*(k-1);
	    nonOneCount = pIoneCount + pInonOneCount*(k-2);                               
	}
	
	if(x==1)
	cout << oneCount << endl;
	else
	cout << nonOneCount << endl;
}














