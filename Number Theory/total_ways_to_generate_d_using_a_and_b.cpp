#include<bits/stdc++.h> 
using namespace std;


typedef long long ll;


class Triplet
{      public:
	ll x;
	ll y;
	ll gcd;
};


Triplet extendedEuclidAlgorithm(ll a, ll b)
{ 
	if(b==0)
	{	Triplet r;
		r.x = 1;
		r.y = 0;
		r.gcd = a;
		return r;	}
		
		
	Triplet t = extendedEuclidAlgorithm(b, a%b);
 

	Triplet r;
	r.gcd = t.gcd;
	r.x = t.y;
	r.y = t.x - (a/b)*t.y;
	return r;	
}

 
ll pmmi(ll a, ll m)         // positive Multiplicative Modulo Inverse i.e. positive (1/a)%m
{
    ll x = extendedEuclidAlgorithm(a, m).x;
    
    ll r = (x%m + m)%m;     // making Multiplicative Modulo Inverse positive
    return r;
}


int main()
{ 
	int t;
	cin>>t;
	
	while(t--)
	{
		ll a, b, d;               // finding count of all (x,y) in (ax + by = d)                    
		cin>>a>>b>>d;
		
        if(d == 0)
		{	cout<<1<<endl;
			continue;	}
		
		
		ll gcd = __gcd(a,b);         
 
		if(d%gcd != 0)            // Non Diophantine Equation so no solution                                  
		{	cout<<0<<endl;
			continue;	}
		else if(d%gcd == 0)       // Diophantine Equation (all are divisible by gcd so simplify the equation)
		{	a /= gcd;
		    b /= gcd;
		    d /= gcd;	}
  
  
		ll y1 = ((d%a) * pmmi(b,a))%a;      // min value of y
		ll n = (d/b - y1)/a;                // no of values of y other than y1 

		if((d/b - y1) < 0)
		cout << 0 <<endl;
		else
	 	cout << n+1 <<endl; 
	} 
}







