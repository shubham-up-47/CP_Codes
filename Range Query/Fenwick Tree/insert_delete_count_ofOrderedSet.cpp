#include <bits/stdc++.h>
using namespace std;
 

/*

'arr[n]'ContainsDistinctElementsInSortedOrder so'arr[i]'IsGreaterThan'i'Elements

Initially, noContributionByAnyIndexNo soInitializeBIT[n+1]by'0'
'BIT[iCN]'havingIndexNoRange'[0,i]' = noOfElementsLessThanOrEqualTo'arr[i]' = sumOfContributions(0/1)ByAllIndexNoOf'arr[n]'InTheRange[0,i] 
 
Time Complexity = O(n*logn*logn) 

*/


class unit
{      public:
	int value;
	bool isInserted;                                            // tellsThatTheElementIsInsertedInArrayOrNot afterQuery(0)to(i-1)
}; 


class temp
{      public:
	int indexNo;
	bool isPresent;                                             // tellsThatTheElementIsPresentIn totalInsertionElementsListOrNot
}; 


int query(int *BIT, int i)
{ 
	int count = 0;
	
	for(int iCN=i+1; iCN>0; iCN-=(iCN&(-iCN)))
	count += BIT[iCN];
	
	return count;
}


void update(int *BIT, int n, int i, int newValue)
{
	for(int iCN=i+1; iCN<n+1; iCN+=(iCN&(-iCN)))
	BIT[iCN] += newValue; 
}


temp binarySearch(int x, vector<unit> &arr, int n)              // searchingElement inTotalInsertionElements
{
	int sI=0, eI=n-1, ansI=-1;
	
	while(sI <= eI)
	{
		int mI = (sI + eI)/2;
		
		if(arr[mI].value == x)
		return {mI, true};                                      // elementFound inArrayStoringUniqueElements
		else if(arr[mI].value > x)
		eI = mI-1;
		else 
		{   ansI = mI; 
			sI = mI+1;   } 
	}                                                              
	                                                                    
	return {ansI, false};                                       // elementWasNotFound inArrayStoringUniqueElements
}
                                          
                                         
int main()
{ 
	int nQ;
	cin >> nQ;
	
	int qrrValue[nQ];
	vector<char> qrrType(nQ);
	
	vector<int> vtr; 
	for(int i=0; i<nQ; i++)                                     // OfflineProgramming soStoringAllQueries(Type + Value)  
	{   
        cin >> qrrType[i] >> qrrValue[i]; 
		 
        if(qrrType[i] == 'I')
        vtr.push_back(qrrValue[i]);   
    } 
    sort(vtr.begin(), vtr.end());
    
    int n=0;
    vector<unit> arr;  
    for(int i=0; i<vtr.size(); i++)
    {
    	if(i==0 || vtr[i]!=vtr[i-1])                            // considerOnlyDistinctElements inSortedOrder bczWeCan'tInsertRepeatedElement
    	{   arr.push_back({vtr[i],0});                          // CoordinateCompression 
		    n++;   }
	}
	                                  
	
	int BIT[n+1] = {0};                           
	                                                                                                                    
	for(int i=0; i<nQ; i++)                                     // considering'arr[i]'AsElement'i'InBIT bczOnlyRelativeOrderOfElementsMatterHere      
	{
		if(qrrType[i] == 'I')
		{
			temp t = binarySearch(qrrValue[i], arr, n);
			
			if(arr[t.indexNo].isInserted==false)                // elementIsNotInsertedAlready weAreAllowedToInsertIt               
			{   arr[t.indexNo].isInserted = true;
			    update(BIT, n, t.indexNo, 1);   }
		}
		else if(qrrType[i] == 'D')
		{
			temp t = binarySearch(qrrValue[i], arr, n);
			                                                                      
			if(t.isPresent && arr[t.indexNo].isInserted==true)  // elementWasInsertedAlready weAreAllowedToDeleteIt     
            {   arr[t.indexNo].isInserted = false;
                update(BIT, n, t.indexNo, -1);   }              // excludeTheContributionCorrespondingToItsIndexNo
		}
		else if(qrrType[i] == 'C')
		{
			temp t = binarySearch(qrrValue[i], arr, n);         // returning index no ansI where (arr[ansI].value <= qrrValue[i])        
			
			if(t.isPresent && t.indexNo>0)                      // finding no of elements less than qrrValue[i]
			cout << query(BIT, t.indexNo-1) << endl;             
	    	else if(t.indexNo != -1)
	    	cout << query(BIT, t.indexNo) << endl;
			else                                          
			cout << 0 << endl;
		}
		else if(qrrType[i] == 'K')
		{
			int k=qrrValue[i], z=0;
			
			int sI=0, eI=n-1, mI;
			
			while(sI <= eI)                                     // finding'kth'SmallestElementUsingBIT bczBITof'[0,a]'=NoOfElementsLessThanOrEqualTo'a'
			{ 
				mI = (sI + eI)/2;
				int currI_count = query(BIT, mI);
				int prevI_count = query(BIT, mI-1);
				
				if(currI_count==k && prevI_count!=k)            // noOfElementsSmallerThanOrEqualToTheTargetElement = k 
				{   z = 1;
				    break;   }
				else if(currI_count < k)
				sI = mI+1;   
				else  
				eI = mI-1;	    
			}
			
			if(z==0)
			cout<<"invalid"<<endl;
			else
			cout<<arr[mI].value<<endl;                          // printingValueCorrespondingToTheIndexOf'kth'SmallestElement
		}
	}
}



















