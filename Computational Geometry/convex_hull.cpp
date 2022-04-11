#include <bits/stdc++.h>
using namespace std;


class Point 
{     public:
    int x, y;
};


bool checker(Point A, Point B, Point C)         // (A=pCurr, B=i, C=pNext) checkingThat'B'LiesOnRightOf'AC'OrNot usingCrossProduct (AB X BC)
{
	int x1 = B.x - A.x;                         // AB vector
	int y1 = B.y - A.y;
	
	int x2 = C.x - B.x;                         // BC vector
	int y2 = C.y - B.y; 
	
	return ((x1*y2 - y1*x2) > 0);               // AB X BC crossProduct  
}


vector<Point> createConvexHullOfGivenPoints(Point *pointList, int n)            // creating ConvexHull Polygon of given Points
{
    vector<Point> ConvexHull;
    
    
	int leftmostPointI = 0;
    for(int i=0; i<n; i++)
    {	if(pointList[i].x < pointList[leftmostPointI].x)
        leftmostPointI = i;   }
    
    
    int pCurr = leftmostPointI;                                                 // p=point, I=IndexNo
    while(ConvexHull.size()==0 || pCurr!=leftmostPointI) 
	{ 
        ConvexHull.push_back(pointList[pCurr]);
        
        int pNext = (pCurr+1)%n; 
        for(int i=0; i<n; i++) 
		{ 
		    if(checker(pointList[pCurr], pointList[i], pointList[pNext])) 
			pNext = i;                                                          // update'pNext' if'i'LiesOnRightOf'pCurr-pNext'Line        
        } 
		pCurr = pNext;
    }
        
	return ConvexHull;
}


int main() 
{
    int n;
    cin>>n;
    
	Point *pointList = new Point[n];
    
	for(int i=0; i<n; i++) 
	cin>>pointList[i].x;    
    
	for(int i=0; i<n; i++) 
	cin>>pointList[i].y;   
	        
        
    vector<Point> ConvexHull = createConvexHullOfGivenPoints(pointList, n);
    
    
	for(auto p: ConvexHull) 
    cout<< p.x <<" "<< p.y <<endl;
}









