#include <bits/stdc++.h>
using namespace std;


#define nBitString 32                            // size of the BitString


/*
 
rp = rootPointer
pp = parentPointer
cp = childPointer 

  
XOR of x with 0 will be x
Here, we are considering each element's BitString of size 32 bits, so TrieBinaryTree has height = 32 & max no of nodes = 2^(32)


finding max 'XOR by subarray', after considering all the contiguous subarrays of Array
Implementing Trie in which leftChildMove=0 & rightChildMove=1, BitString generatedByTravelling from Root to Leaf represents aElementOfArray 
Time complexity = O(n*nBitString) or O(n*log(Xmax))
We will insert {0, A0, A0^A1, A0^A1^A2,..... A0^A1^...^A(i-2), A0^A1^...^A(i-1)} in Trie, thenSearchMax'XOR by pair' correspondingTo{A0^A1^...^Ai} 
XOR of A0^A1^...^Aj with A0^A1^...^Ai will be A(j+1)^A(j+2)^...^A(i-1)^Ai, which will be xor of a general subarray XOR ending at Ai {j=0 to j=i-1} 
XOR of A0^A1^...^Ai with CurrentTrieElements will give xor of all subarrays ending at Ai 
finding max 'XOR by pair' correspondingToEachSubarrayA0^A1^...^Ai fromTrie, will give max 'subarray XOR'                                                              
For max 'XOR by pair' corresponding to element x, search element whose mostly bits are opposite of x (so that 0^1=1 and 1^0=1 after XOR)  

*/
                            
                                      
class TrieNode                                   // TrieNode class
{         public:  
    TrieNode *children[2];                       // addressesOfTwoChildrenNodes nextBit'0'=storeIn'children[0]' & nextBit'1'=storeIn'children[1]'
    
    TrieNode() 
	{   children[0] = NULL;             
        children[1] = NULL;   }
};


void insert(TrieNode *rp, int x)                 // inserting element x in the Trie
{
    TrieNode *pp, *cp;
    
    pp = rp; 
    
    for(int i=nBitString-1;  i>=0;  pp=cp,i--) 
	{
        int k = (x>>i) & 1;
        
        if(pp->children[k] == NULL)              // noNode  =>  ith Bit of x is 0/1  =>  create children[0]/children[1] on left/right
		{   cp = new TrieNode; 
            pp->children[k] = cp;   } 
		else                                     // nodePresent  =>  ith Bit of x is 0/1  =>  moveTo children[0]/children[1] on left/right
        cp = pp->children[k]; 
    }
}


int query(TrieNode *rp, int currArrayXOR)         // finding max XOR pair in Trie, if all subarray(startingFrom'0') xor are inserted in Trie 
{
	if(rp==NULL)
    return 0;
     
     
    int maxSubarrayXOR = 0;                      // maxSubarrayXOR outOfAllTheSubarraysWhichEndsAt'arr[i]'
    TrieNode *pp, *cp;
    
    pp = rp;
  
	for(int j=nBitString-1;  j>=0;  pp=cp,j--) 
	{
        int k = (currArrayXOR>>j) & 1;
        
		if(pp->children[1-k] == NULL)
	    {   cp = pp->children[k];   } 
	    else 
    	{   cp = pp->children[1-k];  
     	    maxSubarrayXOR += pow(2,j);   }  
    } 
     
 
    return maxSubarrayXOR;
}


int main()
{
    int n;
    cin>>n;
    
  
	int arr[n], maxSubarrayXOR=0;          
    TrieNode *rp = new TrieNode;
	
	int currArrayXOR = 0;
    insert(rp, currArrayXOR);                      // inserting 0 (32 bit length) to consider currArrayXOR also in query(), for finding maxSubarrayXOR 
      
	for(int i=0; i<n; i++) 
	{   
	    cin>>arr[i]; 
        currArrayXOR ^= arr[i];  
        
        int temp = query(rp, currArrayXOR);        // maxSubarrayXOR outOfAllTheSubarraysWhichEndsAt'arr[i]'
        maxSubarrayXOR = max(maxSubarrayXOR, temp);
        
        insert(rp, currArrayXOR);    
	} 
	
	
    cout<< maxSubarrayXOR <<endl;
}












 


