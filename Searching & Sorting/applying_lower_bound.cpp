#include <bits/stdc++.h>
using namespace std;

 
int main()
{ 
	int n,p;
	cin>>n>>p;
	
	vector<pair<int,int>> I;
	
	for(int i=0; i<n; i++)
	{
		int start,end;
		cin>>start>>end;
		
		  // in this all intervals are distinct i.e. no overlapping                                                  
		I.push_back({start,end});
    }
	
	sort(I.begin(), I.end());      // sorting based on first element of the pairs
	 
	int prr[p];
	for(int i=0; i<p; i++)
	{
		cin>>prr[i];
		
		  // lower_bound() returns iterator pointing first element >= x, so subtract by I.begin() to index no                  
		int index = lower_bound(I.begin(), I.end(), make_pair(prr[i],0)) - I.begin();                                            
		
		if(index == 0)                            // person came before all intervals
		cout << I[index].first - prr[i];
		else if(index == I.size())                // person came after all intervals  
		cout << -1;
		else if(I[index-1].second > prr[i])       // person came durig a interval                                    
		cout << 0;
		else                                      // person came between two intervals
		cout << I[index].first - prr[i]; 
	
	    cout << endl;
	} 
}




 
 

