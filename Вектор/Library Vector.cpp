#include <iostream>
#include <windows.h>
#include "Vector.h"
#include <ctime>
using namespace std;

void RussianMessage(const char* s)
{
	char* buf = new char[strlen(s) + 1];
	CharToOemA(s, buf);
	cout << buf;
	delete[] buf;
}
istream& operator>>(istream& cin, Vector& v)
{
	RussianMessage("\nВызвался istream& operator >> \n");

		for (int i = 0; i < v.GetSize(); i++)
		{

			cin >> v.vect[i];
		}

	return cin;
}
ostream& operator<<(ostream& cout, Vector& v)
{
	RussianMessage("\nВызвался ostream& operator <<\n");
	for (int i = 0; i < v.GetSize(); i++)
	{
		cout << v.vect[i] << " ";
		
	}
	return cout;
}
Vector::Vector(const int* ptr, int siz) // Конструктор, позволяющий проинициализировать вектор с помощью существующего массива
{
	RussianMessage("\nКонструктор, позволяющий проинициализировать вектор с помощью существующего массива\n");
	size = siz;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = ptr[i];
	}

}
int Vector::GetSize() const // Функция возвращает размерность вектора
{
	RussianMessage("\n Функция возвращает размерность вектора\n");
	int i;
	for (i = 0; i < size; i++)
	{
	}
	return i;

}
void Vector::Print() // Вывод на экран
{
	RussianMessage("\n Вывод на экран\n");
	for (int i = 0; i < size; i++)
	{
		cout << vect[i] <<"  ";
	}
	cout  << endl;
}
void Vector::Input() // Заполнение вектора
{
	RussianMessage("\n  Заполнение вектора\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = i;
	}
}
void Vector::Clear() // Очистка вектора
{
	RussianMessage("\n Очистка вектора\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = 0;
	}
}
bool Vector:: IsEmpty() const // Возвращает истину, если вектор пустой
{
	RussianMessage("\nФункция возвращает истину, если вектор пустой\n");
	int z = 0;
	for (int i = 0; i < size; i++)
	{
		z += vect[i];
	}
	if (z == 0)
	{
		return true;
	}
	else if (z != 0)
	{
		return false;
	}
}
void Vector::Add(const int& item) // Добавление элемента в вектор
{
	RussianMessage("\nФункция добавление элемента в вектор\n");
	size += 1;
	int* vect1, a = 0;
	vect1 = new int[size];
	vect1[0] = item;
	for (int i = 1; i < size; i++)
	{
		vect1[i] = vect[a];
		a++;
	}
	delete[]vect;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect1[i];
	}
	delete[]vect1;
}
void Vector::Insert(int index, const int& item) // Вставка элементов в вектор по заданному индексу
{
	RussianMessage("\n Вставка элементов в вектор по заданному индексу\n");
	int* p = new int[++size];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == i)
		{
			k = 1;
			p[i] = item;
		}
		p[i + k] = vect[i];
	}
	
	delete[]vect;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = p[i];
	}
	delete[]p;

}
void Vector::Remove(int index) // Удаление элемента из вектора по заданному индексу
{
	RussianMessage("\nУдаление элемента из вектора по заданному индексу\n");
	int* p = new int[size--];
	int k = 0;
	for (int i = 0; i < size; i++)
	{

		if (index == i)
			k = 1;
		p[i] = vect[i + k];
	}
	
	delete[]vect;
	 vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = p[i];
	}
	delete[]p;
}
Vector::Vector(const Vector& v)// Конструктор копирования
{
	RussianMessage("\nВызвался Конструктор копирования\n");
	size = v.size;
	this->vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = v.vect[i];
		
	}
	
	
}
Vector ::Vector(int siz) // Конструктор, позволяющий задавать размерность вектора
{
	RussianMessage("\nКонструктор, позволяющий задавать размерность вектора\n");
	size = siz;
	vect = new int[size];
}
Vector::Vector()   // Конструктор по умолчанию
{
	RussianMessage("\nКонструктор по умолчанию\n");
	size = 5;
	vect = new int[size];
}


