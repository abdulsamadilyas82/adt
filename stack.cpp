#include<iostream>
#include"Stack.h"
using namespace std;


template<class T>
stack<T>::stack(int s)
{
	size = s;
	top = -1;
	arr = new T[size];
}

template<class T>
stack<T>::~stack()
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}


template<class T>
void stack<T>::push(T val)
{
	if (isFull())
	{
		reSize();
	}

	arr[++top] = val;
}

template<class T>
void stack<T>::pop()
{
	if (!isEmpty())
	{
		top--;
	}
}

template<class T>
T stack<T>::Top()
{
	if (!isEmpty())
	{
		return arr[top];
	}

	else
	{
		return -1;
	}

}


template<class T>
bool stack<T>::isEmpty()
{
	if (top == -1)
	{
		return true;
	}

	else
	{
		return false;
	}

	
}

template<class T>
bool stack<T>::isFull()
{
	if (top == size)
	{
		return true;
	}

	else
	{
		return false;
	}
}

template<class T>
void stack<T>::reSize()
{
	T* temp = new T[size * 2];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	delete[] arr;
	arr = temp;
	size = size * 2;
}