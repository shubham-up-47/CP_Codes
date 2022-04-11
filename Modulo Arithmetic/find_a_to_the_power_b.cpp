#include <bits/stdc++.h>
using namespace std;


long m = pow(10,9) + 7;


int main()
{ 
	int t, n, i;
	cin>>t;

	while(t--)
	{
        long a, b;
        cin>>a>>b;
 
        long p = 1;
         
        for(int i=0; i<b; i++)
        {  p = p%m;
           a = a%m;
            
           p = (p*a)%m;   } 
        
        cout<<p<<endl;
	} 
}







