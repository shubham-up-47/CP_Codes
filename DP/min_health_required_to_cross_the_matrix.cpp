#include <bits/stdc++.h>
using namespace std;

// health should not be zero at any cell
// matrix[i][j] = strength change at that cell (i,j)  
// finding min health required for moving (rightward/downward only) from (0,0) to (m-1,n-1), so that (health > 0) at all cells  
// arr[i][j] = min health required to move from (i,j) to (m-1,n-1), so that (health > 0) at all cells         
 
 
const int M=3, N=4;
 
int safeHealthAtEnd(int x)
{
	if(x <= 0)
	return (abs(x)+1); 
	else 
	return 1; 
}

int safeHealthInMid(int x, int s)   // x = healthProvided(AtCurrentCell), s = healthRequired(AtNextCell)
{                                   // s > 0 always
	if(x >= 0 && x >= s) 
	return 1; 
	else if(x >= 0 && x < s) 
	return (s-x);
	else if(x < 0)
	return (s+abs(x)); 
}
                                            
int minHealthRequiredBF(int matrix[][N], int m, int n, int i=0, int j=0)                  // Brute Force { O(2^x) where x=max(m,n) } 
{
	if(i>=m || j>=n)       
	return INT_MAX;
	else if(i==m-1 && j==n-1)
	return safeHealthAtEnd(matrix[i][j]);
  
  
  
	int s1 = minHealthRequiredBF(matrix, m, n, i+1, j);
	int s2 = minHealthRequiredBF(matrix, m, n, i, j+1);  
 
 
	return safeHealthInMid(matrix[i][j], min(s1,s2));
}
                                            
int minHealthRequiredM(int matrix[][N], int m, int n, int arr[][N], int i=0, int j=0)     // Memorization { O(m*n) }
{
	if(i>=m || j>=n)       
	return INT_MAX;
	else if(i==m-1 && j==n-1)       
	return safeHealthAtEnd(matrix[i][j]);
    else if(arr[i][j] != -1)
	return arr[i][j];	                                            
                                 
								  
	int s1 = minHealthRequiredM(matrix, m, n, arr, i+1, j);
	int s2 = minHealthRequiredM(matrix, m, n, arr, i, j+1);  
 
 
	arr[i][j] = safeHealthInMid(matrix[i][j], min(s1,s2));     
	return arr[i][j];
}
                                         
                                                                                                   
int main()
{ 
    int m=3, n=4;
	int matrix[M][N] = {{0,-2,-3,1},{-1,4,0,-2},{1,-2,-3,0}};
	 				
					 				           	
    cout<<minHealthRequiredBF(matrix, m, n)<<endl;
    
                                         	
	int arr1[M][N];
	for(int i=0; i<m; i++)
	{   for(int j=0; j<n; j++)
	    arr1[i][j] = -1;    }
     cout<<minHealthRequiredM(matrix, m, n, arr1)<<endl; 
                    
                    
    int arr2[M][N];                                                                         // Dynamic Programming { O(m*n) }
    
    arr2[m-1][n-1] = safeHealthAtEnd(matrix[m-1][n-1]); 
    
	for(int i=m-2; i>=0; i--)
    arr2[i][n-1] = safeHealthInMid(matrix[i][n-1], arr2[i+1][n-1]);
    
	for(int j=n-2; j>=0; j--)
    arr2[m-1][j] = safeHealthInMid(matrix[m-1][j], arr2[m-1][j+1]); 
	
	for(int i=m-2; i>=0; i--)
	{   for(int j=n-2; j>=0; j--)
        {	 
	        int s1 = arr2[i+1][j]; 
	        int s2 = arr2[i][j+1]; 
	             
			arr2[i][j] = safeHealthInMid(matrix[i][j], min(s1,s2));    
		}
    }
    cout<<arr2[0][0]<<endl; 
}



// THIS CODE TELLS BEST WAY TO PASS STATIC 2D ARRAY AS ARGUMENT












 


