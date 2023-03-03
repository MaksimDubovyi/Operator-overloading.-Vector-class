#include <iostream>
#include "Vector.h"
#include <ctime>
using namespace std;

	int main()
	{

		int* vect, SizeVect;
		int size = 5, size1 = 3;
		vect = new int[size];
		for (int i = 0; i < size; i++)
		{
			vect[i] = i;
		}
		Vector a1,b1;
		cout <<a1;
		a1.Input();
		b1.Input();
		cout << a1 << endl << b1;
		b1 = a1++;
		cout << b1;
		b1 = ++a1;
		cout << b1;
		cout << a1;
		b1 = a1--;
		cout << b1;
		b1 = --a1;
		cout << b1;
		b1=a1+10;
		cout << b1;
		a1.Clear();
		b1 = a1;
		cout <<b1;
		Vector a2, b2;
		a2.Input();
		b2.Input();
		a2 = a2 + b2;
		cout << a2;
		b2 = b2 - a2;
		cout << b2;
		b2 = b2 + 10+a2;
		cout << a2;
		cout << b2;
		b2 = b2 - 5;
		cout << b2;
		cout << a2;
		b2 += a2;
		cout << b2;
		b2 += 100;
		cout << b2;
		cout << a2;
		b2 -= a2;
		cout << b2;
		cout << a2;
		b2 -= a2;
		cout << b2;
		b2 = b2 - 50;
		cout << b2;
		b2 *= 2;
		cout << b2;
		cout << a2;
		b2=b2*a2;
		cout << b2;
		b2 = a2 * 2;
		cout << b2;
			delete[]vect;

			

	}
