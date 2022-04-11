#include <bits/stdc++.h>
using namespace std;


/*

*getting coin change for V rupees using D[] coins
*arr[V][n] = no of ways to get coin change for V rupees using D[] ('n' sized Array containing coins)
*don't forget to rake "long" & "%1000000007" as per instruction in question


Note:
*coin change (2 1 1 1), (1 2 1 1), (1 1 2 1), (1 1 1 2) are same for 5 rupees                                 
*so recursive code for Staircase Problem & CoinChange Problem are totally different                  

*/


#define m 1000000007


long coinChangeBF(long V, long *D, long n)                      // Brute Force
{
	if(V==0)                                                    // coinChangePossible correspondingToCurrentFunctionCall 
	return 1;
	else if(V<0 || n==0)                                        // coinChangeNotPossible correspondingToCurrentFunctionCall
    return 0;
 
 
	long r1 = coinChangeBF(V-D[n-1], D, n)%m;                   // including last coin
	long r2 = coinChangeBF(V, D, n-1)%m;                        // excluding last coin
 
 
	return (r1 + r2)%m;
}


long coinChangeM(long V, long *D, long n, long **arr)           // Memorization               
{
	if(V==0)                                                    // coinChangePossible correspondingToCurrentFunctionCall 
	return 1;
	else if(V<0 || n==0)                                        // coinChangeNotPossible correspondingToCurrentFunctionCall
    return 0;
	else if(arr[V][n]!=-1) 
	return arr[V][n];
 
 
	long r1 = coinChangeM(V-D[n-1], D, n, arr)%m;               // including last coin
	long r2 = coinChangeM(V, D, n-1, arr)%m;                    // excluding last coin
    arr[V][n] = r1 + r2;
 
 
	return arr[V][n]%m;
}

 
long coinChangeDP(long V, long *D, long n)                      // Dynamic Programming                         
{ 
    long arr[V+1][n+1];         
    
    
    arr[0][0] = 1;
	for(int i=1; i<V+1; i++)
	arr[i][0] = 0;
	for(int j=1; j<n+1; j++)
	arr[0][j] = 1;
 
 
	for(int i=1; i<V+1; i++)
	{   for(int j=1; j<n+1; j++)
        { 
        	if(i-D[j-1] >= 0)                                   // including + excluding last coin
			arr[i][j] = arr[i-D[j-1]][j]%m + arr[i][j-1]%m;   
			else                                                // excluding last coin
			arr[i][j] = arr[i][j-1]%m;  
		} 
    }
  
  
	return arr[V][n];
}


int main() 
{
	
	long V=5, n=4, D[]={2,3,1,4};
	
	
	cout << coinChangeBF(V, D, n) << endl;
	
	
	long **arr = new long*[V+1]; 
	for(int i=0; i<V+1; i++)            
	{	arr[i] = new long[n+1];
	    for(int j=0; j<n+1; j++)            
	    arr[i][j] = -1;   } 
	cout << coinChangeM(V, D, n, arr) << endl;
	
	
	cout << coinChangeDP(V, D, n) << endl;
}












 




