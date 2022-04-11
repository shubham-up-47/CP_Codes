#include <bits/stdc++.h> 
using namespace std;


void DFS(vector<vector<int>> &adj, bool visitedV[], int currV, stack<int> &s, bool flag) 
{
    visitedV[currV] = true;
    
    for(int j=0; j<adj[currV].size(); j++) 
	{
        if(!visitedV[adj[currV][j]]) 
        DFS(adj, visitedV, adj[currV][j], s, flag);
    }
    
    if(flag)
    s.push(currV); 
}


int main() 
{
  int t;
  cin>>t;
  
  while (t--) 
  {
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n);                    // storing graph
    for(int i=0; i<m; i++) 
	{
       int a, b;
       cin>>a>>b;
       a--,b--;
       adj[a].push_back(b); 
    }
    
    
    int count=0;
    stack<int> s;
    bool visitedV[n]; 
    
     
    memset(visitedV, false, sizeof(visitedV));
    for(int i=0; i<n; i++) 
	{
       if(!visitedV[i]) 
       DFS(adj, visitedV, i, s, true);              // flag==true then DFS will store elements in stack
    }
              
			            
    memset(visitedV, false, sizeof(visitedV)); 
    while(!s.empty()) 
	{
       int currI = s.top();
       s.pop();
      
	   if(!visitedV[currI]) 
	   {
          count++;
          DFS(adj, visitedV, currI, s, false);      // flag==false then DFS will not store elements in stack
       }
    }
    
    
    cout<<count<<endl;
  } 
}


/*

1
3 2
1 2
2 3

*/






