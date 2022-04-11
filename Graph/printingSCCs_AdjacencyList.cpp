#include <bits/stdc++.h>
using namespace std;


/*

Strongly Connected Graph: DirectedGraph inWhich allOtherVerticesAreReachable fromEachVertexOfGraph  
 
Connected Component (CC): subgraph/component ofGraph whichIsConnected
Strongly Connected Component (SCC): subgraph/component ofGraph whichIsStronglyConnected

getting strongly connected components using Adjacency List (arr[nV])

*/


pair<vector<int>*,vector<int>*> storeInputGraph(int nV, int nE)                  
{ 
	vector<int> *arr = new vector<int>[nV];          // creating AdjacencyList 
	vector<int> *Tarr = new vector<int>[nV];         // creating TransposeAdjacencyList  
 
	for(int i=0; i<nE; i++) 
	{
		int v1, v2;                                  // v1 & v2 belongs to [0, nV-1] here
		cin>>v1>>v2;      
		                          
		arr[v1].push_back(v2);                       // storing edge 
		Tarr[v2].push_back(v1);                      // storing transpose edge 
	}
	
	pair<vector<int>*,vector<int>*> p = {arr,Tarr};
	return p;
}

     
void subgraphTraversalDFS(vector<int> *arr, int currV, unordered_set<int> &visitedV, stack<int> &finishedVertices)  // DFS  
{
	visitedV.insert(currV);                                                    // current vertex in DFS 
	
	for(int i=0; i<arr[currV].size(); i++) 
	{ 
		if(visitedV.count(arr[currV][i])==0)                                   // next vertex in DFS    
		subgraphTraversalDFS(arr, arr[currV][i], visitedV, finishedVertices); 
	}
	
	finishedVertices.push(currV);                                              // storing vertices in increasing order of Finishing Time 
}


void TsubgraphTraversalDFS(vector<int> *arr, int currV, unordered_set<int> *scc, unordered_set<int> &visitedV)  // transpose DFS
{
	visitedV.insert(currV); 
	scc->insert(currV);                                                         // current vertex in DFS   
	
	for(int i=0; i<arr[currV].size(); i++) 
	{ 
		if(visitedV.count(arr[currV][i])==0)                                    // next vertex in DFS  
		TsubgraphTraversalDFS(arr, arr[currV][i], scc, visitedV);
	}
}
       

unordered_set<unordered_set<int>*>* getSCCs(vector<int>* arr, vector<int>* Tarr, int nV)          // Kosaraju Algo
{
	unordered_set<int> visitedV;                                  // storing that vertex 'i' is already visited 
	stack<int> finishedVertices;                                  // storing CCs in Stack (Last CC to First CC, SinkVertex than SourceVertex)  
	
	for(int i=0; i<nV; i++)                                       // storingVerticesOfCCs ofDirectedGraph inStack (inIncreasingOrderOfFinishingTime)
	{
		if(visitedV.count(i)==0)                    
		subgraphTraversalDFS(arr, i, visitedV, finishedVertices);
	}
	
	
	unordered_set<int> TvisitedV;                                  // storing that vertex 'i' is already visited while doing transpose DFS 
	unordered_set<unordered_set<int>*>* sccList = new unordered_set<unordered_set<int>*>();
 
	while(finishedVertices.size() != 0)                            // calculatingSCC byDFSfromTheSinkVertex onTransposeAdjacencyList   
	{  
		int currV = finishedVertices.top();
		finishedVertices.pop();
		
		if(TvisitedV.count(currV) == 0)  
		{   unordered_set<int>* scc = new unordered_set<int>();    // Set to store current SCC
		
	  	    TsubgraphTraversalDFS(Tarr, currV, scc, TvisitedV);
		    sccList->insert(scc);   }                              // storing current Set in 2D Set 
	}
	
	return sccList;
}
 

void printSCCs(unordered_set<unordered_set<int>*>* sccList)          
{ 
    cout<<"\nStrongly Connected Components:"<<endl;
   
	for(unordered_set<unordered_set<int>*>::iterator itL=sccList->begin();  itL!=sccList->end();  itL++) 
	{
		unordered_set<int>* scc = *itL;                           // iterator of Set storing current SCC
		  
		for(unordered_set<int>::iterator it=scc->begin();  it!=scc->end();  it++) 
		cout<<*it<<" ";                                           // printing current SCC from Set 
		cout<<endl;
		
		delete scc;                                               // deleting the memory after use
	}
	
	delete sccList;
}
 

int main() 
{
	int nV, nE;
	cin>>nV>>nE; 
	
	pair<vector<int>*,vector<int>*> p = storeInputGraph(nV, nE);
	vector<int> *arr = p.first;
	vector<int> *Tarr = p.second;
	
	
	unordered_set<unordered_set<int>*>* sccList = getSCCs(arr, Tarr, nV);    // finding SCCs using Kosaraju Algo
	
	printSCCs(sccList);


	delete [] arr;
	delete [] Tarr;
}

 
/*

6 7
0 1
1 2
2 3 
3 0
2 4
4 5
5 4
 
 
   0 -------> 1
   /\         | 
   |          |
   |          | 
   |          V           <------
   3 <------- 2 ------> 4 ------> 5
      
      
    [  SCC1  ]          [  SCC2  ]
      0 1 2 3               4 5        
	      
*/











