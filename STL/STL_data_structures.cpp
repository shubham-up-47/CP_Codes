#include<iostream>
#include<vector>             // header file for vector
#include<string>             // header file for string
#include<utility>            // header file for pair        
#include<set>                // header file for ordered set
#include<unordered_map>      // header file for unordered map
#include <list>              // header file for list
using namespace std;

 
int main()
{ 
        //	Vector
        
	vector<int> v1;
	vector<int> v2(5, -1);                       // initialized vector 
	vector<int> v3(5);                           // vector of size=5 i.e. arr[5]

	for(int i=0; i<5; i++)                       // inserting
	v1.push_back(i+1);                          
	
	vector<int>::iterator it;

	for(it=v1.begin(); it!=v1.end(); it++)      // iterating
	cout<<*it<<" ";
	cout<<endl;
	
 
        //	String
        
	string s1 = "Parikh";
	string s2(s1,2,4);                          // initialized string (storing s1 substring whose startingIndex=2 & size=4) 
	string s3(s1);                              // string same as s1  
	cout<<s1<<endl;
	cout<<s2<<endl;

	string s4 = s1.substr(2,4);                 // initialized string (storing s1 substring whose startingIndex=2 & size=4) 
	cout<<s4<<endl;

	if(s2.compare(s4) == 0)                     // comparing
	cout<< s2 <<" is equal to " << s4 <<endl;
	else
	cout<< s2 <<" is not equal to " << s4 <<endl;


        //    Pair

	pair<int,char> p1;
	p1 = make_pair(2,'b');
	pair<int,char> p2(1,'a');                   // initialized pair
	
	cout<<p1.first << " " << p1.second<<endl;
	cout<<p2.first << " " << p2.second<<endl;


	    //    Set

	set<int> s;
	int arr[] = {1,2,3,4,5,6,5};

	for(int i=0; i<7; i++)                      // inserting
	s.insert(arr[i]);                           

	set<int>::iterator t;

	for(t=s.begin(); t!=s.end(); t++)       // iterating
	cout<<*t<<" ";
	cout<<endl;

	if(s.find(7) != s.end())                   // searching
	cout<<"Element found"<<endl;
	else
	cout<<"Element not found"<<endl;

 
	      //    Map

	unordered_map<int,int> m;
	int brr[] = {1,2,3,4,5,6,5};

	for(int i=0; i<7; i++)                          // inserting
	m[brr[i]]++;                                     // storing frequency              

	unordered_map<int,int>::iterator iter;
	
	for(iter=m.begin(); iter!=m.end(); iter++)           // iterating
	cout<<"("<<iter->first << "," << iter->second<<") "; 
	cout<<endl;
	
	m.erase(1);                                   // deleting 
	
	for(iter=m.begin(); iter!=m.end(); iter++)           // searching
	cout<<"("<<iter->first << "," << iter->second<<") ";
	cout<<endl;
	
	
	       //    List
	 
    list<int> lrr;
   
    for(int i=0; i<10; i++)
    lrr.push_back(i*2);
  
    list<int>::iterator itr;
    for(itr=lrr.begin(); itr!=lrr.end(); itr++)
    cout << *itr << " ";
  
    lrr.pop_front();
    lrr.pop_back();
    cout << "\n" << lrr.front() << " " << lrr.back();
   
    lrr.reverse();
    lrr.sort(); 
}













