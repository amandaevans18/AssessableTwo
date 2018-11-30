// tObjectPool.h
#pragma once
#include "Vector.h"
template <typename T>
class tObjectPool
{
public:
	tVector<T> pool;

	tObjectPool(){}                      // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~tObjectPool();                      // destroys all objects

	tVector<bool> free;                            // pointers to objects that can be reused
	
	size_t freeCount;                   // number of objects that are free to use
	size_t usedCount;                   // number of objects that are in use
	size_t cap;

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
 tObjectPool<T>::tObjectPool(size_t initialCapacity)
{
	pool.reserve(initialCapacity);
	free.reserve(initialCapacity);
	freeCount = initialCapacity;
	usedCount = 0;
	for (int i = 0; i < initialCapacity; i++) 
	{
		pool[i] = T();
		free[i] = true;
	}
}

template<typename T>
tObjectPool<T>::~tObjectPool()
{

}

template<typename T>
 T * tObjectPool<T>::retrieve()
{
	 if (cap == usedCount) 
	 {
		 return nullptr;
	 }
	 else 
	 {
		 return *pool[usedCount];
	 }
}

template<typename T>
void tObjectPool<T>::recycle(T * obj)
{
	for (int i = 0; i < cap; i++)
	{
		if (pool[i] == *obj) 
		{
			for (int j = 0; j < usedCount; j++) 
			{
				pool[j] = pool[j + 1];
			}
		}
	}
	usedCount--;
	free[usedCount] = false;

}

template<typename T>
size_t tObjectPool<T>::capacity()
{
	return cap;
}
