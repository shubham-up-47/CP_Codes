#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

  // SOE = Sieve of Eratosthenes, ETF = Euler Totient Function 
  
ll* create_ETFarray_using_SOEconcept(ll n)             // { O(nlog(logn)) }
{ 
	ll *ETF = new ll[n+1];    
	for(int i=0; i<n+1; i++)
    ETF[i] = i;


	ETF[1] = 1;
	for(int i=2; i<n+1; i++)
	{
		if(ETF[i] == i)                                // then i is prime 
		{
			ETF[i] = i-1;                              // [|](prime) = prime-1 = (prime*(prime-1))/prime
			
			for(int j=2*i; j<n+1; j+=i)                // multiply the contribution of prime(i) in its multiples(k*i)
			ETF[j] = (ETF[j]*(i-1))/i;
		}
	}
   
	return ETF;
}


int main()
{ 
	int t;
	cin>>t;

	while(t--)
	{
       ll n;
       cin>>n;
       
       ll *ETF = create_ETFarray_using_SOEconcept(n);       // this will give RunTimeError for very big numbers due to lack of memory
       
       for(ll i=1; i<=n; i++)
       cout<<ETF[i]<<" ";
	   cout<<endl; 
	}
}








