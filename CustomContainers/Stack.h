// tStack.h
#pragma once
#include"Vector.h"

template <typename T>
class tStack
{
	tVector<T> vec;                     // contains the data for a stack

public:
	tStack();                           // initializes the stack's default values

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack

	T& top();                           // returns the top-most element at the given element

	size_t size() const;                // returns current number of elements

	bool empty() const;                 // Returns true if the vector contains no elements.

	T & tStack<T>::top() const;
};

template<typename T>
tStack<T>::tStack()
{

}

template<typename T>
void tStack<T>::push(const T & value)
{
	vec.arrSize++;
	if (vec.arrCapacity <= vec.arrSize)
	{
		reserve(vec.arrCapacity * GROWTH_FACTOR);
	}

	vec[vec.arrSize] = value;
}

template<typename T>
void tStack<T>::pop()
{
	vec.arrSize--;
}

template<typename T>
T & tStack<T>::top()
{
	return vec[vec.arrSize - 1];
}

template<typename T>
size_t tStack<T>::size() const
{
	return vec.arrSize;
}

template<typename T>
inline bool tStack<T>::empty() const
{
	return vec.empty();
}

template<typename T>
inline T & tStack<T>::top() const
{
	// TODO: insert return statement here
	return vec[vec.arrSize - 1];

}