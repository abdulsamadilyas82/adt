#ifndef STACK_H
#define STACK_H

template<class T>

class stack
{

private:
	T* arr;
	int top;
	int size;

public:
	stack(int);
	void push(T val);
	void pop();
	T Top();
	~stack();
	bool isEmpty();
	bool isFull();
	void reSize();
};

#endif 