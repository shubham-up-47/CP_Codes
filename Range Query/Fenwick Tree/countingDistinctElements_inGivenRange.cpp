#include <bits/stdc++.h>
using namespace std;


/*

noOfDEcurr = noOfDistinctElementsInTheArray correspondingToTheIndexNoRange[0,i]
noOfDE[i] = noOfDistinctElementsInTheArray correspondingToTheIndexNoRange[sI,eI]OfQuery'i'

rightmostI[arr[i]] = rightmostIndexIn'[0, i-1]' atWhich'arr[i]'IsPresent     
                                                   
Initially, noContributionByAnyIndexNo soInitializeBIT[n+1]by'0'
BIT[iCN] = sumOfContributions(0/1)ByAllIndexNumbers inTheRangeOfCurrentNode 
 
*/


class Query
{	   public:                                            
    int queryNo;                                                
	int sI;                                      // startIndex                  
	int eI;                                      // endIndex                     
};
 

void update(int *BIT, int n, int k, int value)   // updatingContribution(0/1)CorrespondingToIndex'k'Of'arr[n]'
{ 
	for(int iCN=k+1; iCN<n+1; iCN+=(iCN&(-iCN)))
	BIT[iCN] += value; 
} 


int query(int *BIT, int k)                       // findingNoOfDistinctElementsIn[0,k] ifWeConsiderOnlyRightmostPresenceOfEachElementIn[0,i]
{ 
	int count = 0;
	
	for(int iCN=k+1; iCN>0; iCN-=(iCN&(-iCN)))
	count += BIT[iCN]; 
	
	return count;
}


bool compare(Query A, Query B)                   // sortingQueryArray basedOnEndingIndex   
{ 
	return (A.eI < B.eI);
}


int main()                                       // findingNoOfDistinctElementsInGivenRange
{ 
	int n;
	cin>>n; 
    int arr[n], BIT[n+1]={0}, noOfDE[n], noOfDEcurr=0;
	for(int i=0; i<n; i++)
	cin>>arr[i];
	 
	int nQ;
	cin>>nQ; 
	Query qrr[nQ];
	for(int i=0; i<nQ; i++)                      // OfflineProgramming
	{   qrr[i].queryNo = i;
		cin >> qrr[i].sI >> qrr[i].eI;   } 
 
    unordered_map<int,int> rightmostI;           // mapTelling'arr[i]'ArrayElementRepeatsOrNot & storingItsRightmostIndexIn'[0, i-1]'  
            
            
	sort(qrr, qrr+nQ, compare); 
	              
	for(int i=0,j=0;  i<n;  i++)                 // takeCareOfSumOfContributions(0/1)ByIndexNumbers
	{        
		if(rightmostI.count(arr[i]) == 0)        // ElementIsNotRepeated i.e. newDistinctElement   
		noOfDEcurr++;                
		else                                     // ElementRepeats removeOld'+1'ContributionByAdding'-1'AtOldIndexNoInBIT                
		update(BIT, n, rightmostI[arr[i]], -1); 


        rightmostI[arr[i]] = i;                         
		update(BIT, n, i, 1);                    // AddContribution'+1'CorrespondingToTheCurrentIndexOfElement 
                                    
	                            
		while(j<nQ && qrr[j].eI==i)              // resolveQueriesHavingRange[a,i]   
		{              
			noOfDE[qrr[j].queryNo] = noOfDEcurr - query(BIT, qrr[j].sI-1);
			j++; 
		}    // currAns = BIT[0,i] - BIT[0,a-i] = totalElementsTill(i) - totalElementsTill(a-1) consideringOnlyRightmostPresenceOfEachElement 
	}

	for(int i=0; i<nQ; i++)
	cout<<noOfDE[i]<<endl;
}


/*

1 1 1 2 3 5 7 2     =>     TotalNoOfDistintElementsIn[0,7] = 5 {1,2,3,5,7}

*/













 
