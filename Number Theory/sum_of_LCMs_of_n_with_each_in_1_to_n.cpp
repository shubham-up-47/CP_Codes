#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

 
ll* arrayStoring_SumOfLCMs_forEachIn_1_to_n(ll n)                                // { O(nlog(logn)) }
{ 
	ll *ETF = new ll[n+1];    
	for(int i=0; i<n+1; i++)
    ETF[i] = i;
  
	for(int i=2; i<n+1; i++)
	{
		if(ETF[i] == i)                            
		{	ETF[i] = i-1;                            
			
			for(int j=2*i; j<n+1; j+=i)               
			ETF[j] = (ETF[j]*(i-1))/i;	 }
	}
    
    
    ll *r = new ll[n+1]; 
	for(int i=0; i<n+1; i++)
    r[i] = 1; 
    
	for(int i=1; i<n+1; i++)
	{   
	    for(int j=i; j<n+1; j+=i)
        r[j] += (i*ETF[i]);   
	} 
	for(int i=1; i<n+1; i++)
	{ 
        r[i] *= i;
        r[i] /= 2;
	} 
	
	return r;
}


int main()                  // 1 <= n <= 10^5 
{
    ll *SOL = arrayStoring_SumOfLCMs_forEachIn_1_to_n(1e5+1);                

 
	int t;
	cin>>t;
 
	while(t--)              // Sum Of LCMs of n with each in [1,n]
	{
       ll n;
       cin>>n;
       
	   cout << SOL[n] << endl; 
	}
}








