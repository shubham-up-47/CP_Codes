#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;

 
int main()
{
    ll count=1, n, lastIndex=n-1;
	cin>>n;
	
	ll arr[n];
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	
	queue<ll> insrtdE;
	
	
	sort(arr, arr+n);
	while(n>0 || insrtdE.size()>0)
	{
	   if(n>0 && (arr[n-1]>insrtdE.front() || insrtdE.size()==0))	                          
	   {  ll x = arr[n-1];
	      cout<<"("<<count<<" - "<<x<<") \n"; 
	      n--;
		  
		  if(x/2 > 0)
		  insrtdE.push(x/2);  }
	   else
	   {  ll x = insrtdE.front();
	      cout<<"("<<count<<" - "<<x<<") \n"; 
	      insrtdE.pop(); 
		  
		  if(x/2 > 0)
		  insrtdE.push(x/2);  }
	    
	   count++;	 
	}  
}












 
