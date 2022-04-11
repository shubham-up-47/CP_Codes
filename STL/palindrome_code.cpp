#include <bits/stdc++.h>
using namespace std;

 
int main()
{
    string s;
	cin>>s;
	
	
	int n = s.size();
	map<char,vector<int>> indexes;
	for(int i=0; i<n; i++)
	indexes[s[i]].push_back(i);
	
	
	int z=0;                 	
	for(int i=97; i<123; i++)
	{  if(indexes[i].size()%2 != 0)
	   z++;  }
	   
	                                   
	if(z >= 2)
	cout<<-1<<endl;
	else
	{ 
	   	int plndrm[n], startI=0, endI=n-1;
	   	 
		
		for(int i=97; i<123; i++)
		{
			for(int j=0; j<indexes[i].size(); j+=2)
			{
				if(j == indexes[i].size()-1)
				{  plndrm[n/2] = indexes[i][j];
				   continue;  } 
				
				
				plndrm[startI] = indexes[i][j];
				plndrm[endI] = indexes[i][j+1];
				
				startI++, endI--; 
			}
			 
		}
		
		
		for(int i=0; i<n; i++)
		cout << plndrm[i]+1 <<" "; 
	} 
	
}















