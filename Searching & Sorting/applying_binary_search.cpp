#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


bool checkValidityOfD(ll nCows, ll stall[], ll n, ll D)
{
	ll count = 1;
	ll currStallPosition = stall[0];

	for(int i=1; i<n; i++)
	{
		ll nextStallPosition = stall[i];
		
		if(nextStallPosition - currStallPosition >= D)
		{	currStallPosition = nextStallPosition;
			count++;   }


		if(count == nCows)
		return 1;
	}
	
	return 0;
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		ll n, nCows;
		cin >> n >> nCows;

		ll stall[n];
		for(ll i=0; i<n; i++)
		cin >> stall[i];
		
		
		sort(stall, stall+n); 
		
		ll startD = 0;
		ll endD = stall[n-1] - stall[0]; 
		ll minD = -1;
		 
		while(startD <= endD)
		{
			ll midD = startD + (endD-startD)/2;       // their range is high so write this instead of "(startD+endD)/2"

			if(checkValidityOfD(nCows, stall, n, midD))
			{	minD = midD;
				startD = midD+1;   }                  // increase startD bcz arrangement is possible for midD        
			else
			endD = midD-1;                            // decrease endD bcz arrangement is not possible for midD  
		}
		
		cout << minD <<endl;
	} 
}




 







