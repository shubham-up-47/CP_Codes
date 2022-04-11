#include <bits/stdc++.h>
using namespace std;

 // calculating required product without using '/' operator & in O(1) space complexity                             
 
int productOfArrayElementsExceptCurrent(int *A, int n, int *P)
{ 
    for(int i=0; i<n; i++)
    P[i] = 1; 
    

	int leftProduct = 1;   
    for(int i=0; i<n; i++)
    {	
	    P[i] *= leftProduct; 
        leftProduct *= A[i];   
	}
	 
	 
	int rightProduct = 1;   
    for(int i=n-1; i>=0; i--)
    {	
	    P[i] *= rightProduct; 
        rightProduct *= A[i];   
	}
	
	 
	cout<<"P[] : ";
	for(int i=0; i<n; i++)
	cout<<P[i]<<" ";
}


int main()
{ 
	int n=8, A[]={3,-1,7,6,7,9,-4,-1};
	
	int P[n];
	
	productOfArrayElementsExceptCurrent(A, n, P);
}


















