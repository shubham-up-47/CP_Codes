#include <bits/stdc++.h>
using namespace std;
                           
                         
/* 
 
Considering (arr[i].weight) = distance between vertex (arr[i].startV) & (arr[i].endV)                          
distance[i] = minDistanceOfVertex'i'FromVertex'0'

Iteration0: distance[i]Of(0'sNeighbours)WillBeUpdated,  
Iteration1: distance[i]Of(0'sNeighbours + 0'sNextNeighbours)WillBeUpdated 
Iteration2: distance[i]Of(0'sNeighbours + 0'sNextNeighbours + 0'sNextToNextNeighbours)WillBeUpdated 
Iteration3: distance[i]Of(0'sNeighbours + 0'sNextNeighbours + 0'sNextToNextNeighbours + 0'sNextToNextToNextNeighbours)WillBeUpdated 
    .                           .
    .                           .
	.                           .
    .                           .
    .                           .
    
(INT_MAX + integer) willCauseMemoryOverflow thatsWhyWeAreChecking (distance[v1]!=INT_MAX)
ifGraphContainsNegativeEdgeCycle thenShortestPathFindingAlgorithmsWillNotWork         
ifAfterRunningOneMoreIterationOf'j' distance[i]OfAnyVertexVaries thenItMeansGraphContainsNegativeEdgeCycle [MethodToDetectNegativeEdgeCycle]      
    
*/                               
                        
                                
class Edge                                                    // node of EdgeList  
{     public:
	int startV;                                               // starting vertex of edge (v1)     
	int endV;                                                 // ending vertex of edge (v2)        
	int weight;                                               // weight of edge                  
};


void findingMinDistance_usingBellmanFordAlgo(int nV, int nE, Edge *arr)
{                                                             // calculating minDistance of eachVertex from vertex 0  
	int *distance = new int[nV];                            
	for(int i=0; i<nV; i++)                             
	distance[i] = INT_MAX;                                    // initially distance of vertex 'i' from vertex 0  is oo 
	 
	 
	distance[0] = 0;   
	
	for(int i=0; i<nV; i++)                                   // In'i'thIterationOnAll'nE'Edges, pathUsingAtmost'i'EdgesWillBeConsidered
	{
		for(int j=0; j<nE; j++)                             
		{
			int v1 = arr[j].startV;
			int v2 = arr[j].endV;
			int w = arr[j].weight;
			
			if((distance[v1]!=INT_MAX) && ((distance[v1] + w) < distance[v2]))
			distance[v2] = distance[v1] + w;                 
		}
	}
	 
	for(int i=0; i<nV; i++)
    cout << distance[i] << endl; 
}

 
int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	
	Edge *arr = new Edge[nE]; 
	for(int i=0; i<nE; i++)
	cin >> arr[i].startV >> arr[i].endV >> arr[i].weight;   
	 
	 
	findingMinDistance_usingBellmanFordAlgo(nV, nE, arr);     // finding minDistance of eachVertex from vertex 0 
}


/*

4 5
0 1 -3
0 2 4
1 3 2
1 2 1
2 3 0

(Source Vertex = 0)

          -3
       0------1
       |     /|
       |  1/  | 
      4|  /   |2
       |/     |
       2------3   
          0

*/












