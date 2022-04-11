#include <bits/stdc++.h> 
using namespace std;

 
class TrieNode                          // TrieNode class
{         public:
	bool isTerminal;
    int weight;                         // weight stored in TrieNode 
    TrieNode *children[26];             // addressOfArray storingAddressesOfChildrenNodes (atmax'26'ChildrenOfEachNode)
    
    TrieNode() 
	{   isTerminal = false;
	    weight = 0;
	    
        for(int i=0; i<26; i++)         // for a word in Trie, nextCharCanBeOneOutOf'26'Alphabets, soNextChildCanBeOneOutOf'26'Children   
        children[i] = NULL;   }
};

 
void insert(TrieNode *rp, string Word, int weightCurrWord)   // cp->weight = weightOfMaxWeightWord outOfAllTheWordsWhichPassesThrough'cp'       
{
	int n = Word.size();
    TrieNode *pp, *cp;
    
    pp = rp;
    
    for(int i=0;  i<n;  pp=cp,i++) 
	{
        int k = Word[i]-'a';                                 // kth child of current node, will store current alphabet
        
        if(pp->children[k] == NULL) 
		{   cp = new TrieNode();
            cp->weight = max(cp->weight, weightCurrWord);
            pp->children[k] = cp;   } 
		else
        {   cp = pp->children[k];
            cp->weight = max(cp->weight, weightCurrWord);   } 
    }
    
    pp->isTerminal = true;
}


int search(TrieNode *rp, string PrefixWord) 
{
    int n = PrefixWord.size();
    TrieNode *pp, *cp;
      
    pp = rp;
 
    for(int i=0;  i<n;  pp=cp,i++)                    
	{
        int k = PrefixWord[i]-'a';
        cp = pp->children[k];
        
        if(cp == NULL) 
        return -1;  
    }  
    
    
    int weightTargetWord = -1;               // (TargetWordSize shouldBeGreaterThan PrefixWordSize) and (TargetWordWeight shouldBeMaxPossible)
    for(int i=0; i<26; i++)                  // finding weightOfMaxWeightWord whichEndsBelow'pp'(nodeOfLastCharOfPrefixWord)
	{
		cp = pp->children[i];
		
        if(cp != NULL) 
		weightTargetWord = max(weightTargetWord, cp->weight);    
    }
    
    return weightTargetWord;                  
}


int main() 
{
    int n, nQ;
    cin>>n>>nQ;
    
    
    TrieNode *rp = new TrieNode;
    

    while(n--) 
	{   string Word;
        int weightCurrWord;
        cin>>Word>>weightCurrWord;
        
        insert(rp, Word, weightCurrWord);   }
    
    
    while(nQ--) 
	{   string PrefixWord;
        cin>>PrefixWord;
        
        cout<< search(rp,PrefixWord) <<endl;   }  
}












