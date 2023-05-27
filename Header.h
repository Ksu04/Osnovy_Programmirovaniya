#pragma once
// конструктор
#include<iostream>

class integer
{
public :
	unsigned count_dels();
	unsigned count_digits(unsigned int N);
	unsigned reverse(unsigned int N);
	unsigned long reverse_digit(unsigned int N);
	bool polindrom();
	unsigned int soversh();
	bool  is_prostoe();
	
	integer(unsigned N) {
		this -> n = N;
	};
	~integer() {};
private:
	unsigned n, size;
};
/*
class Set
{
public:
	Set(unsigned N) {
		this->size = N;
	}
	~Set() {};
private:
	unsigned size, *arr;
	unsigned p;
	
};
// список инициализации
// integer(unsigned int N):(n = N);
*/
class MyVector {
public:
	MyVector(int size);		// сразу задаем расмер
	MyVector();				// не задаем размер

	
	void reserve();
	void reserve(int x);
	MyVector& operator =(const MyVector& fromobj)
	{
		if (composity != fromobj.getlength())
		{
			this->length = fromobj.getlength();
			int* p;

			p = new int[length];

			for (int i = 0; i < length; i++)
			{
				p[i] = pMem[i];
			}
			delete[] pMem;
			pMem = p;
			
		}
		return *this;


	}
	void print();
	void push_back(int x);  // вставляет элемент в конец
	~MyVector() { delete[] pMem; }
private:
	int* pMem;				// указатель на память
	int length, composity;
	int pointer = 0;
	int getlength() const;		// узнать длину
	
	int at(int x);			// чтобы получить доступ к конкретному элементу
	
	void insert(int x, int position);	// вставка элемента в нужную позицию (не эфф, тк нужно перевыделять память)
	
	
};
