#pragma once
using namespace std;
void RussianMessage(const char* s);

class Vector
{
	int* vect;  // ������
	int size;   // ����������� �������
public:
	Vector();  // ����������� �� ���������
	
	Vector(int siz); // �����������, ����������� �������� ����������� �������
	
	Vector(const int* ptr, int siz); // �����������, ����������� ������������������� ������ � ������� ������������� �������
	
	Vector(const Vector& v);// ����������� �����������
	

	~Vector() // ����������
	{
		RussianMessage("\n ����������\n");
		delete[]vect;
	}
	void SetSize(int d);
	void SetVect(int index, int numb);
	int GetSize()
	{
		return size;
	}
	int GetVect(int i)
	{
		return vect[i];
	}
	int GetSize() const; // ������� ���������� ����������� �������
	
	void Print(); // ����� �� �����
	
	void Input(); // ���������� �������
	
	void Clear(); // ������� �������
	
	bool IsEmpty() const; // ���������� ������, ���� ������ ������
	
	void Add(const int& item); // ���������� �������� � ������
	
	void Insert(int index, const int& item); // ������� ��������� � ������ �� ��������� �������
	
	void Remove(int index); // �������� �������� �� ������� �� ��������� �������


	/*�������� � ����� Vector ��������� ������ :*/


	Vector(Vector&& v); // ����������� ��������
	Vector& operator ++ (); // ���������� ���� ��������� ������� ��  // ������� (�������)
	Vector operator ++ (int v); // ���������� ���� ��������� ������� ��// ������� (��������)
	Vector& operator -- (); // ���������� ���� ��������� ������� �� //// ������� (�������)
	Vector operator -- (int k); // ���������� ���� ��������� ������� ��//// ������� (��������)
	Vector& operator = (const Vector& v); // ������������� ��������// ������������ � ������������
	
	
	Vector& operator = (Vector&& v); // ������������� ��������
	//// ������������ � ���������

	int& operator [] (int index);// ������������� �������� ����������
	
	Vector operator + (const Vector& v); // �������� ���� ��������
	Vector operator + (int n); // �������� ������� � ������ (������//// ��������� ������� ������������ � ������)
	Vector& operator += (const Vector& v); // ������������� �������� +=//// ��� �������� ���� ��������
	Vector& operator += (int n);
	Vector operator - (const Vector& v); // ��������� ���� ��������
	Vector operator - (int n); // ��������� ����� �� �������
	Vector& operator -= (const Vector& v); // ������������� �������� -=//// ��� ��������� ���� ��������
	Vector operator * (const Vector& v); // ��������� ��������
	Vector operator * (int n); // ��������� ������� �� �����
	Vector& operator *= (int n); // ������������� �������� *= ���//// ��������� ������� �� �����
	// 
	friend istream& operator >> (istream& cin, Vector& v);//// ���� ������� � ����������
	friend ostream& operator << (ostream& cout, Vector& v);//// ����� ������� �� �����


	
}; 