Vector Vector:: operator ++ (int v) // Увеличение всех компонент вектора на// единицу (постфикс)
{
	RussianMessage("\nУвеличение всех компонент вектора на ++int \n");
	Vector a=*this;


	for (int i = 0; i < size; i++)
	{
		vect[i]++;
	}
	return a;
}
Vector::Vector(Vector&& v)
{
	RussianMessage("\nКонструктор переноса \n");
	size = v.size;
	vect = v.vect;
	v.vect = nullptr;

	
}
Vector& Vector :: operator ++ () // Увеличение всех компонент вектора на  // единицу (префикс)
{
	RussianMessage("\nУвеличение всех компонент вектора на int++ \n");
	for (int i = 0; i < size; i++)
	{
		vect[i]++;
	}
	return *this;
}
Vector& Vector::operator -- () // Уменьшение всех компонент вектора на //// единицу (префикс)
{
	RussianMessage("\nУменьшение всех компонент вектора на единицу (префикс) \n");
	for (int i = 0; i < size; i++)
	{
		vect[i]--;
	}
	return *this;


}
Vector Vector::operator -- (int k) // Уменьшение всех компонент вектора на//// единицу (постфикс)
{
	RussianMessage("\nУменьшение всех компонент вектора на  единицу (постфикс) \n");
	Vector a = *this;


	for (int i = 0; i < size; i++)
	{
		vect[i]--;
	}
	return a;

}
int& Vector::  operator [] (int index)// Перегруженный оператор индексации
{
	RussianMessage("\nПерегруженный оператор индексации \n");
	if (index < 0 || index >= size)
		return vect[0];
	return vect[index];
}
Vector& Vector:: operator = (const Vector& v) // Перегруженный оператор// присваивания с копированием
{
	RussianMessage("\n Перегруженный оператор присваивания с копированием \n");
	if (this == &v)
		return *this;
	delete[] this->vect;
	size = v.size;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = v.vect[i];

	}
}
Vector& Vector::operator=(Vector&& v)
{
	RussianMessage("\n Перегруженный оператор присваивания с переносом \n");
	if (this == &v)
		return *this;
	delete []vect;
	
	size = v.size;
	vect = v.vect;
	v.vect = nullptr;
	return *this;
}




Vector Vector::operator + (const Vector& v)
{
	RussianMessage("\n Сложение двух векторов \n");
	if(size>=v.size)
	for (int i = 0; i < v.size; i++)
	{
		vect[i]+=v.vect[i];
	}
	else if (size <= v.size)
		for (int i = 0; i < size; i++)
		{
				vect[i] += v.vect[i];
		}
	return *this;

}
Vector Vector:: operator + (int n) 
{
	RussianMessage("\n Сложение вектора с числом (каждый  компонент вектора складывается с числом) \n");
	for (int i = 0; i < size; i++)
	{
		vect[i] += n;
	}
	return *this;

}
Vector& Vector:: operator += (const Vector& v)
{
	RussianMessage("\n ерегруженный оператор +=  для сложения двух векторов \n");
	for (int i = 0; i < size; i++)
	{
		if (i >= v.size)
			vect[i] = vect[i];
		else
			vect[i] = vect[i] + v.vect[i];
	}
	return *this;
}

Vector& Vector ::operator += (int n)
{
	RussianMessage("\n ерегруженный оператор +=  для сложения вектора и числа \n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] + n;
	}
	return *this;
}

Vector Vector::operator-(const Vector& v)
{
	RussianMessage("\n Вычитание двух векторов\n");
	if (size > v.size)
		for (int i = 0; i < v.size; i++)
		{
			vect[i] -= v.vect[i];
		}
	else if (size < v.size)
		for (int i = 0; i < size; i++)
		{
			vect[i] -= v.vect[i];
		}
	return *this;
}

Vector Vector::operator-(int n)
{
	RussianMessage("\n Вычитание числа из вектора\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] - n;
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
	RussianMessage("\n Перегруженный оператор -= для вычитания двух векторов\n");
	for (int i = 0; i < size; i++)
	{
		if (i >= v.size)
			vect[i] = vect[i];
		else
		vect[i] = vect[i] - v.vect[i];
	}
	return *this;
}

Vector Vector::operator*(const Vector& v)
{
	RussianMessage("\n Умножение векторов\n");
	if (size >= v.size)
		for (int i = 0; i < v.size; i++)
		{
			vect[i]=vect[i] * v.vect[i];
		}
	else if (size <= v.size)
		for (int i = 0; i < size; i++)
		{
			vect[i] =vect[i] * v.vect[i];
		}
	return *this;
}

Vector Vector::operator*(int n)
{
	RussianMessage("\n Умножение вектора на число\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] * n;
	}
	return *this;
}

Vector& Vector::operator*=(int n)
{
	RussianMessage("\n Перегруженный оператор *= для  умножения вектора на число\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] * n;
	}
	return *this;
}

void Vector:: SetSize(int d)
{
	size = d;
}
void Vector:: SetVect(int index, int numb)
{

	vect[index] = numb;
}