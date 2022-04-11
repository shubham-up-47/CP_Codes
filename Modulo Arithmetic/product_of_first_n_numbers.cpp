#include <bits/stdc++.h>
using namespace std;


long m = pow(10,9) + 7;


int main()
{ 
	int t, n, i;
	cin>>t;

	while(t--)
	{
        long n, p=1;
        cin>>n;
 
        for(int i=1; i<=n; i++)
        {  p = p%m;
           i = i%m;
            
           p = (p*i)%m;   } 
        
        int ans = (int)p; 
        cout<<ans<<endl;
	} 
}













