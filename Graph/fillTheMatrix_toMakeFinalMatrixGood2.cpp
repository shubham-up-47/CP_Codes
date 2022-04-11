#include<bits/stdc++.h>
using namespace std;


/*

Disjoint Set Algo / Union Find Algo
*considering index no of array elements {0,1,2...n-1} as vertices 
*dividing all vertices into some CCs, after merging sameValueIndexNoVerticesIntoOneCC
*ds[i] = index no of parent vertex (if'i'isNonRootNodeOfItsCC)
*ds[i] = -ve of no of vertices in its CC (if'i'isRootNodeOfItsCC)

ds = disjoint set
CC = Connected Component

*/


int ds[1000001];


int findRootParent(int i)
{
    if(ds[i] < 0) 
    return i;
    
    return findRootParent(ds[i]);
}


void mergeCCs(int i, int j)       // merging smaller CC with larger CC
{
    int iN=abs(ds[i]), jN=abs(ds[j]);
    
    if(iN > jN) 
    {   ds[i] = -(iN+jN);
        ds[j] = i;   }
    else
    {   ds[j] = -(iN+jN);
        ds[i] = j;   }
}


int main()
{
    int t;
    cin>>t;
    
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        memset(ds, -1, sizeof(ds)); 
        vector<pair<int,int>> v;     // stores CC pairs betweenWhichValueDifferenceShouldBe'1'  
        
        while(m--)
        {
            int i,j,c;
            cin>>i>>j>> c;
            --i; --j;
            
            int iRP = findRootParent(i);
            int jRP = findRootParent(j);
            
            if(c==1)                 // input'c==1' soDifferenceBetweenCC'iRP'andCC'jRP' shouldBe'1' 
            v.push_back({iRP, jRP});
            else if(c==0 && iRP==jRP) 
            continue; 
            else if(c==0 && iRP!=jRP) 
            mergeCCs(iRP,jRP);       // input'c==0' soMergeCC'iRP'andCC'jRP' ifTheyAreDifferent
        }
        
        
        int flag = 1;
        for(auto CC : v)
        {
            int i=CC.first, j=CC.second;
        
            int iRP = findRootParent(i);
            int jRP = findRootParent(j);
  
            if(iRP == jRP)           // ifAfterAllInput'c==0' theseBelongsToSameCC thenContradiction
            {   flag = 0;
                break;   }
        }
        
        if(flag==1)
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    } 
}






