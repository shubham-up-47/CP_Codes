#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


class Job
{     public:
	int startT;
    int endT;
	int payment;	
};


bool compare(Job a, Job b)
{
	return (a.endT < b.endT);
}

  // upper_bound() returns iterator pointing to 1st element which has value > x   {O(logn)}
   
int modifiedUpperBound(Job *arr, int n, int x)
{
    int sI=0, eI=n;                                          // startIndex & endIndex
 
    while(sI < eI) 
	{ 
        int mI = (sI + eI)/2;                                // midIndex
  
        if(x >= arr[mI].endT) 
        sI = mI + 1; 
        else 
        eI = mI;
    }
    
    if(sI<n && arr[sI].endT<=x)                              // if x is greater than arr[n-1]
    sI++; 
    
	return (sI-1);                                           // return oneIndexLesser than theLowerBoundIndex 
}

 
int maxPossiblePaymentFromGivenJobs(Job *arr, int n)         // maxPossiblePaymentWeCanGenerate byDoingSome/AllNonOverlappingJobs outOfGivenJobs  
{
	sort(arr, arr+n, compare);                               // sortingJobs basedOnTheirEndTime
	
	int dp[n];                                               // dp[i] = maxPossiblePaymentCorrespondingToTheDuration  [0, EndTimeOfJob_i]
	dp[0] = arr[0].payment;                                  // initialization of DP
	
	for(int i=1; i<n; i++)                                   // dp[i] = max(maxPaymentExcludingJob_i, maxPaymentIncludingJob_i) 
	{ 
		int j = modifiedUpperBound(arr, n, arr[i].startT);   // returningIndexNumberOfTheJob whichIsJustBeforeJob_i 
		
/*		for(int k=i-1; k>=0; k--) 
		{	if(arr[k].endT <= arr[i].startT)
			{   j = k;
			    break;   }	 }       */

		if(j==-1)
		dp[i] = max(dp[i-1], arr[i].payment);
		else
		dp[i] = max(dp[i-1], arr[i].payment + dp[j]);
	} 
	
	return dp[n-1];  
}


int main()
{
    Job arr[] = {{2,5,50}, {1,2,20}, {6,9,70}, {2,50,400}};
	
	cout<<"Maximum Profit is: "<< maxPossiblePaymentFromGivenJobs(arr, 4) <<endl;
}








