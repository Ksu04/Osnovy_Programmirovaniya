#pragma once
// �����������
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
// ������ �������������
// integer(unsigned int N):(n = N);
*/
class MyVector {
public:
	MyVector(int size);		// ����� ������ ������
	MyVector();				// �� ������ ������

	
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
	void push_back(int x);  // ��������� ������� � �����
	~MyVector() { delete[] pMem; }
private:
	int* pMem;				// ��������� �� ������
	int length, composity;
	int pointer = 0;
	int getlength() const;		// ������ �����
	
	int at(int x);			// ����� �������� ������ � ����������� ��������
	
	void insert(int x, int position);	// ������� �������� � ������ ������� (�� ���, �� ����� ������������ ������)
	
	
};
