#include <bits/stdc++.h>
using namespace std;


void patternMatching_basicApproach(string text, string pattern)
{
	int n=text.size(), m=pattern.size();


	for(int i=0; i<n-m; i++) 
	{
		int j; 
		
		for(j=0; j<m; j++)
		{	
		    if(text[i+j] != pattern[j])
			break;	 
		}

		if(j==m)  
		cout<<"Pattern found in the Text string, at index: "<<i<<endl;
	}
}


int main()
{
	string text = "AABAACAADAABAAABAA";
	string pattern = "AABA";
	
	patternMatching_basicApproach(text, pattern); 
}







