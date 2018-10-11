/*
A vector in cpp is a sequential (order is relevant) container of objects all of the same type.
That is, an array that can change its size: they are dynamic arrays but additionally they automatically
resize themselves when elements are inserted or deleted.
See study_ownvectorclass.cpp for custom implementation of a vector-like class.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> myvector {1, 2, 3, 4, 5};

void begin_end()
{
	for (auto it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	
	cout << endl;
}

int main()
{
	begin_end();
	
	// this new style for using begin and end, amounts to the same as:
	for (int i=0; i<myvector.size(); i++)
	{
		cout << ' ' << myvector[i];
	}
	cout << endl;
	
	// to access the last element of a vector, use back():
	myvector.back() = 9;
	begin_end();
	
	cout << "our vector contains "<<myvector.size()<< " elements. ";
	cout << "Its first element is: "<<myvector.front()<<", its last element is: "<<myvector.back()<<endl;
	cout << "But let's delete them all for now."<<endl;
	myvector.clear();
	cout << "Now, its size is"<<myvector.size()<<" and its capacity is: "<<myvector.capacity()<<endl;
	
	// introducing push_back(): the cool feature of vector is: you can add elements, and it will refit its size automatically.
	for (int i=1; i<=5; i++)
	{
		myvector.push_back(i);
	}
	begin_end();
		
	return 0;
}
