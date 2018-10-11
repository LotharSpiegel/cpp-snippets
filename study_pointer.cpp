/*
Dynamic memory allocation.
First, there is static memory: here global memory is stored. 
It is set at compile-time and does not change while the program is running.

Second, there is stack memory. Here, local variables are stored.

Third, free store memory.

new ... allocate memory
delete de-allocate memory
Both functions work with pointers. See study_pointer.cpp

To access free store memory, we need pointers.
*/


/* A pointer stores the address of a memory location.
Any memory location in a computer has an address. You can access it through the
& operator:
The address is a hexadecimal (base-16) number.
*/

#include <iostream>
using namespace std;

void pointer_basics()
{
	double x = 3.14;
	cout << "x is stored at address " << &x << endl;
	
	// let us declare a pointer that stores the address of a double:
	double* my_pointer;
	
	// we assign it the address of our double variable x:
	my_pointer = &x; // note the & operator in front of x: you can read it as: 'the address of x'
	cout << "x is stored at address " << my_pointer << endl;
	
	// given a pointer, we can access the value of the variable it points to via the * operator:
	cout << "x has the value " << *my_pointer << endl;
	//so, *my_pointer is the same as the object x
	
	
	int a = 5;
	int *p = &a; // pointer p points to a 
	int* q = p; // pointer q points to the same as p
}

void array_basics()
{
	/* in the following statement we allocate 5 contiguous int's worth of free store memory.
	The expression new int[5] returns a pointer to the first int.
	So basically, a static array like int[5] really is nothing else than contiguous memory.
	5 int's which are sitting next to each other in memory.
	*/
	int* array = new int[5];
	
	for (int i=0; i<5; i++)
	{
		cout << "array["<<i<<"] is stored at address " << array+i << endl;
	}
	/* Internally, array is the address of the integer which can be accessed via array[0]
	the address of array[1] equals array+1, and so on
	array[i] is equivalent to *(array+i)
	*/
	
	cout << "array[0] has the value " << array[0];
	// at the moment, this will give out some randomly looking number
	
	/* after we don't need it anymore, we have to de-allocate the memory used by our array:
	*/
	delete[] arr;
}

int main()
{
	pointer_basics();
	array_basics();
	
	return 0;
}

