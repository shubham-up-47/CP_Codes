#include <bits/stdc++.h>
using namespace std;


/*                                          
                                             
#Finding CountOfThe PalindromicSubstring#


Method1: (BasicApproach)
GetAllSubstrings => CheckPalindromeOrNotAndMaintainCount
TimeComplexity = O(n*n*n)


Method2:
RunLoopFrom i=0 to i=n-1
ForEach'i' MoveTillLongestPalindromicSubstringOnItAndCountEach
TimeComplexity = O(n*n)
toConsiderOddPalindromes => moveLeftAndRightOf'i'   
toConsiderEvenPalindromes => moveLeftAndRightOf'i'And'i+1'
                                         
*/                                           


int countAllPalindromicSubstring(string str)
{
	int n=str.size(), nPS=0;
	
	for(int i=0; i<n; i++)
	{
		for(int L=i,R=i;  L>=0 && R<n && str[L]==str[R];  L--,R++)          // odd palindromes  
		nPS++; 
	   
		for(int L=i,R=i+1;  L>=0 && R<n && str[L]==str[R];  L--,R++)        // even palindromes
	    nPS++;  
	}
	 
	return nPS; 
} 


int main()
{
	int t;
	cin>>t;

	while(t--)
	{
        string str;
        cin>>str;
  
        cout<< countAllPalindromicSubstring(str) <<endl;
    }
}

 
 
 
 
 
 



