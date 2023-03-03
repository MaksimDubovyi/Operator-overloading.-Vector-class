#pragma once
using namespace std;
void RussianMessage(const char* s);

class Vector
{
	int* vect;  // Вектор
	int size;   // Размерность вектора
public:
	Vector();  // Конструктор по умолчанию
	
	Vector(int siz); // Конструктор, позволяющий задавать размерность вектора
	
	Vector(const int* ptr, int siz); // Конструктор, позволяющий проинициализировать вектор с помощью существующего массива
	
	Vector(const Vector& v);// Конструктор копирования
	

	~Vector() // Деструктор
	{
		RussianMessage("\n Деструктор\n");
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
	int GetSize() const; // Функция возвращает размерность вектора
	
	void Print(); // Вывод на экран
	
	void Input(); // Заполнение вектора
	
	void Clear(); // Очистка вектора
	
	bool IsEmpty() const; // Возвращает истину, если вектор пустой
	
	void Add(const int& item); // Добавление элемента в вектор
	
	void Insert(int index, const int& item); // Вставка элементов в вектор по заданному индексу
	
	void Remove(int index); // Удаление элемента из вектора по заданному индексу


	/*Добавить в класс Vector следующие методы :*/


	Vector(Vector&& v); // Конструктор переноса
	Vector& operator ++ (); // Увеличение всех компонент вектора на  // единицу (префикс)
	Vector operator ++ (int v); // Увеличение всех компонент вектора на// единицу (постфикс)
	Vector& operator -- (); // Уменьшение всех компонент вектора на //// единицу (префикс)
	Vector operator -- (int k); // Уменьшение всех компонент вектора на//// единицу (постфикс)
	Vector& operator = (const Vector& v); // Перегруженный оператор// присваивания с копированием
	
	
	Vector& operator = (Vector&& v); // Перегруженный оператор
	//// присваивания с переносом

	int& operator [] (int index);// Перегруженный оператор индексации
	
	Vector operator + (const Vector& v); // Сложение двух векторов
	Vector operator + (int n); // Сложение вектора с числом (каждый//// компонент вектора складывается с числом)
	Vector& operator += (const Vector& v); // Перегруженный оператор +=//// для сложения двух векторов
	Vector& operator += (int n);
	Vector operator - (const Vector& v); // Вычитание двух векторов
	Vector operator - (int n); // Вычитание числа из вектора
	Vector& operator -= (const Vector& v); // Перегруженный оператор -=//// для вычитания двух векторов
	Vector operator * (const Vector& v); // Умножение векторов
	Vector operator * (int n); // Умножение вектора на число
	Vector& operator *= (int n); // Перегруженный оператор *= для//// умножения вектора на число
	// 
	friend istream& operator >> (istream& cin, Vector& v);//// Ввод вектора с клавиатуры
	friend ostream& operator << (ostream& cout, Vector& v);//// Вывод вектора на экран


	
}; 
