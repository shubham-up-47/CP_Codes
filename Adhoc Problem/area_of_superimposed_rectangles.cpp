#include <bits/stdc++.h>
using namespace std;
 

int main()
{ 
	vector<int> vtr;                            // vector storing extreme right x coordinate of each rectangle given    
    unordered_map<int,int> h;                   // (key = extreme right x coordinate of rectangle) (value = height of rectangle)                                         
  
	int xMax=0, currH=0, t;
	cin>>t;
	
	while(t--)
	{
       int L,H;                                 // (L = length) & (H = height) of rectangle
       cin>>L>>H;
        
       int xCurr = L/2;
       xMax = max(xMax, xCurr); 
         
       if(h.count(xCurr)>0 && H>h[xCurr])                                
       h[xCurr] = H;   
       else if(h.count(xCurr)==0)                                                      
       {  h[xCurr] = H;
          vtr.push_back(xCurr);  }                                                                                                                                          
	}                                                                         
          
    
    long long Area=0;                                     
    sort(vtr.begin(), vtr.end(), greater<int>());        // sorting extreme right x coordinate in decreasing order                            
    
    for(int i=xMax,j=0;  i>=1;  i--)                     // travelling from extremeRight"x"Coordinate to x=1 & keep adding unit area
    {
	   if(j<vtr.size() && i==vtr[j])          
	   {  currH = max(currH, h[vtr[j]]);  
	      j++;  } 
	  
	   Area += currH;                                    // adding unit area in (x = i-1) to (x = i)                                                          
    } 
    
     
	Area *= 2;                                           // totalArea = 2 X areaOfRightHalf                     
	cout<<Area<<endl;                                    // area of resultant rectangles                  
}

 






 

