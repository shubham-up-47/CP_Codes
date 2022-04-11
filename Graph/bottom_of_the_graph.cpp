#include <bits/stdc++.h>
using namespace std;


void DFS1(vector<vector<int>> &adj, int currV, bool *visitedV, vector<int> &sortedV) 
{
  visitedV[currV] = true;
  
  for(int i=0; i<adj[currV].size(); i++) 
  {
    if(!visitedV[adj[currV][i]]) 
    DFS1(adj, adj[currV][i], visitedV, sortedV);
  }
  
  sortedV.push_back(currV);
}


void DFS2(vector<vector<int>> &adjT, int currV, bool *visitedV, int *SCC, int serialNo) 
{
  visitedV[currV] = true;
  SCC[currV] = serialNo;
  
  for(int i=0; i<adjT[currV].size(); i++) 
  {
    if(!visitedV[adjT[currV][i]]) 
    DFS2(adjT, adjT[currV][i], visitedV, SCC, serialNo); 
  }
}


int main() 
{
   int t;
   cin>>t;
    
   while(t--) 
   {
      int n, m;
      cin>>n>>m;
      
      vector<vector<int>> adj(n), adjT(n);         // AdjacencyMatrix(Graph), TransposeAdjacencyMatrix(TransposeGraph)           
      for(int i=0; i<m; i++) 
	  {
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adjT[b].push_back(a);
      }
      
      
      bool visitedV[n];
      vector<int> sortedV;                          //  vertices in their increasingOrderOfFinishingTime (SinkVertices then SourceVertices) 
       
      memset(visitedV, false, sizeof(visitedV));
      for(int i=0; i<n; i++) 
	  {
        if(!visitedV[i]) 
        DFS1(adj, i, visitedV, sortedV);                 
      }
      
      
      int serialNo = 0;                            // serial no of current SCC (make SCC[i]=serialNo for all vertices of current SCC)
      int SCC[n];                                  // array storing vertices where (SCC[i] = serial no of correspondong SCC) of current vertex
      vector<bool> isValidSCC(n, false);           // isValidSCC[i]=true means SCC having serialNo=i will be included in the BottomOfTheGraph

      memset(visitedV, false, sizeof(visitedV));
      for(int i=sortedV.size()-1; i>=0; i--)       // using Stack/sortedV in o  
	  {
        if(!visitedV[sortedV[i]]) 
		{
          DFS2(adjT, sortedV[i], visitedV, SCC, serialNo);
          isValidSCC[serialNo] = true;
          serialNo++;
        }
      }
                 
      for(int i=0; i<n; i++) 
	  {
        for(int j=0; j<adj[i].size(); j++) 
	    { 
          if(SCC[i] != SCC[adj[i][j]])         // forOutgoingEdge'i'To'j', if'j'LiesInDifferentSCC thenSCC'i'CannotBeIn'BottomOfTheGraph' excludeIt 
	  	  {
            isValidSCC[SCC[i]] = false;
            break;
          }
        }
      }
        
      
	  for(int i=0; i<n; i++) 
	  {  
	     if(isValidSCC[SCC[i]] == true)
         cout<<i+1<<" ";  
	  }
      cout<<endl;
   } 
}
    
    
    
    
    
    
    
    
    
    
