#include <bits/stdc++.h>
using namespace std;
 
 
bool checkEven(int n)
{
   int z = n & 1;
   
   if(z != 0)
   return false;
   else
   return true; 
} 
 
  
int main()                    // 13 = 0000 1101
{ 
	cout << checkEven(13) << endl; 
}









