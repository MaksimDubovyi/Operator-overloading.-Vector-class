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
	RussianMessage("\n�������� istream& operator >> \n");

		for (int i = 0; i < v.GetSize(); i++)
		{

			cin >> v.vect[i];
		}

	return cin;
}
ostream& operator<<(ostream& cout, Vector& v)
{
	RussianMessage("\n�������� ostream& operator <<\n");
	for (int i = 0; i < v.GetSize(); i++)
	{
		cout << v.vect[i] << " ";
		
	}
	return cout;
}
Vector::Vector(const int* ptr, int siz) // �����������, ����������� ������������������� ������ � ������� ������������� �������
{
	RussianMessage("\n�����������, ����������� ������������������� ������ � ������� ������������� �������\n");
	size = siz;
	vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = ptr[i];
	}

}
int Vector::GetSize() const // ������� ���������� ����������� �������
{
	RussianMessage("\n ������� ���������� ����������� �������\n");
	int i;
	for (i = 0; i < size; i++)
	{
	}
	return i;

}
void Vector::Print() // ����� �� �����
{
	RussianMessage("\n ����� �� �����\n");
	for (int i = 0; i < size; i++)
	{
		cout << vect[i] <<"  ";
	}
	cout  << endl;
}
void Vector::Input() // ���������� �������
{
	RussianMessage("\n  ���������� �������\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = i;
	}
}
void Vector::Clear() // ������� �������
{
	RussianMessage("\n ������� �������\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = 0;
	}
}
bool Vector:: IsEmpty() const // ���������� ������, ���� ������ ������
{
	RussianMessage("\n������� ���������� ������, ���� ������ ������\n");
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
void Vector::Add(const int& item) // ���������� �������� � ������
{
	RussianMessage("\n������� ���������� �������� � ������\n");
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
void Vector::Insert(int index, const int& item) // ������� ��������� � ������ �� ��������� �������
{
	RussianMessage("\n ������� ��������� � ������ �� ��������� �������\n");
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
void Vector::Remove(int index) // �������� �������� �� ������� �� ��������� �������
{
	RussianMessage("\n�������� �������� �� ������� �� ��������� �������\n");
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
Vector::Vector(const Vector& v)// ����������� �����������
{
	RussianMessage("\n�������� ����������� �����������\n");
	size = v.size;
	this->vect = new int[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = v.vect[i];
		
	}
	
	
}
Vector ::Vector(int siz) // �����������, ����������� �������� ����������� �������
{
	RussianMessage("\n�����������, ����������� �������� ����������� �������\n");
	size = siz;
	vect = new int[size];
}
Vector::Vector()   // ����������� �� ���������
{
	RussianMessage("\n����������� �� ���������\n");
	size = 5;
	vect = new int[size];
}


Vector Vector:: operator ++ (int v) // ���������� ���� ��������� ������� ��// ������� (��������)
{
	RussianMessage("\n���������� ���� ��������� ������� �� ++int \n");
	Vector a=*this;


	for (int i = 0; i < size; i++)
	{
		vect[i]++;
	}
	return a;
}
Vector::Vector(Vector&& v)
{
	RussianMessage("\n����������� �������� \n");
	size = v.size;
	vect = v.vect;
	v.vect = nullptr;

	
}
Vector& Vector :: operator ++ () // ���������� ���� ��������� ������� ��  // ������� (�������)
{
	RussianMessage("\n���������� ���� ��������� ������� �� int++ \n");
	for (int i = 0; i < size; i++)
	{
		vect[i]++;
	}
	return *this;
}
Vector& Vector::operator -- () // ���������� ���� ��������� ������� �� //// ������� (�������)
{
	RussianMessage("\n���������� ���� ��������� ������� �� ������� (�������) \n");
	for (int i = 0; i < size; i++)
	{
		vect[i]--;
	}
	return *this;


}
Vector Vector::operator -- (int k) // ���������� ���� ��������� ������� ��//// ������� (��������)
{
	RussianMessage("\n���������� ���� ��������� ������� ��  ������� (��������) \n");
	Vector a = *this;


	for (int i = 0; i < size; i++)
	{
		vect[i]--;
	}
	return a;

}
int& Vector::  operator [] (int index)// ������������� �������� ����������
{
	RussianMessage("\n������������� �������� ���������� \n");
	if (index < 0 || index >= size)
		return vect[0];
	return vect[index];
}
Vector& Vector:: operator = (const Vector& v) // ������������� ��������// ������������ � ������������
{
	RussianMessage("\n ������������� �������� ������������ � ������������ \n");
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
	RussianMessage("\n ������������� �������� ������������ � ��������� \n");
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
	RussianMessage("\n �������� ���� �������� \n");
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
	RussianMessage("\n �������� ������� � ������ (������  ��������� ������� ������������ � ������) \n");
	for (int i = 0; i < size; i++)
	{
		vect[i] += n;
	}
	return *this;

}
Vector& Vector:: operator += (const Vector& v)
{
	RussianMessage("\n ������������ �������� +=  ��� �������� ���� �������� \n");
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
	RussianMessage("\n ������������ �������� +=  ��� �������� ������� � ����� \n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] + n;
	}
	return *this;
}

Vector Vector::operator-(const Vector& v)
{
	RussianMessage("\n ��������� ���� ��������\n");
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
	RussianMessage("\n ��������� ����� �� �������\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] - n;
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
	RussianMessage("\n ������������� �������� -= ��� ��������� ���� ��������\n");
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
	RussianMessage("\n ��������� ��������\n");
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
	RussianMessage("\n ��������� ������� �� �����\n");
	for (int i = 0; i < size; i++)
	{
		vect[i] = vect[i] * n;
	}
	return *this;
}

Vector& Vector::operator*=(int n)
{
	RussianMessage("\n ������������� �������� *= ���  ��������� ������� �� �����\n");
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