#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
 

int main()
{ 
	ll t;
	cin>>t;

	while(t--)        // gcd(a,b) = gcd(b,a%b)  [where r = a%b]
	{
       ll b;
       cin>>b; 
       
       string a;
       cin>>a;
        
     
       if(b == 0)
       {   cout<<a<<endl;
           continue;   }
       

       ll r = 0;
       for(int i=0; i<a.size(); i++)
       { 
       	   ll d = a[i]-'0';
			   
		   r = ((r*10)%b + d%b)%b;    
	   }

       cout<<__gcd(b,r)<<endl;
	} 
}









