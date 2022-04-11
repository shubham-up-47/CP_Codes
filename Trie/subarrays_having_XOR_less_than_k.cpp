#include <bits/stdc++.h>
using namespace std;


#define nBitString 32 

 
/*
 
rp = rootPointer
pp = parentPointer
cp = childPointer 

  
XOR of x with 0 will be x
Here, we are considering each element's BitString of size 32 bits, so TrieBinaryTree has height = 32 & max no of nodes = 2^(32)
 

finding countOfSubarraysWhose 'XOR by subarray' isLessThan k, after considering all the contiguous subarrays of Array
Implementing Trie in which leftChildMove=0 & rightChildMove=1, BitString generatedByTravelling from Root to Leaf represents aElementOfArray 
Time complexity = O(n*nBitString) or O(n*log(Xmax))
We will insert {0, A0, A0^A1, A0^A1^A2,..... A0^A1^...^A(i-2), A0^A1^...^A(i-1)} in Trie, thenSearchLessThan k 'XOR by pair' w.r.t.{A0^A1^...^Ai} 
XOR of A0^A1^...^Aj with A0^A1^...^Ai will be A(j+1)^A(j+2)^...^A(i-1)^Ai, whichWillBeXOR ofGeneralSubarrayEndingAt'Ai' {j=0 to j=i-1} 
XOR of A0^A1^...^Ai with CurrentTrieElements will give XOR of all subarrays ending at Ai  
countingLessThan k 'XOR by pair' correspondingToEachSubarrayA0^A1^...^Ai fromTrie, will give countOfAllSubarrayWhoseXOR lessThan k                                                              
For greater 'XOR by pair' corresponding to element x, go for element whoseCurrentBitsIsOppositeOf CurrentBitsOf'x'  
For lesser 'XOR by pair' corresponding to element x, go for element whoseCurrentBitsIsSameAs CurrentBitsOf'x'

*/
      

class TrieNode                          // TrieNode class
{           public:
    int count;                          // countOfAllTheNumbersWhoseBitStringEndsAtOrBelowCurrentTrieNode stored in TrieNode 
    TrieNode *children[2];              // addressesOfTwoChildrenNodes nextBit'0'=storeIn'children[0]' & nextBit'1'=storeIn'children[1]'
    
    TrieNode() 
	{   count = 0;                     
        children[0] = NULL;
        children[1] = NULL;   }
};


void insert(TrieNode *rp, int x) 
{
    TrieNode *pp, *cp;
    
    pp = rp;
    
    for(int i=nBitString-1;  i>=0;  pp=cp,i--) 
	{
        int k = (x>>i) & 1;
        
        if(pp->children[k] == NULL) 
		{   cp = new TrieNode;
            cp->count = 1;
            pp->children[k] = cp;   } 
		else
        {   cp = pp->children[k];
            cp->count += 1;   }                 // countOfAllTheNumbers whoseBitStringPassesThroughCurrentNode 
    }
}
                                

int query(TrieNode *rp, int currArrayXOR, int k) 
{
	if(rp==NULL)
    return 0;
     
      
    int requiredCount=0;                        // findingCountOfAllSubarraysEndingAt'arr[i]' whoseElement'sXOR isLessThan'k' 
    TrieNode *pp, *cp;
    
    pp = rp;
                         
	for(int j=nBitString-1;  j>=0 && pp!=NULL;  pp=cp,j--)     // x = currArrayXOR = A0^A1^...^Ai 
	{
        int p = (k>>j) & 1;                                    // currentBitOf'k'
        int q = (currArrayXOR>>j) & 1;                         // currentBitOf'x'
            
        if(p==1)                               // if (currentBitOf'k'==1) then moveOppositeToCurrentBitOf'x' & countAllBitStringsAlongCurrentBitOf'x'
        {   if(pp->children[q] != NULL)
	    	requiredCount += pp->children[q]->count; 
	    	    
	    	cp = pp->children[1-q];	  } 
	    else if(p==0)                          // if (currentBitOf'k'==0) then moveAlongCurrentBitOf'x'  
     	{   cp = pp->children[q];   }
    } 


    return requiredCount;
}
    

int main() 
{
    int n, k;
    cin>>n>>k;
     
     
	int arr[n], requiredCount=0;          
    TrieNode *rp = new TrieNode;
	
	int currArrayXOR = 0;
    insert(rp, currArrayXOR);                      // inserting 0 (32 bit length) to consider currArrayXOR also in query(), for finding requiredCount 
      
	for(int i=0; i<n; i++) 
	{   
	    cin>>arr[i]; 
        currArrayXOR ^= arr[i];  
        
        int temp = query(rp, currArrayXOR, k);     // maxSubarrayXOR outOfAllTheSubarraysWhichEndsAt'arr[i]'
        requiredCount += temp;
        
        insert(rp, currArrayXOR);    
	} 
	
	
    cout<< requiredCount <<endl;                   // count of all the subarrays of arr[], whose element's XOR is less than k
} 






 

