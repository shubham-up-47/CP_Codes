#include <bits/stdc++.h>
using namespace std;
 

int main()
{

	int n, cost=0;
	cin>>n;

    string s,t;
    cin>>s>>t;
  	
    for(int i=0; i<n; i++)
    {
    	if(i+1<n && s[i]!=t[i] && s[i+1]!=t[i+1] && s[i]!=s[i+1])
    	{ 
		    char temp = s[i];
			s[i] = s[i+1];
			s[i+1] = temp;   
 
			i++;
			cost++;
		}
    	else if(s[i]!=t[i])
    	{
    	 	s[i] = (s[i]=='0') ? '1' : '0';   
			
			cost++;
		}
    }
    	
	cout << cost << endl;  
}









