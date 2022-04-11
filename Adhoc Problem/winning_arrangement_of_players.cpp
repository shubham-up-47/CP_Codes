#include <bits/stdc++.h>
using namespace std;


int swapCount = 0; 
 

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
	
	swapCount++;
}


void winningStrategy(int arr[], int n)
{  
	for(int i=1; i<n+1; i++)
	{
		if( abs(arr[i]-i) > 2)               // winning arrangement is not possible                            
		{
		    cout << "NO" << endl;
		    return;
		}
	}
		 
    swapCount = 0;
                                         
	for(int i=n; i>=1; i--)                  // winning arrangement is possible    
	{
		if(arr[i] != i)
		{ 
		    if(i-1 >= 0 && arr[i-1]==i)      // SingleSwapping between (i-1) & (i)
            {   swap(arr, i-1, i);   }
            else if(i-2 >= 0 && arr[i-2]==i) // DoubleSwapping between (i-2) & (i-1) & (i)
			{   swap(arr, i-2, i-1); 
                swap(arr, i-1, i);   } 
		}
	}
    
	cout<<"YES"<<endl;
    cout<<swapCount<<endl;
    
	return;
}

 // dontConsiderSimilarSwapping like [(i-1) & (i)] then [(i) & (i+1)] bczThenRepetition 
 // dontConsiderSimilarSwapping like [(i-2) & (i-1) & (i)] then [(i) & (i+1) & (i+2)] bczThenRepetition

int main()
{
	int t;
	cin >> t;
    
	while(t--)
	{
		int n;
		cin>>n;
        
		int arr[n+1];
		for(int i=1; i<n+1; i++)
		cin>>arr[i];
		
		winningStrategy(arr, n);
	}
}




 









