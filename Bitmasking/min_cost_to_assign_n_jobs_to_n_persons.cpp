#include <bits/stdc++.h>
using namespace std;

                   // Memorization (recursive)
int minCostToAssignJobsM(int cost[4][4], int n, int i, int maskNo, int *arr)                         
{
	if(i >= n)
	return 0;
	else if(arr[maskNo] != INT_MAX)
	return arr[maskNo];
	
	int minCost = INT_MAX;
	for(int j=0; j<n; j++)         // considering binary of 'maskNo' as current 'n' bit 'Bit String'                
	{
		if(!(maskNo & (1<<j)))     // if 'j'th bit is 0, then make 'j'th bit 1 (assign 'j'th Job to 'i'th Person i.e. pay cost[i][j])                             
		{   int r = minCostToAssignJobsM(cost, n, i+1, maskNo|(1<<j), arr) + cost[i][j];            
			
			minCost = min(minCost, r);	 } 
	}
	
	arr[maskNo] = minCost;
	return arr[maskNo]; 
}

                   // Dynamic Programming (iterative)
int minCostToAssignJobsDP(int cost[4][4], int n)                         
{
    int *dp = new int[1<<n];
    for(int i=0; i<(1<<n); i++)
    dp[i] = INT_MAX;
    
	dp[0] = 0;
 
    for(int maskNo=0; maskNo<(1<<n)-1; maskNo++) 
    { 
        int i=0;
		for(int t=maskNo; t>0; t/=2)   // count no of set bits in maskNo
		{ 
		    if(t%2 == 1)
		    i++;
		}
                                       // assigning Job to 'i'th Person (where i = no of 1s in current 'n' bit 'Bit String')
	    for(int j=0; j<n; j++)         // considering binary of 'maskNo' as current 'n' bit 'Bit String' 
	    {
		    if(!(maskNo & (1<<j)))     // if 'j'th bit is 0, then make 'j'th bit 1 (assign 'j'th Job to 'i'th Person i.e. pay cost[i][j])              
		    dp[maskNo|(1<<j)] = min(dp[maskNo|(1<<j)], dp[maskNo]+cost[i][j]);                  
		}
    }
	 
	return dp[(1<<n)-1]; 
}


int main()
{                                      // 4 Jobs for 4 Persons
	int cost[4][4] = {{10,2,6,5}, {1,15,12,8}, {7,8,9,3}, {15,13,4,10}};                                                     

    int *arr = new int[1<<4];
    for(int i=0; i<(1<<4); i++)
    arr[i] = INT_MAX;
    
    cout << minCostToAssignJobsM(cost, 4, 0, 0, arr) << endl;
	
    cout << minCostToAssignJobsDP(cost, 4) << endl; 
}
 
 
 // best way to pass (const size static 2D array) in function











 
