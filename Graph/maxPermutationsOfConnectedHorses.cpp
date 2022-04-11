#include <bits/stdc++.h> 
using namespace std;


int mod = 1e9 + 7;
#define ll long long int


ll DFS(int **Board, int i, int j, int n, int m)            // consider all eight L shape moves
{
  ll count = 1;
  Board[i][j] = 0;
  

  if(i-2>=1 && j+1<=m && Board[i-2][j+1] == 1)
  count += DFS(Board, i-2, j+1, n, m);
  
  if(i-1>=1 && j+2<=m && Board[i-1][j+2] == 1)
  count += DFS(Board, i-1, j+2, n, m);
  
  if(i+1<=n && j+2<=m && Board[i+1][j+2] == 1)
  count += DFS(Board, i+1, j+2, n, m);
    
  if(i+2<=n && j+1<=m && Board[i+2][j+1] == 1)
  count += DFS(Board, i+2, j+1, n, m);
    
  if (i-2>=1 && j-1>=1 && Board[i-2][j-1] == 1)
  count += DFS(Board, i-2, j-1, n, m);
    
  if(i-1>=1 && j-2>=1 && Board[i-1][j-2] == 1)
  count += DFS(Board, i-1, j-2, n, m);
    
  if(i+1<=n && j-2>=1 && Board[i+1][j-2] == 1)
  count += DFS(Board, i+1, j-2, n, m);
    
  if(i+2<=n && j-1>=1 && Board[i+2][j-1] == 1)
  count += DFS(Board, i+2, j-1, n, m);
    
    
  return count;
}


int maxPermutationsOfConnectedHorses(int **Board, int n, int m, ll fact[]) 
{
  ll ans = 1;
  
  for(int i=1; i<=n; i++) 
  { for(int j=1; j<=m; j++) 
	{
        if(Board[i][j] == 1) 
		{  int count = DFS(Board, i, j, n, m);
           ans = (ans*fact[count]) % mod;   }
    }
  }
  
  return ans;
}


int main() 
{
  int t;
  cin>>t;
  
  ll fact[100001];
  fact[0] = 1;
  for(int i=1; i<100001; i++)
  fact[i] = (fact[i-1]*i) % mod;
  
  
  while(t--) 
  {
    int n, m, q;
    cin>>n>>m>>q;
    
    int **Board = new int*[n+1];
    
    for(int i=1; i<=n; i++) 
	{   Board[i] = new int[m+1];
	
        for(int j=1; j<=m; j++) 
        Board[i][j] = 0;   }
    
    for(int i=0; i<q; i++) 
	{   int a, b;
        cin>>a>>b;
        Board[a][b] = 1;   }
    
    cout << maxPermutationsOfConnectedHorses(Board, n, m, fact) << endl; 
  }
}



