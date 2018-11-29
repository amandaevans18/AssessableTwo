#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store

	tVector(const tVector &vec); //copy constuctor

	tVector& operator=(const tVector &vec); // copy assignment

	T& operator[] (size_t index); //allow access to elements in arr without calling the at


	bool empty();         // Returns true if the vector contains no elements.
	void resize(size_t newSize);  // Resizes the vector to contain the given number of elements.
	void shrink_to_fit(); // Resizes the vector's capacity to match its size.
	void clear();         // Empties the vector (all elements are destroyed in this process)
};

template<typename T>
tVector<T>::tVector()
{

}

template<typename T>
tVector<T>::~tVector()
{
	arrCapacity = 0;
	arrSize = 0;
	delete[] arr;
}

template<typename T>
T * tVector<T>::data()
{
	return arr;
}

template<typename T>
void tVector<T>::reserve(size_t newCapacity)
{
	if (size > newCapacity)
	{
		std::cout << "Sorry thats what resize is for!!!" << std::endl;
		system("PAUSE");
		return;
	}
	T *temp = new T[newCapacity]();
	for (int i = 0; i < newCapacity; i++)
	{
		if (i < arrSize)
		{
			break;
		}
		else
		{
			temp[i] = arr[i];
		}
	}
	arrCapacity = newCapacity;
	*arr = *temp;
	delete temp;

}

template<typename T>
void tVector<T>::push_back(const T & value)
{
	arrSize++;
	if (arrCapacity <= arrSize)
	{
		reserve(arrCapacity * GROWTH_FACTOR);
	}

	arr[arrSize] = value;

}

template<typename T>
void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
T & tVector<T>::at(size_t index)
{
	// TODO: insert return statement here
	return arr[index];
}

template<typename T>
size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
size_t tVector<T>::capacity() const
{
	return arrCapacity;
}

template<typename T>
tVector<T>::tVector(const tVector & vec)
{
	return arr = vec;
}

template<typename T>
tVector<T> & tVector<T>::operator=(const tVector & vec)
{
	// TODO: insert return statement her
	for (size_t i = 0; i < arrCapacity; i++)
	{
		arr[i] = vec[i];
	}
	arrCapacity = vec.arrCapacity;
	arrSize = vec, arrSize;
	return arr[i];
}

template<typename T>
T & tVector<T>::operator[](size_t index)
{
	// TODO: insert return statement here
	return arr.at(index);
}

template<typename T>
bool tVector<T>::empty()
{
	if (arrSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void tVector<T>::resize(size_t newSize)
{
	if (arrCapacity < newSize)
	{
		T *temp = new T[arrCapacity]();
		for (int i = 0; i < newSize; i++)
		{
			temp[i] = arr[i];
		}

		*arr = *temp;
		arrSize = newSize;
		delete temp;
	}
	else
	{
		reserve(newSize);
	}
}

template<typename T>
void tVector<T>::shrink_to_fit()
{
	arrCapacity = arrSize;
}

template<typename T>
void tVector<T>::clear()
{
	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = NULL;
	}
	arrSize = 0;
}
