#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef complex<double> Z;                          // Z(a,b) = a + ib = complexNumberHavingRealPart'a'AndImaginaryPart'b'


/*

Some inbuilt features/functions used here are:
*complex<double> = datatypeTellingMemoryWillStoreComplexNumber'a + ib'
*acos(x) = InverseCosineFunction = returnsAngleAtWhich'cos(0)'Is'x'
*cos(0) = CosineFunction = returnsValueOf'cos(0)'
*sin(0) = SineFunction = returnsValueOf'sin(0)'


CVF = CoefficientValueForm of Polynomial
PVF = PointValueForm of Polynomial
FFT = FastFourierTransform
weHaveDefined Z(a,b) = a + ib, soUsingDatatypeAs'Z'WillMean memoryWillStoreComplexNumber'a + ib'
useLongLongInEveryCodeOfFFT

*/


vector<Z> nthRootOfUnitySeries(ll n)                // calculating all wK values already (correspondingTo'nth'RootOfUnity)   
{
	double pi = acos(-1);                           // pi value 3.14159 ......
	double angle = (2*pi)/n;
	
	 
	vector<Z> w(n);                                 // storing all wK values in vector
	
	for(ll k=0; k<n; k++)                           // omegaValueSeries i.e. all'nth'RootOfUnity = {w0, w1, w2...} = {w[0], w[1], w[2]...}
	w[k] = Z(cos(angle*k), sin(angle*k));
	
	
	return w;
}


vector<Z> converting_CVFtoPVF_usingFFT(vector<Z> &a, vector<Z> &w)  // a[] = {a0, a1, a2 ..... } i.e. coefficientValuesOfPolynomialInCVF
{
	if(a.size() == 1)
	return a;
	
	
	ll n = a.size(); 
	vector<Z> aEven(n/2);                                           // aEven[] = {a0, a2, a4 ..... }  
	vector<Z> aOdd(n/2);                                            // aOdd[] = {a1, a3, a5 ..... }  
	  
	for(ll i=0,j=0;  j<n;  i++,j+=2)
	{   aEven[i] = a[j];
	    aOdd[i] = a[j+1];   }
	
	
	vector<Z> y(n);
	vector<Z> yEven = converting_CVFtoPVF_usingFFT(aEven, w);
	vector<Z> yOdd = converting_CVFtoPVF_usingFFT(aOdd, w); 
	
	for(ll k=0; k<n/2; k++)
	{   y[k] = yEven[k] + w[k]*yOdd[k];
		y[k+n/2] = yEven[k] - w[k]*yOdd[k];   }
	
	
	return y;                             // returning {y0, y1, y2 ..... } i.e. 'yK'ValuesCorrespondingToAll'xK'(where'xK=='nth'RootOfUnity=='wK') 
}


int main()
{ 
    vector<Z> a;                          // storingCoefficientsOfInputPolynomial 
    a.push_back(1);
	a.push_back(2);   
	a.push_back(3);
	a.push_back(4); 
 
    vector<Z> w = nthRootOfUnitySeries(a.size()); 
    vector<Z> y = converting_CVFtoPVF_usingFFT(a, w);
    
    
    cout<<"[ yK = A(xK) = A(wK) ] values:"<<endl;
    for(int i=0; i<y.size(); i++)
    cout<<y[i]<<endl;                     // yK = (a,b) = a + ib     
}


/*
 
a[] = {1, 2, 3, 4}


   ->   InputPolynomial (CVF)
y(x) = 1 + 2*x + 3*x*x + 4*x*x*x

 
   ->  InputPolynomial (PVF)
y(x) = {(w0, 10), (w1, -2-2i), (w2, -2), (w3, -2+2i)}
y(x) = {(1, 10), (i, -2-2i), (-1, -2), (-i, -2+2i)}

*/












