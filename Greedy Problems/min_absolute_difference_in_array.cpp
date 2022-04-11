#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int main()
{

	int t;
	cin>>t;

	while(t--)
	{
       ll n;
       cin>>n;
       
       ll arr[n];
       for(ll i=0; i<n; i++)
       cin>>arr[i];
       
       sort(arr, arr+n);
       
       ll mD = INT_MAX;
       for(ll i=1; i<n; i++)
       mD = min(mD, abs(arr[i]-arr[i-1]));

       cout<<mD<<endl;
	} 
}








