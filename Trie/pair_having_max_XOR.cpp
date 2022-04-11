#include <bits/stdc++.h>                                                      
using namespace std;


#define nBitString 32                                      // size of the BitString


/*
 
rp = rootPointer
pp = parentPointer
cp = childPointer 

  
XOR of a element with itself will be 0
Here, we are considering each element's BitString of size 32 bits, so Trie(BinaryTree) has height = 32 & max no of nodes = 2^(32)


finding max 'XOR by pair', after considering all the pairs of Array
ImplementingTrieInWhich leftChildMove=0 & rightChildMove=1, BitString generatedByTravellingFromRootToLeafInTrie representsAnElementOfArray 
Time complexity = O(n*nBitString) or O(n*log(Xmax))
We will search max 'XOR by pair' corresponding to each element, then return the best one
For max 'XOR by pair' corresponding to element x, search element whose mostly bits are opposite of x (so that 0^1=1 and 1^0=1 after XOR)  

*/


class TrieNode                                             // TrieNode class
{       public:
	TrieNode *left;                                        // leftChildNodeAddress
	TrieNode *right;                                       // rightChildNodeAddress
};


void insert(TrieNode *rp, int x)                           // inserting element x in the Trie
{
    TrieNode *pp, *cp;
    
    pp = rp; 
    
    for(int i=nBitString-1;  i>=0;  pp=cp,i--) 
	{
        int k = (x>>i) & 1;          
		        
        if(k==0)                                           // ith Bit of x is 0  =>  insert on left
        {   
		    if(pp->left == NULL) 
		    {   cp = new TrieNode(); 
                pp->left = cp;   } 
		    else
            cp = pp->left;   
		}
        else if(k==1)                                      // ith Bit of x is 1  =>  insert on right
        {
		    if(pp->right == NULL) 
		    {   cp = new TrieNode(); 
                pp->right = cp;   } 
		    else
            cp = pp->right;
        }
    }
}


int query(TrieNode *rp, int *arr, int n)                   // finding max XOR pair in array, if all array elements are inserted in Trie                                                 
{ 
    int xorMax = INT_MIN; 
    TrieNode *pp, *cp;
    
    
	for(int i=0;  i<n;  i++)                                
	{ 
	    pp = rp;
	    int x = arr[i];
        int xorCurr = 0; 
         
        for(int j=nBitString-1;  j>=0;  pp=cp,j--) 
	    {
            int k = (x>>j) & 1;           
		        
            if(k==0)                                       // ith Bit of x is 0  =>  xorCurr will be max by 1  =>  search on right
            {   
		        if(pp->right != NULL) 
		        {   xorCurr += pow(2,j); 
                    cp = pp->right;   } 
                else    
		        cp = pp->left; 
	    	}
            else if(k==1)                                  // ith Bit of x is 1  =>  xorCurr will be max by 0  =>  search on left
            {
	    	    if(pp->left != NULL) 
		        {   xorCurr += pow(2,j); 
                    cp = pp->left;   } 
	     	    else
                cp = pp->right;
            }
        }
        
        xorMax = max(xorMax, xorCurr);
    } 
    
    
    return xorMax;
}


int main()
{
    int n=6, arr[]={8,1,2,15,10,5};
 
 
    TrieNode *rp = new TrieNode();
	for(int i=0; i<n; i++) 
    insert(rp, arr[i]);                                    // inserting all array elements in Trie
    
    
    cout<< query(rp,arr,n) <<endl;                         // finding max 'XOR by pair' using Trie
}

 
/*

10 = "1010"
 5 = "0101"
 
10 ^ 5 = "1010" ^ "0101" = 15 
 
*/




                                                                





