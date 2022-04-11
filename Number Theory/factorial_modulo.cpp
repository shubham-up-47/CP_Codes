#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


int findPowerModulo(int x, int n, int m)
{
	if(x==0 || m==1)
	return 0;
	else if(n==0)
	return 1;
	 
	long r, t = findPowerModulo(x, n/2, m);
	 
	if(n%2 == 0)     
    r = (t*t)%m;
    else 
	r = ((t*t)%m * x%m)%m;         
	
	return (r+m)%m;                                            
}


ll findFactorialModulo(ll n, ll p)
{
    ll r = 1;
    
    for(ll i=n+1; i<=p-1; i++)                       // Wilson's Theorem
    {
        ll t = findPowerModulo(i, p-2, p);           // Fermat's Little Theorem
        r = (r*t)%p;
    }
    
    r *= -1;
    r += p;
    
    return r;
}


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ll n, p;
        cin>>n>>p;
        
        if(n >= p)
        cout<<0<<endl;
        else
        cout<<findFactorialModulo(n,p)<<endl; 
    } 
}







