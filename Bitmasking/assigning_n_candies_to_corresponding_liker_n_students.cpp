#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

                 
ll countWays(ll **s, ll n, ll i, ll maskNo, ll *arr)                         
{
	if(i==n && maskNo==(1<<n)-1)
	return 1;
    else if(i==n && maskNo!=(1<<n)-1)
    return 0;
	else if(arr[maskNo] != -1)
	return arr[maskNo];
	
	ll count = 0;
	for(ll j=0; j<n; j++)          // considering binary of 'maskNo' as current 'n' bit 'Bit String' (in which 0 = unassignedCandy & 1 = assignedCandy)               
	{
		if(!(maskNo & (1<<j)) && s[i][j]==1)     // if 'j'th bit is 0, then make 'j'th bit 1 (i.e. assign 'j'th Candy to 'i'th Person if he likes it)                             
		count += countWays(s, n, i+1, maskNo|(1<<j), arr);      
	}
	
	arr[maskNo] = count;
	return arr[maskNo]; 
}
 

int main()
{
  ll t;
  cin>>t;

  while(t--)
  {
    ll n;     // n = no of students = no of candies
    cin>>n;
        
    ll **s = new ll*[n];    // s[i][j] = (1/0) means student 'i' (likes/dislikes) candy 'j' 
    for(ll i=0; i<n; i++)
    {   
        s[i] = new ll[n];
        for(ll j=0; j<n; j++)
        cin>>s[i][j];   
    }
      
     
    ll *arr = new ll[1<<n];    // arr[i] = total ways of distributing corresponding to Bit String 'i'                                
    for(ll i=0; i<(1<<n); i++)
    arr[i] = -1;
    
    cout<<countWays(s,n,0,0,arr)<<endl;  // counting total ways of distributing (n candies) to (n students)
  }
}
 
  






