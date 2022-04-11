#include <bits/stdc++.h>
using namespace std;


int moduloOfPower_recursive(int x, int n, int m)
{
	if(x==0 || m==1)
	return 0;
	else if(n==0)
	return 1;
	
	
	long t = moduloOfPower_recursive(x, n/2, m);
	
	
	int r;
	
	if(n%2 == 0)     
    r = (t*t)%m;
    else 
	r = ((t*t)%m * x%m)%m;         // (long)*(int) = (long) soNoMemoryOverflow [bcz MemoryOverflow may happen when (int)*(int)]
	
	return (r+m)%m;                // return positive (int) value of r [r can be negative in (x<0) case]                                            
}

 
int moduloOfPower_iterative(int x, int n, int m)
{
	if(x==0 || m==1)
	return 0;
	else if(n==0)
	return 1;
	
	
	long t=x%m, r=1;
	
	while(n != 0)
	{ 
		if(n&1 == 1) 
		r = (r*t)%m; 
		
		n = n>>1;           // or n = n/2 or right shift
		t = (t*t)%m;        // t = a^i
	}
	 
	return (r+m)%m;         // return positive (int) value of r [r can be negative in (x<0) case]                                            
} 
 
 
int main()
{
	cout<< moduloOfPower_recursive(2,10,5) <<endl;  
	cout<< moduloOfPower_iterative(2,10,5) <<endl;  
}
 
 
 
 
 
 
 
 
 
 
 

