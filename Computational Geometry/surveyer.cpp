#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;


ll areaOfClosedPaths(string direction, int *distance, int n)     // finding area of closed perpendicular paths by E=East/W=West/N=North/S=South moves
{ 
    ll currArea=0; 
    
    ll prevX=0, currX=0, currH=0;
    
    for(int i=0; i<n; i++)                                       // starting from (0,0)        
	{
        prevX = currX;
    
	    if(direction[i]=='N') 
        currH += distance[i];
        else if(direction[i]=='S') 
        currH -= distance[i];
        else if(direction[i]=='E')
        currX += distance[i];
        else if(direction[i]=='W')  
        currX -= distance[i];
        
        currArea += (currX-prevX)*currH;
    }
    
    return abs(currArea);
}


int main()
{
    string s;
    cin>>s;
    
    int n=s.size();
    int arr[n];
    for(int i=0; i<n; i++) 
	cin>>arr[i];
    
    ll totalArea = areaOfClosedPaths(s, arr, n);
    cout<< totalArea <<endl;
}


















