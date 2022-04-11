#include <bits/stdc++.h>
using namespace std;

                                                   
/*

using DP
valid for directed graph having +ve/0/-ve edge values
considering edge value arr[i][j] = distance between vertex i & j                                        
(weight = value of edge) (distance[i] = distance of vertex 'i' from its parentVertex which is vertex 0 here) 
minDistance between i & j = minDistanceOfVertex'i'FromVertex'0' - minDistanceOfVertex'j'FromVertex'0'     
distance[i][j] = minDistanceBetweenVertex'i'AndVertex'j'

(INT_MAX + integer) willCauseMemoryOverflow thatsWhyWeAreChecking (distance[i][k]!=INT_MAX) & (distance[k][j]!=INT_MAX)                                            

*/                              
                                         
                                                                                                            
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                    // creating adjacency matrix  
	for(int i=0; i<nV; i++)  
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = INT_MAX;	}                  // directed graph
	
	for(int i=0; i<nE; i++)                      // storing weighted graph    
	{  int v1, v2, weight;
	   cin>>v1>>v2>>weight;
	   arr[v1][v2] = weight;  }                 
	
	return arr;
}
      
                           
void findingMinRelativeDistance_usingFloydWarshallAlgo(int **arr, int nV)
{
	int **distance = new int*[nV];
	for(int i=0; i<nV; i++)
	{   distance[i] = new int[nV];
	 
	 	for(int j=0; j<nV; j++)
	 	{   if(i==j)
            distance[i][j] = 0;
            else
		    distance[i][j] = arr[i][j];   }      // initially (minDistanceBetween'i'And'j' = EdgeValue'arr[i][j]')
    }
	                                                                                     
	for(int k=0; k<nV; k++)                      // considering'k'AsIntermediateVertex updatingMinDistanceBetweenAll'i'&'j' 
	{   for(int i=0; i<nV; i++)
    	{	for(int j=0; j<nV; j++)            
	    	{ 
		     	if((distance[i][k]!=INT_MAX) && (distance[k][j]!=INT_MAX) && ((distance[i][k] + distance[k][j]) < distance[i][j]))
		    	distance[i][j] = distance[i][k] + distance[k][j];
		    }
		}
	}
	                                                                            
				                                                                                     
	for(int i=0; i<nV; i++)
	{   for(int j=0; j<nV; j++)
		{
			if(distance[i][j]==INT_MAX)
			cout<<"INF ";                        // INF = infinity
			else
			cout<<distance[i][j]<<" ";
		} 
		cout<<endl;
	} 
}

                                                      
int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);         // storing weighted graph (having -ve, 0, +ve edges)
	
 
	findingMinRelativeDistance_usingFloydWarshallAlgo(arr, 4);
}
 

/*

4 10 
0 0 0
0 1 3
0 3 5
1 0 2
1 1 0
1 3 4
2 1 1
2 2 0
3 2 2
3 3 0

           Adjacency Matrix    
--------------------------------------
|    0        3     INT_MAX     5    |
|    2        0     INT_MAX     4    |
| INT_MAX     1        0     INT_MAX |
| INT_MAX  INT_MAX     2        0    |
--------------------------------------

*/












