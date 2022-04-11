#include <bits/stdc++.h> 
using namespace std;


/*

m[i][j] >= 0
m[i][i] = 0
m[i][j] = m[j][i]  


To check CCs are Bipartite or not
=>check CCs can be divided in two sets (0 & 1) or not
=>check all the vertices can be divided in two sets (0 & 1) or not [whereVerticesOfSameCC willBeInSameSet]  
=>varticesHaving valueDifference==0 shouldBeInSameSet
=>varticesHaving valueDifference==1 shouldBeInDifferentSet

*/


bool isBipartiteUtil(vector<vector<int>> &adj, int startV, int *setNo, map<pair<int,int>,int> &h)                     
{
    setNo[startV] = 1;
    
    queue<int> pendingV;
    pendingV.push(startV);
     
    while(!pendingV.empty())                                // (setNo[startV] = 1) so (setNo[currV] = 0/1)                       
	{ 
        int currV = pendingV.front();
        pendingV.pop();
      
        for(int i=0; i<adj[currV].size(); i++)                          // currentVertexHasSomeNeighbourVertices
	    {
            int neighbourV = adj[currV][i]; 
            int d = h[{min(currV,neighbourV),max(currV,neighbourV)}];   // r = valueDifferenceBetweenCurrentVertexAndNeighbourVertex
        
            if(d==0)                                                    // valueDifference==0 soBothVerticesShouldBeInSameSet (setNo[currV])               
	        {    
		        if(setNo[neighbourV]==-1)                               // neighbourV is unhandled
                {  setNo[neighbourV] = setNo[currV];
                   pendingV.push(neighbourV);  }
                else if(setNo[currV]!=setNo[neighbourV]) 
                return false;
	        }
	        else if(d==1)                                               // valueDifference==1 soBothVerticesShouldBeInDifferentSet (1-setNo[currV])
	        {
	            if(setNo[neighbourV]==-1)                               // neighbourV is unhandled
                {  setNo[neighbourV] = 1-setNo[currV];
                   pendingV.push(neighbourV);  }
	            else if(setNo[currV]==setNo[neighbourV]) 
	            return false;
	        } 
        }
    }
      
	return true;
}


bool isBipartiteGraph(vector<vector<int>> &adj, int n, map<pair<int,int>,int> &h) 
{
    int setNo[n]; 
    memset(setNo, -1, sizeof(setNo)); 
    
	for(int i=0; i<n; i++)                                  // currentVertex isUnhandled & haveSomeNeighbourVertices      
    {
		if(setNo[i]==-1 && adj[i].size()>=1 && isBipartiteUtil(adj,i,setNo,h)==false)
		return false;
    }
    
	return true;
}


int main()                  
{
    int t;
    cin>>t;
            
	while(t--) 
	{
        int n, q;
        cin>>n>>q;
         
        bool flag = true;   
        vector<vector<int>> adj(n);
        map<pair<int,int>,int> h;                           // mapping of Coordinte(i,j) v/s BinaryAt(i,j) using map                               
           
		while(q--)                                             
        {
            int i,j,c;                                       
            cin>>i>>j>>c;
            i--,j--;
            adj[i].push_back(j);                            // creating undirected graph from input vertices 
            adj[j].push_back(i);
            
            pair<int,int> t = {min(i,j),max(i,j)};        
           
            if(h.count(t)>0 && h[t]!=c)                     // verifying m[i][j] == m[j][i], ifNotThenReturnFalse 
            flag = false; 
            else                                            // storing all m[i][j]=c as h[{x,y}]=c (where c=0/1, x=min(i,j), y=max(i,j))      
			h[t] = c;
        }
                
		if(flag==false || isBipartiteGraph(adj,n,h)==false)
		cout<<"no"<<endl;  
        else
        cout<<"yes"<<endl;
    }
}
 







