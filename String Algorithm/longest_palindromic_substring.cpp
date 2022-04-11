#include <bits/stdc++.h>
using namespace std;


/*                                          
                                             
#Finding LengthOfThe LongestPalindromicSubstring#


Method1: (BasicApproach)
GetAllSubstrings => CheckPalindromeOrNot
TimeComplexity = O(n*n*n)


Method2:
RunLoopFrom i=0 to i=n-1
ForEach'i' findSizeOfLongestPalindromeOnIt
TimeComplexity = O(n*n)
                                           
*/                                           


int longestPalindromicSubstring(string str)
{
	int n=str.size(), nLPS=0;
	
	for(int i=0; i<n; i++)
	{
		for(int L=i,R=i;  L>=0 && R<n && str[L]==str[R];  L--,R++)          // toCheckForOddPalindrome => moveLeftAndRightOf'i' 
		nLPS = max(nLPS, R-L+1);    
		
		for(int L=i,R=i+1;  L>=0 && R<n && str[L]==str[R];  L--,R++)        // toCheckForEvenPalindrome => moveLeftAndRightOf'i'And'i+1'
		nLPS = max(nLPS, R-L+1); 
	}
	 
	return nLPS; 
} 


int main()
{
    string str = "ababbabcba";
  
    cout<<"Length of the Longest Palindromic Substring: "<< longestPalindromicSubstring(str) <<endl;
}

 









