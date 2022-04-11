#include <bits/stdc++.h>                 
using namespace std;


/*

Connected Graph = each 2 vertex have atleast 1 path between them          
Disconnected Graph = non connected graph having some connected subgraphs or connected components 

Connected Component (CC): subgraphOfGraph whichIsConnected
getting connected components using Adjacency List (arr[nV])

*/


vector<int>* storeInputGraph(int nV, int nE)
{ 
	vector<int> *arr = new vector<int>[nV];          // creating adjacency list 
 
	for(int i=0; i<nE; i++) 
	{
		int v1, v2;                                  // v1 & v2 belongs to [0, nV-1] here
		cin>>v1>>v2;      
		                          
		arr[v1].push_back(v2);                       // taking undirected graph input  
		arr[v2].push_back(v1);
	}
	
	return arr;
}
                                                

void subgraphTraversalDFS(int currV, vector<int> *arr, int nV, unordered_set<int> &visitedV, unordered_set<int> *cc) 
{
	visitedV.insert(currV);
	cc->insert(currV);                                                  // current vertex in DFS
	 
	for(vector<int>::iterator it=arr[currV].begin();  it!=arr[currV].end();  it++) 
	{ 
		if(visitedV.count(*it) == 0)                                    // next vertex in DFS 
		subgraphTraversalDFS(*it, arr, nV, visitedV, cc);
	}
}
                                                        
                                                                              
unordered_set<unordered_set<int>*>* getCCs(vector<int> *arr, int nV) 
{
	unordered_set<int> visitedV;                                        // storing that vertex 'i' is already visited   
	unordered_set<unordered_set<int>*>* ccList = new unordered_set<unordered_set<int>*>();
	
	for(int i=0; i<nV; i++) 
	{
		if(visitedV.count(i) == 0) 
		{   unordered_set<int> *cc = new unordered_set<int>();          // Set to store current CC 
			subgraphTraversalDFS(i, arr, nV, visitedV, cc);
			ccList->insert(cc);   }                                     // storing current Set in 2D Set 
	}
	
	return ccList;
}


void printCCs(unordered_set<unordered_set<int>*>* ccList)          
{ 
    cout<<"\nConnected Components:\n(reverse DFS order)"<<endl;
   
	for(unordered_set<unordered_set<int>*>::iterator itL=ccList->begin();  itL!=ccList->end();  itL++) 
	{
		unordered_set<int> *cc = *itL;                                // iterator of Set storing current CC 
		 
		for(unordered_set<int>::iterator it=cc->begin();  it!=cc->end();  it++) 
		cout<<*it<<" ";                                                // printing current CC from Set 
		cout<<endl;
		
		delete cc;                                                     // deleting the memory after use
	}
	
	delete ccList; 
}


int main()
{
	int nV, nE;
	cin>>nV>>nE; 
	
	vector<int> *arr = storeInputGraph(nV, nE);
	
	
	unordered_set<unordered_set<int>*>* ccList = getCCs(arr, nV);
    
	printCCs(ccList);
}

 
/*

8 7
0 1
1 3
1 6
3 7
2 4
2 5
4 5
 
      Input Graph
                  0
      2           |
     /\           1
    /  \          /\
   4----5        /  \
                6    3
                     |
                     7
 
*/











