#include <bits/stdc++.h>
using namespace std;


void matrixMultiply(int A[2][2], int B[2][2])
{ 
	int p = A[0][0]*B[0][0] + A[0][1]*B[1][0];
	int q = A[0][0]*B[0][1] + A[0][1]*B[1][1];
	int r = A[1][0]*B[0][0] + A[1][1]*B[1][0];
	int s = A[1][0]*B[0][1] + A[1][1]*B[1][1];

	A[0][0] = p;
	A[0][1] = q;
	A[1][0] = r;
	A[1][1] = s; 
}


void matrixExponent(int M[2][2], int n)        // nth power of matrix M 
{
	if(n==1)
	return;
  
	matrixExponent(M, n/2);                    // (n/2)th power of matrix M 
	
	if(n%2 == 0)                               // n is even
	{  matrixMultiply(M, M);  }                // (t*t)
	else                                       // n is odd 
	{  matrixMultiply(M, M);                   // (t*t*x)
	   int X[2][2] = {{1,1},{1,0}};
	   matrixMultiply(M, X);  }
} 


int fibUsingME(int n)                // nth fibonacci number using ME (Matrix Exponentiation)
{
	if(n==0 || n==1)
	return n;
	
	int M[2][2] = {{1,1},{1,0}};     // matrix M  
	
	matrixExponent(M, n-1);          // finding M^(n-1)
	
	return (M[0][0]*1 + M[0][1]*0);  // finding F(n) by Matrix Multiplication                             
} 


int main()
{ 
	int t;
	cin>>t;

	while(t--)
	{ 
        int n;
      	cin>>n;
    	
      	cout<< fibUsingME(n) <<endl;
	} 
}














