#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;                // here range of k & arr[i] is high so use long long                        


ll maxSuffixSum(ll *arr, ll n)                        
{
	ll currSuffixSum = 0;                      
	ll maxSuffixSum = INT_MIN;     
	
	for(ll i=n-1; i>=0; i--)
	{
		currSuffixSum += arr[i];
		  
		maxSuffixSum = max(maxSuffixSum, currSuffixSum);
	}
	
	return maxSuffixSum;
}

ll kadaneSum(ll *arr, ll n)                               
{
	ll currSum = 0;                      
	ll maxSum = INT_MIN;               // max subarray sum ending at 'i'
	
	for(ll i=0; i<n; i++)
	{
		currSum += arr[i];
		 
		if(currSum < 0)
		currSum = 0;
		
		maxSum = max(maxSum, currSum);
	}
	
	return maxSum;
}

ll maxPrefixSum(ll *arr, ll n)                         
{
	ll currPrefixSum = 0;                     
	ll maxPrefixSum = INT_MIN;       
	
	for(ll i=0; i<n; i++)
	{
		currPrefixSum += arr[i];
		  
		maxPrefixSum = max(maxPrefixSum, currPrefixSum);
	}
	
	return maxPrefixSum;
}

ll totalSum(ll *arr, ll n)                         
{
	ll totalSum = 0;                     
 
	for(ll i=0; i<n; i++)
	totalSum += arr[i];
 
	return totalSum;
}

ll maxSumSubarrayIn_K_ConcatenatedArray(ll *arr, ll n, ll k)                         
{
	ll MSS = maxSuffixSum(arr, n);  
	ll KS = kadaneSum(arr, n);                   
	ll MPS = maxPrefixSum(arr, n);
	ll TS = totalSum(arr, n);                    
	
	if(k==1)
	return KS;
	else
	{
	    if(TS>=0)
		return max(KS, MSS + TS*(k-2) + MPS);	
		else
		return max(KS, MSS + MPS); 
	} 
}
 
int main()
{ 
	ll k=4, arr[] = {-3,6,-2,-1,5,1};

    cout << maxSumSubarrayIn_K_ConcatenatedArray(arr, 6, k) << endl; 
}








