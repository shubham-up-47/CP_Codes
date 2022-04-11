#include <bits/stdc++.h>
using namespace std;


int arr[3][4] = {{0,-2,-3,1},{-1,4,0,-2},{1,-2,-3,0}};

int maxSumRectangleDP1(int m, int n)
{ 		
	int dp[m][n];                     // dp[i][j] = sum of elements of rectangle {starting from (0,0)} and {ending at (i,j)}                                         
	 
    dp[0][0] = arr[0][0]; 
    
	for(int i=1; i<m; i++)
    dp[i][0] = dp[i-1][0] + arr[i][0];
    
	for(int j=1; j<n; j++)
    dp[0][j] = dp[0][j-1] + arr[0][j];
     
	for(int i=1; i<n; i++)
	{   for(int j=1; j<n; j++)
        dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];   }
    
    
    int maxR = INT_MIN;
     
    for(int x1=0; x1<n; x1++)               // O(n^4)
    {	for(int y1=0; y1<n; y1++)
    	{	for(int x2=x1; x2<n; x2++)
    		{	for(int y2=y1; y2<n; y2++)
    			{              // currR = sum of elements of rectangle {starting from (x1,y1)} and {ending at (x2,y2)}  
    				int currR = dp[x1][y1] - dp[x1][y2] - dp[x2][y1] + dp[x2][y2];
    			    maxR = max(maxR, currR);
				} 
			} 
		} 
	}
  
  
    return maxR;
}

int maxSumSubarray(vector<int> &arr)  // Kadane's Algorithm { O(n) }                   
{
	int currSum = 0;                      // max subarray sum ending at 'i'
	int maxSum = 0;
	
	for(int i=0; i<arr.size(); i++)
	{
		currSum += arr[i];
		 
		if(currSum < 0)
		currSum = 0;
		
		maxSum = max(maxSum, currSum);    // check whether max sum ending at 'i' is maxSum or not
	}
	
	return maxSum;
}

int maxSumRectangleDP2(int m, int n)     // O(n^3)
{
	int maxR = INT_MIN;
                                                                    
    for(int l=0; l<n; l++)            // finding max sum rectangle between (lth column to rth column)         
    {
        vector<int> v(m,0);           // v[i] = sum of all (ith row element) between (lth column to rth column) 
            
        for(int r=l; r<n; r++)
        {
            for(int i=0; i<m; i++)   
            v[i] += arr[i][r];
                
            maxR = max(maxR, maxSumSubarray(v));     // finding maximum sum subarray/rectangle between (lth column to rth column) 
        }
    }
       
	return maxR;
}
                                        
				                                                                                
int main()
{ 
    int m=3, n=4;
 		
    cout<< maxSumRectangleDP1(m, n) <<endl; 
    
    cout<< maxSumRectangleDP2(m, n) <<endl;  
}

 













 
