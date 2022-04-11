#include <bits/stdc++.h>
using namespace std;

 
// dp[p][i][j] = maxValue can be stored in bag when (p = no of primes provided), (i = no of items provided) & (j = maxWeight that bag can bear)

typedef long long ll;
 
class item
{     public:
    ll v;       // value  
    ll w;       // weight
};

bool compare(item i1, item i2)
{   return (i1.v < i2.v);   }


int main()                                
{ 
	ll n,wMax;
	cin>>n>>wMax;
	
	
	item arr[n];
	
	for(ll i=0; i<n; i++)
	cin >> arr[i].v >> arr[i].w;
 
	sort(arr, arr+n, compare);         // sort the items based on weights, so that we can multiply (big value) with (big prime)                   
	
	
	ll ***dp = new ll**[2];            // dynamic 3d array (dp[2][n+1][wMax+1])
	
	for(ll i=0; i<2; i++)
	{   dp[i] = new ll*[n+1];
		
		for(ll j=0; j<n+1; j++)
		{   dp[i][j] = new ll[wMax+1];
			
			for(ll k=0; k<wMax+1; k++)
			dp[i][j][k] = 0;           // array initialization  
		} 
	}
	
	
	ll prime[11] = {1,2,3,5,7,11,13,17,19,23,29};

    // calculating for p=0 (base index initialization of DP)
 
	for(ll i=1; i<n+1; i++)           // considering simple knapsack (i.e. not using any prime)    
	{
		for(ll j=1; j<wMax+1; j++)
        {
         	ll vMax1=LONG_MIN, vMax2=LONG_MIN;
			
            vMax1 = dp[0][i-1][j];     // excluding weight at index (i-1) 				

        	if(j-arr[i-1].w >= 0)      // including weight at index (i-1) 
         	vMax2 = dp[0][i-1][j-arr[i-1].w] + arr[i-1].v;                              
            	              
        	
        	dp[0][i][j] = max(vMax1, vMax2);   
    	} 
	} 
 
    // calculating for p=1 to p=10 
    
    ll flag = 1;

	for(ll p=1; p<=10; p++)           // this loop will consider all the cases where, 10 primes will be used (in sorted order) to the values (in sorted order) 
	{    
		for(ll i=1; i<n+1; i++)       // for iterating (dp[p][][]) we need data of (dp[p-1][][]) only, so use flag (toggler)
		{
			for(ll j=1; j<wMax+1; j++)
			{
         	    int vMax1=LONG_MIN, vMax2=LONG_MIN;
			            // dp[p][i-1][j]      
                vMax1 = dp[flag][i-1][j];                                             // excluding weight at index (i-1) 				
 
				if(j-arr[i-1].w >= 0)                                                // including weight at index (i-1)  
				{	    // dp[p][i-1][j-arr[i-1].w] + arr[i-1].v                      
				    ll x1 = dp[flag][i-1][j-arr[i-1].w] + arr[i-1].v;                // without using prime 
					
					    // dp[p-1][i-1][j-arr[i-1].w] + prime[p]*arr[i-1].v   
					ll x2 = dp[flag^1][i-1][j-arr[i-1].w] + (prime[p])*(arr[i-1].v); // using prime[p] for (i,j) 
					
				    vMax2 = max(x1, x2);   
				} 
				    
				dp[flag][i][j] = max(vMax1, vMax2);  
			}
		}
		
		flag = flag^1;  
	} 
	
	cout << dp[flag^1][n][wMax] << endl;
}


/*

7 37
33 5
5 19
14 30
14 4
16 15
25 31
15 25

*/














