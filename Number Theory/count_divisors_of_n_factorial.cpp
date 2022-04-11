#include<bits/stdc++.h>
using namespace std;

#define MAX 500001                // 1 <= N <= 500000
#define m 1000000007
#define pb push_back

typedef long long ll;

vector<int> sieveStoringPrimes()
{
	bool isPrime[MAX];

	vector<int> prime;
	for(int i=2; i<MAX; i++)
	isPrime[i] = true;
	
	for(int i=2; i*i<MAX; i++)
	{ 
		if(isPrime[i])
		{
			for(int j=i*i; j<MAX; j+=i)
			isPrime[j] = false;
		}
	}

	prime.pb(2);
	for(int i=3; i<MAX; i+=2)
	{
		if(isPrime[i])
		prime.pb(i);
	}
	
	return prime; 
}

ll countDivisorsOf_n_Factorial(int n, vector<int> &prime)
{
	ll c = 1;
	
	for(int i=0; prime[i]<=n; i++)
	{
		ll a=0, p=prime[i]; 
		
		while((n/p) != 0)                      // calculating a (power of prime[i] in n!) 
		{
			a = (a%m + (n/p)%m)%m;             
			p = p*prime[i];
		}
		
		c = (c%m * (a+1)%m)%m;                 // multiply the diviser contribution factor due to the current prime 
	}
	
	return c;
}


int main()
{ 
	int t;
	cin>>t;
	
	vector<int> prime = sieveStoringPrimes();         // storing all primes from 1 to n
	
	while(t--)
	{
		int n;
		cin>>n;
		
		cout<< countDivisorsOf_n_Factorial(n, prime) <<endl;
	} 
}








