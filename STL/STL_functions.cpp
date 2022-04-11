#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility> 
using namespace std;


struct Interval
{
	int st;
	int et;
};

bool compare(Interval i1, Interval i2)
{	return (i1.st < i2.st);   }


int main()
{
	int arr[] = {2,1,3,5,4,7,6};
	
	sort(arr, arr+3);                                   // sorting in increasing order
	sort(arr+3, arr+7, greater<int>());                 // sorting in decreasing order
	
	for(int i=0; i<7; i++)
	cout<< arr[i] <<" "; 
	cout<< endl;
 
    sort(arr, arr+7);
	cout<< "Index = " << binary_search(arr, arr+7, 2) <<endl;

 // binary search concept is used to calculate lower_bound() & upper_bound()
	cout<< lower_bound(arr, arr+7, 3) - arr <<endl;  // returns iterator pointing to 1st element which has value >= 3  {O(logn)}
	cout<< upper_bound(arr, arr+7, 3) - arr <<endl;  // returns iterator pointing to 1st element which has value > 3   {O(logn)}


	cout<< __gcd(10,6) <<endl; 
	
	cout<< pow(2.2,-5.8) <<endl;
	
	cout<< min(17,43) <<endl;

	int x=10, y=12;
	swap(x,y);
	cout<<x<<" "<<y<<endl;


    Interval brr[] = {{6,4}, {3,4}, {4,6}, {8,13}};       
    sort(brr, brr+4, compare);                          // sorting in increasing order of "st"
	
    for(int i=0; i<4; i++)
    cout<<"("<< brr[i].st <<","<< brr[i].et <<") ";  
}












