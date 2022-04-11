#include <bits/stdc++.h>
using namespace std;


long countVariationPairs(int *arr, int n, int k)   // logical search using two variables (i) & (j)            
{
	long vpCount = 0;
	
	sort(arr, arr+n);
	
	for(int i=0,j=1;  j<n;  )
    {
 		if(arr[j] - arr[i] >= k)  // increase (count) & (i) if you get arr[j] for current (i)
 		{  vpCount += (n-j);
		   i++;  }
 		else                      // keep increasing (j) till you get arr[j] for current (i)
 		j++; 
	}
	
	return vpCount;
}

 
int main()
{ 
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	long vpCount = countVariationPairs(arr, n, k); 
	cout<<vpCount<<endl;
}














