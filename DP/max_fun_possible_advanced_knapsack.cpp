#include <bits/stdc++.h>
using namespace std;


// arr[i][j].f = max possible Fun when (i = no of parties) & (j = maxCost that we can bear)
// arr[i][j].c = cost corresponding to max Fun when (i = no of parties) & (j = maxCost that we can bear) 
       
typedef long long ll;

class dp
{     public:
    ll f;
    ll c; 
};


int main()
{ 
	ll n;          // no of parties
    cin>>n;
    
	ll C[n];       // Cost of ticket of each party
	for(ll i=0; i<n; i++)
	cin>>C[i];                  
	
    ll F[n];       // Fun in each party
	for(ll i=0; i<n; i++)
	cin>>F[i];   
	
    ll cMax;
	cin>>cMax;  
	
	
    dp arr[n+1][cMax+1]; 
	 
	arr[0][0] = {0,0};
 
	for(int i=1; i<n+1; i++)
	arr[i][0] = {0,0}; 
	for(int j=1; j<cMax+1; j++)
	arr[0][j] = {0,0};
    
	for(int i=1; i<n+1; i++)                                                            
	{   for(int j=1; j<cMax+1; j++)             
        {	
         	ll fMax1=INT_MIN, cMax1=INT_MIN, fMax2=INT_MIN, cMax2=INT_MIN;
	
            fMax1 = arr[i-1][j].f;                                     // excluding party at index (i-1)            
	        cMax1 = arr[i-1][j].c;      
        
        	if(j-C[i-1] >= 0)                                          // including party at index (i-1) 
            {   fMax2 = F[i-1] + arr[i-1][j-C[i-1]].f;  
                cMax2 = C[i-1] + arr[i-1][j-C[i-1]].c;   }
 
 
            if((fMax1 > fMax2) || (fMax1==fMax2 && cMax1 < cMax2))
	        arr[i][j] = {fMax1, cMax1};  
            else
            arr[i][j] = {fMax2, cMax2};
		}
    }
               
    cout<<arr[n][cMax].c<<" "<<arr[n][cMax].f<<endl;  
}




 
    
    
    






