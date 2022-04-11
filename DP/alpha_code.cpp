#include <bits/stdc++.h>
using namespace std;


int countAlphaCodesBF(int *code, int n)                          // Brute Force
{
	if(n==0 || n==1) 
	return 1;
 
 
	int r; 
	if(code[n-2]*10 + code[n-1] <= 26) 
	r = countAlphaCodesBF(code, n-1) + countAlphaCodesBF(code, n-2);
	else 
	r = countAlphaCodesBF(code, n-1);
 
 
	return r;
}


int countAlphaCodesM(int *code, int n, int* arr)                 // Memorization               
{
	if(n==0 || n==1) 
	return 1;
	else if(arr[n]!=-1) 
	return arr[n];
 
 
	if(code[n-2]*10 + code[n-1] <= 26) 
	arr[n] = countAlphaCodesM(code, n-1, arr) + countAlphaCodesM(code, n-2, arr);
	else 
	arr[n] = countAlphaCodesM(code, n-1, arr);
 
 
	return arr[n];
}

 
int countAlphaCodesDP(int *code, int n)                           // Dynamic Programming                         
{ 
	int *arr = new int[n+1];
	
	arr[0] = 1;
	arr[1] = 1;

	for(int i=2; i<=n; i++)                        // arr[i] = no of Alphabetical codes corresponding to first i digits of Numerical code
	{
    	if(code[i-2]*10 + code[i-1] <= 26) 
    	arr[i] = arr[i-1] + arr[i-2];
	    else 
    	arr[i] = arr[i-1];
	}
	 
	int count = arr[n];
	delete [] arr;
	return count;
}


int main() 
{
	
	int n=4, code[]={2,3,1,4};
	
	
	cout << countAlphaCodesBF(code, n) << endl;
	
	
	int *arr = new int[n+1]; 
	for(int i=0; i<n+1; i++)                        // arr[i] = no of of Alphabetical codes corresponding to forst i digits of
	arr[i] = -1;
	cout << countAlphaCodesM(code, n, arr) << endl;
	
	
	cout << countAlphaCodesDP(code, n) << endl;
}


















