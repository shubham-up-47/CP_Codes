#include <bits/stdc++.h>
using namespace std;


/*

L = indexNoOfLeftmostChar in'str[L,R]'
R = indexNoOfRightmostChar in'str[L,R]'
str[L,R] = substringStartingFrom'L'
str[0,R-L] = PrefixOf'str'   
 

Points before Calculating Z function:
*(str[i]!=str[0])  =>  Z[i]=0
*(str[L,R]==str[0,R-L])  =>  Z[i]=R-L


Z[i] = lengthOfLongestSubstringStartingFrom'i' whichIsAlsoPrefixOf'str'     

Z[0] = isNotDefinedForAnyString bczString'str[0]'IsObvioslyPrefixOf'str'

 
Example:
pattern="aab" & text="baabaa"
 str = a-a-b-$-b-a-a-b-a-a
Z[] = {X,1,0,0,0,3,1,0,2,1}


str = "-p-a-t-t-e-r-n-$-t-e-x-t-" 
                        [L, R]
                        [i]

*/


int* buildZfunction_forInputString(string str)
{ 
	int n = str.size();
	int *Z = new int[n]();
	
	
	int L=0, R=0;                                          // str[L,R] = longestSubstringStartingFrom'L' whichIsAlsoPrefixOf'str[0,n-1]'
	for(int i=1; i<n; i++)                                 // calculating'Z[i]'In'i'thIteration   
	{
		if(R < i)                                          // substring'str[i,n-1]'IsUnvisitedTillNow soPrevious'str[L,R]'IsUseless
		{   
		    L = i;
			R = i;          
		
		    while(R<n && str[R-i]==str[R]) 
			R++; 
			
			Z[i] = R-i;
			R--;  
		}  
		else if(i <= R)                                    // substring'str[i,n-1]'IsPartiallyVisitedAlready soPrevious'str[L,R]'IsUseful    
		{   
		    int k = i-L;                                   // (str[0,i-L] = str[L,i]) bczOfPrevious'str[L,R]'And(L<i<=R i.e. i lies in [L,R])
		
		    if(Z[k] < R-i)	                               // substringOf'Z[i]'LiesInside'str[i,R]'So(Z[i] = str[0,Z[k]] = str[i,i+Z[k]])                                       
		    Z[i] = Z[k];
		    else if(Z[k] >= R-i)                           // substringOf'Z[i]'LiesOutside'str[i,R]'AlsoSo(Z[i] = newlyCalculated'str[L,R])     
		    {   
			    L = i;
			    R = R;
		    
			    while(R<n && str[R-i]==str[R])
			    R++;
			    
			    Z[i] = R-i;
			    R--;   
			}   
		}   
	} 
	
	return Z;
}


bool patternMatching_Z_Algo(string text, string pattern)   // In Z_Algo & KMP_Algo, both has same Time-Space Complexity, but Z_Algo is simpler 
{
    int n=text.size(), m=pattern.size(); 
    string str = pattern + "$" + text;
    
    int *Z = buildZfunction_forInputString(str);
    vector<int> v;
    
	for(int i=0; i<n+m+1; i++)
	{
		if(Z[i]==m)                                        // Z[i] = lengthOfLongestSubstringStartingFrom'i' whichIsAlsoPrefixOf'str'               
		v.push_back(i-m-1);   
	} 
	
	for(auto x: v)                                            
	cout<<"Pattern found in the Text string, at index: "<<x<<endl;
    if(v.size() == 0)
	cout<<"Pattern not found in the Text string"<<endl;
}


int main()
{
    string text = "abcdsafbcdfasbcda";
    string pattern = "bcd";
    
    patternMatching_Z_Algo(text, pattern);
}









