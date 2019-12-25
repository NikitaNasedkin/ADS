#pragma once
template<class T>
class Queue
{
protected:
	T* ptr;
	const int size;
	int len;
	int first;
	int last;
public:
	Queue(int size_ = 1)
	{
		size = size_;
		ptr = new T[size];
		first = last = -1;
	}
	Queue(const Queue<T>& q)
	{
		size = q.size;
		ptr = new T[size];
		first = q.first;
		last = q.last;
		for (int i = first; i != last; i = (i + 1) % size)
			ptr[i] = q.ptr[i];
	}
	~Queue()
	{
		delete[] ptr;
	}
	bool IsFull()
	{
		if (first == last + 1)
			return 1;
		else return 0;
	}
	bool IsEmpty()
	{
		if (first == last)
			return 1;
		else return 0;
	}
	void Push(T& elem)
	{
		if (IsFull) throw;
		if (first == -1 && last == -1)
		{
			first++;
			last++;
			ptr[last] = elem;
			len++;
		}
		else
		{
			last = (last + 1) % size;
			ptr[last] = elem;
			len++;
		}
	}
	T Pop()
	{
		if (IsEmpty) throw;
		len--;
		return ptr[first--];
	}
};