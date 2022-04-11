#include <bits/stdc++.h>
using namespace std;


// P1 & P2 are two permutations of numbers [1,n]


void DFS(vector<vector<int>> &adj, int currV, bool visitedV[], vector<int> &cc)
{
   visitedV[currV] = true;
   cc.push_back(currV);

   for (int i=0; i<adj[currV].size(); i++)
   {
       if(visitedV[adj[currV][i]] == 0)
       DFS(adj, adj[currV][i], visitedV, cc);
   }
}


bool is_P1_permutableTo_P2(vector<vector<int>> &adj, int n, vector<int> &P1, vector<int> &P2)
{
   bool visitedV[n] = {0}; 

   for(int i=0; i<n; i++)
   {
       vector<int> cc;                           // cc = current ConnectedComponent
     
	   if(visitedV[i] == 0)
       {   DFS(adj, i, visitedV, cc);
           
           vector<int> temp1, temp2; 
           for(int i=0; i<cc.size(); i++)
           {   temp1.push_back(P1[cc[i]]);
               temp2.push_back(P2[cc[i]]);   }
 
           sort(temp1.begin(), temp1.end());
           sort(temp2.begin(), temp2.end());
 
           if(temp1 != temp2)
           return 0;   }    
	}
        
	return 1;
}


int main() 
{
    int t;
    cin>>t;
     
	while (t--)
    {
       int n, m;	
       cin>>n>>m;

       vector<int> P1(n), P2(n); 
       for(int i=0; i<n; i++)
       cin>>P1[i]; 
       for(int i=0; i<n; i++)
       cin>>P2[i];
       
       vector<vector<int>> adj(n); 
       for(int i=0; i<m; i++)                     // making graph from index no pairs of P1, between which permutation is allowed
       {   int a, b;
           cin>>a>>b;
           a--,b--;
           adj[a].push_back(b);
           adj[b].push_back(a);   }
       
       if(is_P1_permutableTo_P2(adj, n, P1, P2))
       cout<<"YES"<<endl;
       else
       cout<<"NO"<<endl;
    }
}







