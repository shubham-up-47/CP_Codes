#include <bits/stdc++.h>
using namespace std;
 
 
// (sumOfSubstringEndingAt"arr[i]") = (sumOfSubstringEndingAt"arr[i-1]")*10 + (sizeofSunstringIncluding"arr[i]")*(arr[i])              


int main()
{
    string s;                                        // input numerical string             
    cin>>s;              
    long n = s.size();
    
    
	long sum=0, dp[n];                               // Dynamic Programming          
	
    dp[0] = s[0]-'0';
    
    for(int i=1; i<n; i++)
    dp[i] = dp[i-1]*10 + (i+1)*(s[i]-'0'); 

    for(int i=0; i<n; i++)
    sum += dp[i]; 
    
    cout << sum << endl;
}




                                            
                                                                                                           



 

