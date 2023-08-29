///Dynamic Memory Allocation in C++
#include<iostream>

///Also see PREREQUISITE 2 AND 3
/**
new Operator-
	"pointerVAriable = new dataType;"
	
	new operator returns the address of the memory location.
	Thats why we use pointer type variable. In case of an array, the new
	operator returns the address of the first element of the array.

delete Operator-
	"delete pointerVariable;"
	
	Once we no longer need to use a variable that we have
	declared dynamically , we can deaalocate the memory occupied by the variable.
	For this we use delete operator. It returns th memory to the OS.
	
;
*/
using namespace std;

int main()
{
	///declare an int pointer
	int *pointVar;
	
	///dynamically allocate memory using the new keyword
	pointVar = new int;
	
	///assign value to the allocated memory
	*pointVar = 45;
	
	cout << "The value at pointVar : " << *pointVar << endl;
	
	float *pointVar1 = new float;
	*pointVar1 = 45.5;
	
	cout << "The value at pointVar1 : " << *pointVar1 << endl;
	
	
	return 0;
}