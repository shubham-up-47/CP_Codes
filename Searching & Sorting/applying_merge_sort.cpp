#include <bits/stdc++.h>
using namespace std;


typedef long long ll;     // (start = StartIndex) (mid = MiddleIndex) (end = EndIndex) (L = LeftHalfArray) (R = RightHalfArray)


ll inversionsCountRelative(ll arr[], ll startL, ll endL, ll startR, ll endR) // Relative Inversions Count while Merging Sorted Arrays
{ 
	ll relativeCount = 0;
	
	
	ll i = startL;
	ll j = startR; 
	ll k = 0;
	
	ll arrMerged[endR - startL + 1];

	while(i<=endL && j<=endR)
	{
		if(arr[i] <= arr[j])
		{   arrMerged[k] = arr[i];
		    i++,k++;   }
		else if(arr[i] > arr[j])
		{	arrMerged[k] = arr[j];
		    j++,k++;
		                                   
			relativeCount += (endL-i+1);   }             // counting Inversions in LeftHalfArray due to arr[j]
	}
	
	while(i <= endL)
	{	arrMerged[k] = arr[i];
	    i++,k++;   }
	
	while(j <= endR)
	{	arrMerged[k] = arr[j];
	    j++,k++;   }
 
	for(ll i=startL,k=0;  i<=endR;  i++,k++)
	arr[i] = arrMerged[k];


	return relativeCount;
}


ll inversionsCount(ll arr[], ll start, ll end)           // Inversions Count using Merge Sort
{ 
	if(start < end)
	{
		int mid = (start + end)/2;

		ll leftCount = inversionsCount(arr, start, mid);
		ll rightCount = inversionsCount(arr, mid+1, end);
		ll relativeCount = inversionsCountRelative(arr, start, mid, mid+1, end);

		return (leftCount + rightCount + relativeCount);
	}
	else
	return 0; 
}
 

int main()
{
    ll n;
    cin >> n;

    ll *arr = new ll[n]; 
    for(ll i=0; i<n; i++)
    cin >> arr[i];
 
    cout << inversionsCount(arr, 0, n-1) << endl; 
}











 



