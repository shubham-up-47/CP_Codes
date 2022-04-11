#include <bits/stdc++.h>
using namespace std;


/*

Bipartite Graph = graph made of 2 independent set of vertices (2 parts), where no edge between same set vertices   
Bicolourable Graph = graph having chromatic number (related to graph colouring) is 2 
Bipartite Graph = Bicolourable Graph  


Note:
*graph having odd length cycle, can't be Bipartite/Bicolourable
*Bipartite/Bicolourable graph can have only even length cycle 

*/
 

vector<int>* storeInputGraph(int nV, int nE)
{ 
	vector<int> *arr = new vector<int>[nV];          // creating AdjacencyList 
 
	for(int i=0; i<nE; i++) 
	{
		int v1, v2;                                  // v1 & v2 belongs to [0, nV-1] here
		cin>>v1>>v2;      
		                          
		arr[v1].push_back(v2);                       // taking undirected graph input  
		arr[v2].push_back(v1);
	}
	
	return arr;
}
              

bool checkBipartiteOrBicolourable(vector<int> *arr, int nV)          // algorithm based on defination of Bipartite Graph
{
	if(nV==0)
	return 1;
	
	
	unordered_set<int> setV[2];
	vector<int> pendingV;                    // storing pendingVertices which are not handled till now  
	
	 
	setV[0].insert(0);
	pendingV.push_back(0);
	
	while(pendingV.size() > 0)       // maintaining two independentSetOfVertices (setV[0] & setV[1]), to check current graph Bipartite/Bicolourable 
	{
		int currV = pendingV.back();                            
		pendingV.pop_back();
		
		int flag = (setV[0].count(currV)>0) ? 0 : 1;            // (flag = 0/1 meansCurrVertexWasIncludedInSet 0/1)  
		 
		 
		for(int i=0; i<arr[currV].size(); i++)                  // storingAllNeighourVertiesOfCurrVertex inTheSetOppositeToCurrentVertex
		{
			int neighbourV = arr[currV][i];                     
			
			if(setV[flag].count(neighbourV) > 0)                // ifNeighbourVertexWasIncludedInSetOfCurrVertex thenGraphIsNonBipartite       
			return 0; 
			else if(setV[1-flag].count(neighbourV) > 0) 
			continue;
			else                                                 // ifNeighbourVertex wasNeverIncluded
			{   setV[1-flag].insert(neighbourV);
				pendingV.push_back(neighbourV);	  }  
		}
	}
	                 
	return 1;
}
 

int main()                  // assumingInputGraphIsConnected, ifInputGraphIsDisconnected thenCheckThatEachComponentIsBipartiteOrNot (asWeDoForDFS)
{
	int nV, nE;
	cin>>nV>>nE;  
	vector<int> *arr = storeInputGraph(nV, nE);
	  
	  
	bool r = checkBipartiteOrBicolourable(arr, nV);
 
	if(r) 
	cout<<"Bipartite/Bicolourable"<<endl;
	else 
	cout<<"Non Bipartite/Bicolourable"<<endl;
}


/*

5 5
0 1
1 2
2 3
3 4
0 4

    0
   / \ 
  4   1
  |   |
  3---2



4 4
0 1
1 3
2 3
0 2

  0---1
  |   |
  2---3 

*/







