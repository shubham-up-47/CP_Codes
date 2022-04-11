#include<bits/stdc++.h>
using namespace std;


#define MAX 100001                  // 1 <= u <= 10^10 


vector<int> createSieveOfSmallPrimes()     
{ 
	bool isPrime[MAX];
	for(int i=0; i<MAX; i++)
	isPrime[i] = true;
	
	for(int i=2; i<=sqrt(MAX); i++)
    {
		if(isPrime[i])
        {
			for(int j=i*i; j<MAX; j+=i)
			isPrime[j] = false;
		}
	}
    
    
	vector<int> smallPrime;
    
	smallPrime.push_back(2); 
	for(int i=3; i<MAX; i+=2)
    {   if(isPrime[i])
		smallPrime.push_back(i);   }
    
	return smallPrime;
}


void printPrimesInGivenRange(long long l, long long u, vector<int> &smallPrime)
{
	bool isPrime[u-l+1]; 
	for(long long i=l; i<=u; i++)
	isPrime[i-l] = true;
	

	for(int i=0; smallPrime[i]<=sqrt(u); i++)
    {
		int p = smallPrime[i];         	
	
        long long m;                        // m is multiple of p where (m is in range [l,u]) & (m >= p*p)                                              
        if(l <= p*p)
        m = p*p;
        else if(l%p == 0)
        m = l;
        else
        m = l-(l%p) + p;
                              
		for(long long j=m; j<=u; j+=p)   	// mark all multiples of p in range [l,u] as false
		isPrime[j-l] = false;   
	}

	for(long long i=l; i<=u; i++)
    {
		if(isPrime[i-l] == true)
		cout<<i<<" ";
	}
}


int main()
{
	vector<int> smallPrime = createSieveOfSmallPrimes();
    
	int t;
	cin>>t;
    
	while(t--)
    {
		long long l,u;
		cin>>l>>u;
        
        if(l <= 2)
        l = 2;
        
		printPrimesInGivenRange(l, u, smallPrime);
        cout<<endl;
	} 
}



