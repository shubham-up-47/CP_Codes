#include <bits/stdc++.h>
using namespace std;


/*
 
LPS = LongestPrefix whichIsAlsoSuffix (in pattern) 

sizeOfLPS[j] = sizeOfLPS forSubstringOfPattern in [0,j]
 
*/


int* sizeOfLPS_forEachSubstring(string pattern)     // i = indexNoOfLastCharOfLongestPrefix (whichIsAlsoSuffix) forSubstringOfPattern in [0,j]                    
{
	int m = pattern.size();
	int *sizeOfLPS = new int[m];
	
	sizeOfLPS[0] = 0;                            
	
	for(int i=0,j=1;  j<m;  )                       // travelling from j=1 to j=m-1 in pattern string 
	{
		if(pattern[i]==pattern[j])
		{   
		    sizeOfLPS[j] = i+1; 
		    i++,j++;   
		}
		else if(pattern[i]!=pattern[j] && i==0)
		{   
		    sizeOfLPS[j] = 0;
			j++;   
		}
		else if(pattern[i]!=pattern[j] && i!=0)
		{ 
		    i = sizeOfLPS[i-1];  
	    }
	}
	           
	return sizeOfLPS;
}


void patternMatching_KMP_Algo1(string text, string pattern)     // thisAlgorithmTellsOnlyTheFirstIndex wherePatternIsPresentInTextString
{
    int n=text.size(), m=pattern.size();  
    int *sizeOfLPS = sizeOfLPS_forEachSubstring(pattern);
     
    int i=0, j=0;
	while(i<m && j<n)                                            // travelling from j=0 to j=n-1 in text string 
	{
	    if(pattern[i]==text[j])
		i++,j++;    
		else if(pattern[i]!=text[j] && i==0)
		j++;
		else if(pattern[i]!=text[j] && i!=0)
		i = sizeOfLPS[i-1];    
	}
	 
	if(i==m)                                                    
	cout<<"Pattern found in the Text string"<<endl;
    else
	cout<<"Pattern not found in the Text string"<<endl;
}


void patternMatching_KMP_Algo2(string text, string pattern)       // thisAlgorithmTellsAllTheIndexes wherePatternIsPresentInTextString
{
    int n=text.size(), m=pattern.size();  
    int *sizeOfLPS = sizeOfLPS_forEachSubstring(pattern);
    vector<int> v;
    
    int i=0, j=0;  
	while(j<n)                                                     // travelling from j=0 to j=n-1 in text string 
	{
	    if(i==m)                                                     
	    {  v.push_back(j-m);
		   i = sizeOfLPS[i-1];  }
		else if(pattern[i]==text[j])
		i++,j++;    
		else if(pattern[i]!=text[j] && i==0)
		j++;
		else if(pattern[i]!=text[j] && i!=0)
		i = sizeOfLPS[i-1];    
	}
	 
	for(auto x: v)                                            
	cout<<"Pattern found in the Text string, at index: "<<x<<endl;
    if(v.size() == 0)
	cout<<"Pattern not found in the Text string"<<endl;
}


int main()
{
    string text = "abcxabcdabcydabcdabcynnn";
    string pattern = "abcdabcy";
     
    cout<<"\nKMP Algo1:"<<endl;
    patternMatching_KMP_Algo1(text,pattern);
    cout<<"\nKMP Algo2:"<<endl;
    patternMatching_KMP_Algo2(text,pattern);
    cout<<"\n";
}









