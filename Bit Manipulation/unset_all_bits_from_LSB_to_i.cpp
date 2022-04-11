#include <bits/stdc++.h>
using namespace std;
 
 
int unset_all_bits_from_LSB_to_i(int n, int i)
{
   int z = ~((1<<(i+1)) - 1);
   int r = n & z;
 
   return r; 
} 
  
 
int main()                    // 29 = 0001 1101
{ 
	cout << unset_all_bits_from_LSB_to_i(29, 2) << endl;  
}












