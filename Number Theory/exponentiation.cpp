#include <bits/stdc++.h>
using namespace std;


int pow1(int x, int n)
{
	if(n == 0)
	return 1;
	
	int r = pow(x, n-1)*x;
	
	return r;
}


int pow2(float x, int n)
{
	if(n == 0)
	return 1;
	
	float t = pow(x, n/2);
	
	if(n%2 == 0)
	return (t*t);
	else
	return (t*t*x); 
}


float pow3(float x, int n)
{
	if(n == 0)
	return 1;
	
	float t = pow(x, n/2);
	
	if(n%2 == 0)
	return (t*t);
	else
	{	if(n > 0)
		return (t*t*x);
		else
		return ((t*t)/x);	}
}

 
int main()
{
	cout<< pow1(2,3) <<endl; 
	cout<< pow2(2,3) <<endl; 
	cout<< pow3(2,-3) <<endl; 
}
 

