#include <bits/stdc++.h>
using namespace std;

  // Subarray = continguous part of array

int findMaxSumSubarray(int *arr, int n)   // Kadane's Algorithm                     
{
	int currSum = 0;                      // max sum ending at 'i'
	int maxSum = 0;
	
	for(int i=0; i<n; i++)
	{
		currSum += arr[i];
		 
		if(currSum < 0)
		currSum = 0;
		
		maxSum = max(maxSum, currSum);
	}
	
// 	// Code which also works for the edge case of all negative integer arrays:
// 	int prevSum = arr[0];
// 	int maxSum = arr[0];
// 	for(int i=0; i<n; i++)
// 	{
// 		prevSum = max(arr[i], prevSum+arr[i]);
// 		maxSum = max(maxSum, prevSum);
// 	}
	
	return maxSum;
}

 
int main()
{ 
	int arr[] = {-3,6,-2,-1,5,1};

    cout << findMaxSumSubarray(arr, 6) << endl; 
}
