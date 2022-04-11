#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
 
  
bool checkPrime1(int n)     // O(n) 
{
    int factorsCount = 0;
  	
    for(int i=1; i<=n; i++)
    {
	    if(n%i == 0)
        factorsCount++;
    }
        
    return (factorsCount==2);  
}


bool checkPrime2(int n)      // O(Vn) = root n   
{
    int factorsCount = 0;
  	
    for(int i=1; i<=sqrt(n); i++)   // considering (i) & (n/i) at the same time
    {
	    if(n%i == 0)
        factorsCount += 2; 
    }
        
	if(n==1)
	return 0;
	else
    return (factorsCount==2);  
}
  
bool checkPrime3(int n)     // O(Vn) = root n
{
    bool r = true;
  	
    for(int i=2; i<=sqrt(n); i++)
    {
	    if(n%i == 0)
        {  r = false;
           break;  }       // this code is more optimized
    }
      
	if(n==1)
	return 0;
	else
    return r;  
}


int findingPrimesFrom_1_To_n(int n)     // making Sieve of Erathosthenes
{ 
	bool isPrime[n+1];                  // [make boolean array]
	for(int i=0; i<n+1; i++)            // mark all numbers as prime(true)
	isPrime[i] = true;
		
		
	isPrime[0] = false;                  // mark 0 & 1 as not prime(false)   [initialization]
	isPrime[1] = false;         
 
	for(int i=2; i<sqrt(n+1); i++)       // mark all composite numbers from 2 to n as not prime(false)  
	{
		if(isPrime[i] == true)          
		{
			for(int j=(i*i); j<n+1; j+=i)  // mark all the multiples of prime(true) i as not prime(false)  
			isPrime[j] = false; 
		}
	}


	int count = 0;
	for(int i=0; i<n+1; i++)
	{	
	    if(isPrime[i] == true)
		{ 
		    cout<<i<<"  ";                // print prime(true)
		    count++;	                 // count prime(true)
		}
    }
    cout<<endl;
	
	return count; 
}

 
int main()
{ 
    int n = 35;
 
 
    for(int i=1; i<=n; i++)
    {   if(checkPrime1(i))
		cout<<i<<"  ";    }
	cout<<endl;
	

    for(int i=1; i<=n; i++)
    {   if(checkPrime2(i))
		cout<<i<<"  ";    }
	cout<<endl;
		
		
    for(int i=1; i<=n; i++)
    {   if(checkPrime3(i))
		cout<<i<<"  ";    }
	cout<<endl;
	
	
	int primeCount = findingPrimesFrom_1_To_n(n); 
	cout<<"Count: "<<primeCount<<endl; 
}















