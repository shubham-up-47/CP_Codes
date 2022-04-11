#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

ll x = 1000000007;


void matrixMultiply(ll A[2][2], ll B[2][2])
{ 
	int p = (A[0][0]*B[0][0] + A[0][1]*B[1][0])%(x-1);
	int q = (A[0][0]*B[0][1] + A[0][1]*B[1][1])%(x-1);
	int r = (A[1][0]*B[0][0] + A[1][1]*B[1][0])%(x-1);
	int s = (A[1][0]*B[0][1] + A[1][1]*B[1][1])%(x-1);

	A[0][0] = p;
	A[0][1] = q;
	A[1][0] = r;
	A[1][1] = s; 
}


void matrixExponent(ll M[2][2], ll n)        // nth power of matrix M 
{
	if(n==1)
	return;
  
	matrixExponent(M, n/2);                    // (n/2)th power of matrix M 
	
	if(n%2 == 0)                               // n is even
	{  matrixMultiply(M, M);  }                // (t*t)
	else                                       // n is odd 
	{  matrixMultiply(M, M);                   // (t*t*x)
	   ll X[2][2] = {{1,1},{1,0}};
	   matrixMultiply(M, X);  }
} 


ll fibUsingME(ll n)                // nth fibonacci number using ME (Matrix Exponentiation)
{
	if(n==0 || n==1)
	return n;
	
	ll M[2][2] = {{1,1},{1,0}};     // matrix M  
	
	matrixExponent(M, n-1);          // finding M^(n-1)
	
	return (M[0][0]*1 + M[0][1]*0);  // finding F(n) by Matrix Multiplication                             
} 


ll findPowerModulo(ll x, ll n, ll m)
{
	if(x==0 || m==1)
	return 0;
	else if(n==0)
	return 1;
	 
	ll r, t = findPowerModulo(x, n/2, m);
	 
	if(n%2 == 0)     
    r = (t*t)%m;
    else 
	r = ((t*t)%m * x%m)%m;         
	
	return (r+m)%m;                                            
} 


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ll f0, f1, n;
        cin>>f0>>f1>>n;
        
        ll a = f0 + 1;
        ll b = f1 + 1;
         
        ll power1 = fibUsingME(n-1);      // taking %(x-1) in fib() calculations
        ll power2 = fibUsingME(n);
        
        ll term1 = findPowerModulo(a, power1, x);
        ll term2 = findPowerModulo(b, power2, x);
        
        ll r = ((term1*term2)%x - 1 + x)%x;
		cout<<r<<endl;  
    } 
}






