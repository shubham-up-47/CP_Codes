#include <bits/stdc++.h> 
using namespace std;


/*

Grundy(n) = 0

Grundy(n) = Mex{Grundy(n/2), Grundy(n/3), Grundy(n/6)}    
 
*/


int calculateMex(unordered_set<int> s) 
{
    int Mex = 0;
    
    while(s.find(Mex) != s.end())
    Mex++;
    
	return Mex;
}


int calculate_nthGrundyNo(int *Grundy, int n) 
{
    if(n==0)
    return 0;
    else if(Grundy[n] != -1)
    return Grundy[n];


    unordered_set<int> s;
    s.insert(calculate_nthGrundyNo(Grundy, n/2));
    s.insert(calculate_nthGrundyNo(Grundy, n/3));
    s.insert(calculate_nthGrundyNo(Grundy, n/6));
    Grundy[n] = calculateMex(s);
    
    
    return Grundy[n];
}


int main() 
{
    int Grundy[1000001];
    memset(Grundy,-1,sizeof(Grundy));
   
    int t;
    cin>>t;
   
    while (t--) 
	{
        int n;
        cin>>n;
        cout<< calculate_nthGrundyNo(Grundy,n) <<endl;       // finding nth Grundy No (corresponding to current game) using Memorization
    }
}












