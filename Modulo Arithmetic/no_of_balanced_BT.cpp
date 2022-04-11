#include <bits/stdc++.h>
using namespace std;

long m = pow(10,9) + 7;
                                                                                          
long noOfBalancedBTsM(long *arr, long h)                             // Memorization { O(n) }
{
	if(h==0 || h==1)       
	return 1;
    else if(arr[h]!=-1)
	return arr[h];	
   
	long c1 = noOfBalancedBTsM(arr, h-1)%m;
	long c2 = noOfBalancedBTsM(arr, h-2)%m; 
	
	arr[h] = ( ( (c1*c1)%m + (c1*c2)%m )%m + (c2*c1)%m )%m; 
	return arr[h];
}


int main()
{ 
	int t;
	cin>>t;

	while(t--)
	{
        long h;
	    cin>>h; 
	
    	long arr1[h+1];
    	for(int i=0; i<h+1; i++)
    	arr1[i] = -1; 
   
        cout<<noOfBalancedBTsM(arr1, h)<<endl;   
	} 
}

















