#include <bits/stdc++.h>                            
using namespace std;

 
class TrieNode                          // TrieNode class
{         public:
	bool isTerminal; 
    TrieNode *children[26];             // addressOfArray storingAddressesOfChildrenNodes (atmax'26'ChildrenOfEachNode)
    
    TrieNode() 
	{   isTerminal = false;
 
        for(int i=0; i<26; i++)         // for a word in Trie, nextCharCanBeOneOutOf'26'Alphabets, soNextChildCanBeOneOutOf'26'Children  
        children[i] = NULL;   }
};


void insert(TrieNode *rp, string Word) 
{
    int n = Word.size();
    TrieNode *pp, *cp;
    
    pp = rp;
    
    for(int i=0;  i<n;  pp=cp,i++) 
	{
        int k = Word[i]-'a';            // kth child of current node, will store current alphabet
         
        if(pp->children[k]==NULL) 
        {   cp = new TrieNode();
            pp->children[k] = cp;   }
        else
        cp = pp->children[k];
    }
    
    pp->isTerminal = true;
}


void autoComplete(TrieNode *pp, vector<string> &validWords, string &currPrefixWord)         // findingValidWords correspondingToCurrPrefixWord                                      
{	
    if(pp==NULL) 
	{   validWords.push_back(currPrefixWord);
	    return;   }
    else if(pp->isTerminal==true) 
	validWords.push_back(currPrefixWord);

 
    for(int j=0;  j<26; j++) 
	{
		TrieNode *cp = pp->children[j];
		
        if(cp != NULL) 
		{   char nextChar = 'a'+j;
		
		    currPrefixWord.push_back(nextChar);
            autoComplete(cp, validWords, currPrefixWord);                                   // DFS
		    currPrefixWord.pop_back();   } 
    }
}


void search(TrieNode *rp, vector<string> &validWords, string PrefixWord) 
{
    int n = PrefixWord.size(); 
    TrieNode *pp, *cp;
	
	pp = rp;   
    string currPrefixWord;  
    
    for(int i=0;  i<n;  pp=cp,i++) 
	{
        int k = PrefixWord[i]-'a';
        cp = pp->children[k];
        
		if(cp != NULL) 
		currPrefixWord += PrefixWord[i];  
		else
        break;
    }
    
    if(currPrefixWord.size() < n)
    return;
    else
	autoComplete(pp, validWords, currPrefixWord);
}


int main() 
{
    int n;
    cin>>n;

    TrieNode *rp = new TrieNode;

    while(n--) 
	{   string Word;
        cin>>Word; 
		insert(rp, Word);   }


    int nQ;
    cin>>nQ;

    while(nQ--) 
	{
        string PrefixWord;
        cin>>PrefixWord;
        
        vector<string> validWords;
        search(rp, validWords, PrefixWord);
         
        if(validWords.size() == 0) 
		{   cout<<"No suggestions"<<endl;
            insert(rp, PrefixWord);   } 
		else 
		{   for(int i=0; i<validWords.size(); i++) 
            cout<< validWords[i] <<endl;   }
    }
}















