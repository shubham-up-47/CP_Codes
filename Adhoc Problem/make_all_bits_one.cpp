#include<bits/stdc++.h>
using namespace std;


int main()
{ 
    long n, x, y;
    cin>>n>>x>>y;
    
    string s;
    cin>>s;
    
     
    long c = (s[0]=='0') ? 1 : 0;             // counting no of groupOfZeros in input string               
    for(int i=1; i<n; i++)
    { 
        if(s[i-1]=='1' && s[i]=='0')
        c++; 
    }
    
    
    if(c==0)
    cout<<0<<endl;
    else
    cout<<((c-1)*(min(x,y)) + y)<<endl; 
}


/*

if [x == min(x,y)] then clubAllZeroGroupsAtLastGroup by applyingReverseOperationFromFirstGroup 
if [y == min(x,y)] then toggleAllZeroGroups each individually 

*/








