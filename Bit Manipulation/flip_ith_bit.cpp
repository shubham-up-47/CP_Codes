#include <bits/stdc++.h>
using namespace std;
 
 
int flip_ith_bit(int n, int i)
{
   int z = (1<<i);
   int r = n ^ z;
 
   return r; 
} 
  
 
int main()                    // 13 = 0000 1101
{ 
	cout << flip_ith_bit(13, 1) << endl;  
}






