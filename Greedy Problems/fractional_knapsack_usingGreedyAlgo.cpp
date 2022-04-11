#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


class Item
{     public:
	int weight;
	int value;
};


bool compare(Item a, Item b)
{
	double value1 = ((double)a.value)/(a.weight);
	double value2 = ((double)b.value)/(b.weight);	
	
	return (value1 > value2);
}


double fractionalKnapsack(Item *arr, int n, int wMax)
{
	sort(arr, arr+n, compare);
	
	int wCurr = 0;
	double vMax = 0;
	
	for(int i=0; i<n; i++)
	{
		if(wCurr+arr[i].weight <= wMax)
		{   wCurr += arr[i].weight;
		    vMax += arr[i].value;   }
		else
		{   int weightTemp = wMax - wCurr; 
		    vMax += (arr[i].value * ((double)weightTemp/arr[i].weight));    // Value*Fraction (Fraction = FractionalItemWeight/TotalItemWeight)
			break;   } 
	}
	
	return vMax;
}


int main()
{
    int n=3, wMax=70;
	
	Item arr[] = {{20,60}, {15,70}, {40,80}};
	cout << "Maximum Value is: "<< fractionalKnapsack(arr, n, wMax) << endl;                
}









