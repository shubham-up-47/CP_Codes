#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int gcdUsingEuclidAlgo(int a, int b)
{
	if(a < b)
	return gcdUsingEuclidAlgo(b, a);
	else if(b==0)
	return a;
	
	int r = gcdUsingEuclidAlgo(b, a%b);
	
	return r; 
}


int main()
{

	int t;
	cin>>t;

	while(t--)
	{
        int a, b;
        cin>>a>>b;
        
        cout<<gcdUsingEuclidAlgo(a, b)<<endl; 
	} 
}








