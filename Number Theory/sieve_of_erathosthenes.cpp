#include <bits/stdc++.h>
using namespace std;


int findingPrimesFrom_1_To_n(int n)         // making Sieve of Erathosthenes
{ 
	bool isPrime[n+1];                      // [make boolean array]
	for(int i=0; i<n+1; i++)                // mark all numbers as prime(true)
	isPrime[i] = true;
		
		
	isPrime[0] = false;                     // mark 0 & 1 as not prime(false)   [initialization]
	isPrime[1] = false;         
 
	for(int i=2; i<sqrt(n+1); i++)          // mark all composite numbers from 2 to n as not prime(false)  
	{
		if(isPrime[i] == true)          
		{
			for(int j=(i*i); j<n+1; j+=i)   // mark all the multiples of prime(true) i as not prime(false)  
			isPrime[j] = false; 
		}
	}


	int count = 0;
	for(int i=0; i<n+1; i++)
	{	
	    if(isPrime[i] == true)
		{ 
		    cout<<i<<" ";                    // print prime(true)
		    count++;	                     // count prime(true)
		}
    }
    cout<<endl;
	
	return count; 
}


int main()
{
	int n = 35;
 
	int primeCount = findingPrimesFrom_1_To_n(n); 
	cout<<"Count: "<<primeCount<<endl; 
}









