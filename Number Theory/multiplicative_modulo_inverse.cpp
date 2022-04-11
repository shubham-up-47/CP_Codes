#include <bits/stdc++.h>
using namespace std;


class Triplet
{ 	  public:
   int x;
   int y;
   int gcd; 
};

   // solving equation LinearDiaphantineEquation [ax + by = gcd(a,b)] using ExtendedEuclidAlgorithm                 
 
Triplet extendedEuclidAlgorithm(int a, int b)
{
	if(b==0)
	{  Triplet r;
	   r.x = 1;
	   r.y = 0;
	   r.gcd = a;	
		
	   return r;   }
	
	Triplet t = extendedEuclidAlgorithm(b, a%b);
	
	Triplet r;
	r.x = t.y;
	r.y = t.x - (a/b)*t.y;
	r.gcd = t.gcd;	 
	return r; 
}

   //  if MultiplicativeModuloInverse of a is b, then [(a.b)%m = 1]

int multiplicativeModuloInverse(int a, int m)
{
	Triplet r = extendedEuclidAlgorithm(a, m);
	
	int b = r.x;
	return b; 
}


int main()
{ 
	int t;
	cin>>t;

	while(t--)
	{
        int a, m;
        cin>>a>>m;
         
        cout<<multiplicativeModuloInverse(a, m)<<endl;
	} 
}








