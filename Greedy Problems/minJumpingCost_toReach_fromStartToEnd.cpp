#include <bits/stdc++.h>
using namespace std;

 
int main()
{
    int n;
    cin>>n;
    
    int A[n];
    for(int i=0; i<n; i++)
    cin>>A[i];
    
    
    long totalCost=0, i=0, j, k=n-1;
    
    
    while(i < k)          // loop breaks at (i==k) & (j==k)            
    {
    	j = i+1;
    	
    	while(j < k)
    	{
    		if(abs(A[i]) > abs(A[j]) || (abs(A[i])==abs(A[j]) && A[i]>0))                                     
		    break;
		    else
		    j++;
		} 
		
		totalCost += ((j-i)*A[i] +(j*j-i*i)*A[i]*A[i]);
		i = j;
	}
	
	cout << totalCost << endl; 
}








