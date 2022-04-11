#include <bits/stdc++.h>
using namespace std;

 // bitonic subsequence = values in (strictlyAscendingOrder) ||  (strictlyDescendingOrder) || (strictlyAscendingOrder + strictlyDescendingOrder) 
 // dp1[i] = length of longestStrictlyIncreasingSubsequence endingAtIndex'i' in given array       
 // dp2[i] = length of longestStrictlyDecreasingSubsequence startingAtIndex'i' in given array 
 // maxL = length of longestBitonicSubsequence in given array    
   
int main()
{
  int t;
  cin>>t;

  while(t--)
  {
	long n;
	cin>>n;
	
	long arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];       
	
	
    long dp1[n], dp2[n];                                                           // Dynamic Programming  
    
    
    dp1[0] = 1; 
    for(int i=1; i<n; i++)
    {
       dp1[i] = 1;
	   for(int j=i-1; j>=0; j--)
	   {  if(arr[j] < arr[i] && dp1[j]+1 > dp1[i])
	      dp1[i] = dp1[j] + 1;   }	 
    } 
    
    
    dp2[n-1] = 1; 
    for(int i=n-2; i>=0; i--)
    {
       dp2[i] = 1;
	   for(int j=i+1; j<n; j++)
	   {  if(arr[j] < arr[i] && dp2[j]+1 > dp2[i])
	      dp2[i] = dp2[j] + 1;   }	 
    } 
    
      
    long maxL = 0;
    for(int i=0; i<n; i++)
    maxL = max(maxL, (dp1[i]+dp2[i]-1));
	 
    cout<<maxL<<endl; 
  }
    
}





