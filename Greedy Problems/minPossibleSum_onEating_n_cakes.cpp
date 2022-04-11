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
       
       ll c[n];
       for(ll i=0; i<n; i++)
       cin>>c[i];
       
       sort(c, c+n, greater<int>());
       
       ll sum = 0;
       for(ll i=0; i<n; i++)
       sum += (c[i]*(1<<i));

       cout<<sum<<endl;

	}



}








