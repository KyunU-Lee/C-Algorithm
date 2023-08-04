#include <iostream>
#include "func.h"
using namespace std;

int main()
{
	int a = 10;
	int b = 20;

	cout << "a : " << a << "b: " << b << "\n";
	swap(a, b);
	cout << "a : " << a << "b: " << b << "\n";
	ptrswap(&a, &b);
	cout << "a : " << a << "b: " << b << "\n";


	cout << "fect(10) : " << fect(10) << endl;

	cout << "facttail(10, 10) : " << facttail(4, 1) << endl;




	return 0;
}