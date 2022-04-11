#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
 

             // Memorization (recursive)
ll countPermutationsM(ll n, ll maskNo, ll *arr)                         
{
	if(maskNo == (1<<(n+1))-1)
	return 1;  
	else if(arr[maskNo] != -1)
	return arr[maskNo];
	
	ll count = 0;
	for(ll j=1; j<=n; j++)          // considering binary of 'maskNo' as current 'n' bit 'Bit String'                
	{
		if(!(maskNo & (1<<j)))      // if 'j'th bit is 0, then make 'j'th bit 1                        
		{   
		    int z = 0;
            for(ll i=1; i<=n; i++)  // if ((i&j) == j) where (i = already filled number whose Bit is 1) and (j = current number) then return 0 bcz this will give wrong permutation               
            {   
			    if((maskNo & (1<<i)) && ((i&j) == j))
                {  z = 1;
				   break;  }
		    }
             
            if(z == 0) 
            count += countPermutationsM(n, maskNo|(1<<j), arr);            
		} 
	}
	
	arr[maskNo] = count;
	return arr[maskNo]; 
}

           // Dynamic Programming (iterative)
ll countPermutationsDP(ll n)                                 
{ 
    ll *dp = new ll[1<<(n+1)];
    for(ll i=0; i<(1<<(n+1)); i++)
    dp[i] = 0;
    
	dp[1] = 1;
    
	for(ll maskNo=1; maskNo<(1<<(n+1)); maskNo++)     // we will track that bits from (index=1) to (index=n) are 1 (no. already included) or 0 (no. not included) in the Bit String                    
    {
		for(ll j=1; j<=n; j++)  
		{
            if ((maskNo & (1>>j)) == 0)
            {          
                int z = 0;
                for(int i=1; i<=n; i++)
				{
                    if((maskNo & (1<<i)) && ((i&j) == j))
					{   z = 1;
                        break;   }
                }
                
                if(z == 0)
                dp[maskNo|(1<<j)] += dp[maskNo]; 
            }
        }
	}
	
	return dp[(1<<(n+1))-1];
}
 

int main()
{ 
    ll n;
    cin>>n;
          
    ll *arr = new ll[1<<(n+1)];
    for(ll i=0; i<(1<<(n+1)); i++)
    arr[i] = -1;
    
    cout << countPermutationsM(n, 1, arr) << endl;  

    cout << countPermutationsDP(n) << endl;  
}
 
  









