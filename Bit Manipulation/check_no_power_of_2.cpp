#include <bits/stdc++.h>
using namespace std;
 
bool check_no_power_of_2(int n)
{
    int r = n & (n-1);
	
	if(r==0)
	return true;
	else
	return false; 
} 
  
int main()                   
{  
	cout << check_no_power_of_2(16) << endl;
}












