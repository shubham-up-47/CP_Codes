#include <bits/stdc++.h>
using namespace std;
                                
// checking whether (subset having elements sum = k) exist or not
// arr[i][j] = subset having sum j is present or not when (i = no of elements) & (j = target sum)
                                                                             
bool checkSubsetSumK_DP1(int *arr, int n, int k)                               
{
    bool dp[n+1][k+1]; 
	 
	dp[0][0] = 1;
	for(int i=1; i<n+1; i++)
	dp[i][0] = 1; 
	for(int j=1; j<k+1; j++)
	dp[0][j] = 0; 
	
	for(int i=1; i<n+1; i++)          // for filling dp[i] values we need dp[i-1] values only                                                 
	{   for(int j=1; j<k+1; j++)             
        {	                          // using (previous row data) to calculate (current row data)
        	if(j-arr[i-1] >= 0)                                                               
         	dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];                              
            else
            dp[i][j] = dp[i-1][j];        
		}
    }
  
	return dp[n][k];
}
                                                           
int checkSubsetSumK_DP2(int *arr, int n, int k)                    
{
    bool dp[2][k+1];                // for filling dp[i] values we need dp[i-1] values only, so using 2 X k+1 size dp[] array  
	  
	dp[0][0] = 1;                   // filling dp[0] values
	for(int j=1; j<k+1; j++)
	dp[0][j] = 0; 
	
	int flag = 1;                   // we know (1^1 = 0) and (0^1 = 1) 
	dp[1][0] = 1; 
	for(int i=1; i<n+1; i++)                                                   
	{   for(int j=1; j<k+1; j++)             
        {	                        // using (previous row data) to calculate (current row data)
        	if(j-arr[i-1] >= 0)                                                                
         	dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-arr[i-1]];                              
            else
            dp[flag][j] = dp[flag^1][j];       
		} 
		flag = flag^1;             // toggle prevRow and currRow 
    }
  
	return dp[flag^1][k];
}
                                                              
                                                                                                   
int main()
{
	int n=5, arr[5]={10,3,2,5,20}, k=23;
	
	cout<< checkSubsetSumK_DP1(arr, n, k) <<endl;
	cout<< checkSubsetSumK_DP2(arr, n, k) <<endl;
}
 

 














