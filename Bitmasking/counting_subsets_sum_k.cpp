#include <bits/stdc++.h>
using namespace std;
                                
                                                         
int countingSubsetsSumK1(int *arr, int n, int k)      // using Recursion                          
{
	if(n==0 && k==0)
	return 1;
	else if(n==0 && k!=0)
	return 0;
	
	
	int c1 = countingSubsetsSumK1(arr, n-1, k-arr[n-1]);        // including arr[n-1]
	int c2 = countingSubsetsSumK1(arr, n-1, k);                 // excluding arr[n-1]
	
	 
	return (c1+c2);
}
                                                           
int countingSubsetsSumK2(int *arr, int n, int k) // using Bit Masking        
{
	int count = 0;
	 
    for(int maskNo=0; maskNo<(1<<n); maskNo++)   // array will have total (1<<n) subsets
    { 
        int sum=0;                               // (sum of the elements) of current subset       
        
	    for(int i=0; i<n; i++)                   // considering binary of maskNo as current (n bits Bit String) 
	    {
		    if(!(maskNo & (1<<i)))   // ith bit of maskNo is (1/0) corresponds to (including/excluding) arr[i] in current subset             
		    sum += arr[i];                  
		}
		
		if(sum == k)
		count++;
    }
 
	return count; 
}
                                                              
                                                                                                   
int main()
{
	int n=5, arr[5]={10,3,2,5,20}, k=20;
	
	cout<< countingSubsetsSumK1(arr, n, k) <<endl;
	cout<< countingSubsetsSumK2(arr, n, k) <<endl;
}
 

 







