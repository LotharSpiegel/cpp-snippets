/*
We will create our own vector-like class.
See study_vector.cpp
*/

/*
See study_pointer.cpp for basics about pointers and memory allocation.
*/ 

#include <iostream>
#include <stdexcept>

using namespace std;

int INIT_CAPACITY = 10;

class myvector {
	double* arr;
	int _capacity; // size of underlying array  arr
	int _size; // the size
	
	void increase_capacity(int new_cap) {
		if (new_cap <= _capacity) return; // still enough 
		
		cout << "increase old capacity of "<<_capacity<<" to new capacity of "<<new_cap<<endl;
		
		double* new_arr = new double[new_cap];
		
		// copy old array in new one:
		for (int i=0; i<_capacity; ++i) {
			new_arr[i] = arr[i];
		}
		_capacity = new_cap;
		
		delete[] arr;
		arr = new_arr;
	}
	
public:
	// the constructor:
	myvector(): _capacity(INIT_CAPACITY), _size(0) {
		arr = new double[_capacity];
	}
	
	// the destructor:
	~myvector() {
		delete[] arr; // de-allocate the memory used
		cout << "object is destructed\n"; // just to learn when destructor is called ;)
	}
	
	int size() const {
		return _size;
	}
	
	int capacity() const {
		return _capacity;
	}
	
	void push_back(double x) {
		if (_size >= _capacity) // we need more space!
			increase_capacity(2 * _capacity); // let's double our space
		arr[_size] = x;
		++_size;
	}
	
	void insert(double x, int pos) {
		if (pos < 0 || pos > _size) throw out_of_range("vector range error");
		
		push_back(0); // increase the size of the vector by 1 
		
		// move elements from pos to end of vector up one position
		// a nice use case for a for loop starting at the (right) end
		
		for (int i=_size-1; i>pos; --i) {
			arr[i] = arr[i-1];
		}
		
		// insert new element:
		arr[pos] = x;
	}
	
	/* A get operator: 
	operator[] must return a reference to a double (instead of just a
   regular double) in order to work properly with assignment, e.g. vec[3] =3.14;*/
   double& operator[](int pos) {
		if (pos < 0 || pos >= _size) throw out_of_range("vector range error");
		return arr[pos];
   }
	
	/*const double& operator[](int pos) {
		if (pos < 0 || pos >= _size) throw out_of_range("vector range error");
		return arr[pos];
	}*/
	
	// the & is necessary: the statement v[5] now returns the double at pos 5 of the array
	// without & it would just return the value the double is containing. also assignment is nonly possible like this.
	
	void print() {
		for (int i=0; i<_size; ++i) {
			cout << ' ' << arr[i];
		}
		cout << endl;
	}
	
	// how to direct to cout?
};

#include <random>

int main()
{
	myvector vec = myvector();
	vec.print();

	double lower_bound = 0;
	double upper_bound = 10000;	
	uniform_real_distribution<double> unif(lower_bound, upper_bound);
	default_random_engine re;
	double random_double;
	for (int i=0; i<15; ++i) {
		random_double = unif(re);
		vec.push_back(random_double);
	}
	
	vec.print();
	
	return 0;
}

