#include <bits/stdc++.h>
using namespace std;

int n,x;
                 
int findTouchesCount(int i, int maskNo, vector<string> &str, int **arr)                          
{
    if((maskNo&(maskNo-1)) == 0)    // maskNo has only 1 Set bit
	return 0;
    else if(maskNo==0 || i==-1)
	return 10000; 
	else if(arr[i][maskNo] != INT_MAX)
	return arr[i][maskNo];
	
	int touchesCount = 0; 
	int maskNo1=0, maskNo2=0;
 
	for(int k=0; k<n; k++)          // 'k'th bit in Bit String (maskNo) will corresponding to 'k'th String (in vectorArray) 
	{
		if(maskNo & (1<<k)) 
		{   touchesCount++;
		
		    if(str[k][i] == '0')
		    maskNo1 = maskNo1 | (1<<k);
		    else if(str[k][i] == '1')
			maskNo2 = maskNo2 | (1<<k);
		} 
	}                                                     // include touchesCount corresponding to current index (i) 
	int r1 = touchesCount + findTouchesCount(i-1, maskNo1, str, arr) + findTouchesCount(i-1, maskNo2, str, arr);
	int r2 = findTouchesCount(i-1, maskNo, str, arr);     // exclude touchesCount corresponding to current index (i)  
	 
	arr[i][maskNo] = min(r1, r2);
	return arr[i][maskNo];
}


int minNoOfTouchesToDistinguishAllStrings(vector<string> str)                                                            
{
	int **arr = new int*[x];         // storing the repeated function calls corresponding to (indexNo,maskNo)
	
	for(int i=0; i<x; i++)     
	{	arr[i] = new int [1<<n];
		
		for(int j=0; j<(1<<n); j++)
		arr[i][j] = INT_MAX;   }
	
	return findTouchesCount(x-1, (1<<n)-1, str, arr);
}


int main()
{ 
	int t;
	cin>>t;

	while(t--)
	{  
       cin>>n;                       // no of strings
       
       vector<string> str(n); 
       for(int i=0; i<n; i++)
       cin>>str[i];
       
       x = str[0].size();            // size of each string

       cout<<minNoOfTouchesToDistinguishAllStrings(str)<<endl;
	} 
}






 
