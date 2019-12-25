#pragma once
template<class T>
class Stack
{
protected:
	T* ptr;
	const int size;
	int top;
public:
	Stack(int size_ = 1)
	{
		if (size <= 0)
			throw;
		size = size_;
		top = -1;
		ptr = new T[size];
	}
	Stack(const Stack<T>& s)
	{
		size = s.size;
		top = s.top;
		ptr = new T[size];
		for (int i = 0; i < top; i++)
			ptr[i] = s.ptr[i];
	}
	~Stack()
	{
		size = 0;
		top = 0;
		delete[] ptr;
	}
	bool IsFull()
	{
		if (top = size-1)
			return 1;
		else return 0;
	}
	bool IsEmpty()
	{
		if (top == -1) return 1;
		else return 0;
	}
	void Push(T& elem)
	{
		if (IsFull())
			throw;
		top++;
		ptr[top] = elem;
	}
	T Pop()
	{
		if (IsEmpty())
			throw;
		return ptr[top--];
	}
};