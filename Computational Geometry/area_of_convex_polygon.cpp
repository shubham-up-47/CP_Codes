#include <bits/stdc++.h>
using namespace std;


class Point 
{      public:
    double x, y; 
};
 
 
class Polygon
{        public:
	Point *pointList;
	
	Polygon(int n)
	{   pointList = new Point[n];   }
};


double findPolygonArea(Polygon p, int n) 
{
	double polygonArea = 0;
	 
    for(int i=2; i<n; i++)               // usingGeneralisedFormulaForAreaCalculation = (rp1 X rp2) + (rp2 X rp23) + (rp3 X rp4) + (rp4 X rp5) + ... 
    {                                    // (r=referencePoint & pi=ithPoint)
    	double x1 = p.pointList[i-1].x - p.pointList[0].x;
    	double y1 = p.pointList[i-1].y - p.pointList[0].y;
    	
    	double x2 = p.pointList[i].x - p.pointList[0].x;
    	double y2 = p.pointList[i].y - p.pointList[0].y;
    	
    	double crossProduct = x1*y2 - x2*y1; 
	    polygonArea += crossProduct; 
    }
    
    return abs(polygonArea/2);
}


int main() 
{
    int t;
    cin>>t;
    
	while(t--) 
	{
        int n;
        cin>>n;
        
		Polygon p(n);
        
		for(int i=0; i<n; i++) 
		cin>> p.pointList[i].x >> p.pointList[i].y;
			 
        cout<< (long) findPolygonArea(p,n) <<endl;
    }
}






 



