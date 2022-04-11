#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

  // SOE = Sieve of Eratosthenes, ETF = Euler Totient Function 

ll countCoprimesOf_n_using_ETFconcept_and_SOEconcept(ll n)             // { O(nlog(logn)) }
{ 
	bool isPrime[n+1];            
	for(int i=0; i<n+1; i++)              
	isPrime[i] = true;
		
		
	isPrime[0] = false;                   
	isPrime[1] = false;          
	for(int i=2; i<sqrt(n+1); i++)          
	{
		if(isPrime[i] == true)          
		{
			for(int j=(i*i); j<n+1; j+=i)    
			isPrime[j] = false; 
		}
	}


	ll r = n;
	for(int i=0; i<n+1; i++)
	{	
	    if(isPrime[i]==true && r%i==0)      // multiply the contributions of all prime divisor (i) 
		r = (r*(i-1))/i; 
    }
    
	return r; 
}


ll countCoprimesOf_n_using_ETFconcept_and_PrimeCheckconcept(ll n)  // { O(Vn) }
{ 
	ll c=n, i=n;
	
	for(int j=2; j<=sqrt(i+1); j++)
	{
		if(i%j == 0)                                               // j is prime factor of i
		{
			c = (c*(j-1))/j;                                       // multiply the contribution of prime j 
			
			while(i%j == 0)                                        // remove all powers of prime j from i
			i /= j; 
		}
	}
	
	if(i > 1)
    c = (c*(i-1))/i;
    
	return c;
}


int main()
{  
	int t;
	cin>>t;

	while(t--)
	{
       ll n;
       cin>>n;
       
       cout<< countCoprimesOf_n_using_ETFconcept_and_PrimeCheckconcept(n) <<endl;            
	}
}













