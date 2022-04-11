#include <bits/stdc++.h>
using namespace std;
 
 
bool check_ith_bit(int n, int i)
{
   int z = n & (1<<i);
   
   if(z != 0)
   return true;
   else
   return false; 
} 
 
  
int main()                    // 13 = 0000 1101
{ 
	cout << check_ith_bit(13, 3) << endl; 
}






