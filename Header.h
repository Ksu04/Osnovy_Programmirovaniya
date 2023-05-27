#pragma once
#include<iostream>
#include<algorithm>

template<typename T>
class Array
{
private:
	T* arr;
	size_t length;
	size_t capacity;
public:
	explicit Array(size_t initial_capacity = 1) :length(0), capacity(initial_capacity)
	{
		arr = new T[initial_capacity];
	}

	void push_back(T element)
	{
		if (capacity == length)
		{
			capacity *= 2;
			T* new_arr = new T[capacity];
			std::copy(arr, &arr[length], new_arr);
			delete arr[];
			arr = new_arr;
		}
		arr[length++] = element;
	}

	void erase(size_t index)
	{
		for (size_t i = index + 1; i < length; i++)
		{
			arr[i - 1] = arr[i];
		}
		length--;
	}

	T& at(size_t index) return arr[index];

	int size() const return length;

	~Array() delete[] arr;
};