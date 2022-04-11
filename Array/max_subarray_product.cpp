#include <bits/stdc++.h>
using namespace std;

  // SP = subarray product (there will always exist some positive product in this question)                        

int maxSubarrayProduct(int *arr, int n)
{
	int maxSP = 1;
	
	int maxSP_endingHere = 1;     // max subarray product ending at 'i'                       
	int minSP_endingHere = 0;     // min subarray product ending at 'i'  

    for(int i=0; i<n; i++)
    {
    	if(arr[i] < 0)
    	{
    	   int temp1=maxSP_endingHere, temp2=minSP_endingHere;              
    	  
		   maxSP_endingHere = max(1, temp2*arr[i]); 	
    	   minSP_endingHere	= min(0, temp1*arr[i]);
		}
    	else if(arr[i] == 0)
    	{
    	   maxSP_endingHere = 1; 	
    	   minSP_endingHere	= 0;
		}
    	else if(arr[i] > 0)
    	{
    	   maxSP_endingHere = maxSP_endingHere*arr[i]; 	
    	   minSP_endingHere	= min(0, minSP_endingHere*arr[i]);
		} 
		
		maxSP = max(maxSP, maxSP_endingHere);
	}
	
	return maxSP;
}


int main()
{ 
	int arr[] = {3,-1,0,6,0,9,-4,-1};
	
	cout << maxSubarrayProduct(arr, 8);
}




















