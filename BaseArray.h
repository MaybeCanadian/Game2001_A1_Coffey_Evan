#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;

template<class T>
class BaseArray
{
public:
	BaseArray(int size) : p_array(nullptr), maxSize(0), growSize(2), num_Elements(0)
	{
		if (size) {
			maxSize = size;
			p_array = new T[maxSize];

			memset(p_array, 0, sizeof(T) * maxSize);
		}
	}

	~BaseArray() {
		if (p_array != nullptr) {

			delete[] p_array;
			p_array = nullptr;
		}
	}

	const T& operator[] (int index)
	{
		assert(p_array != nullptr && index < num_Elements);
		return p_array[index];
	}

	virtual int linearSearch(T value) { //returns the index
		assert(p_array != nullptr);

		for (int i = 0; i < num_Elements; i++) {
			if (p_array[i] == value) {
				return i;
			}
		}

		return -1; // found nothing
	}

	int getSize() { return num_Elements; }
	int getMaxSize() { return maxSize; }
	int getGrowSize() { return growSize; }

	virtual void push(T val) { //adds to the back of the array
		assert(p_array != nullptr);

		if (num_Elements >= maxSize) {
			cout << "expanding" << endl;
			expand();
		}

		p_array[num_Elements] = val;
		num_Elements++;
	}

	void pop() { //preserves order
		assert(p_array != nullptr);

		if (num_Elements > 0) {
			num_Elements--;
		}

	}
	
	virtual bool remove(int index) { //gets rid of one item in the array preserves order
		assert(p_array != nullptr);

		if (index > maxSize || index > num_Elements) {
			return false;
		}

		for (int k = index; k < num_Elements - 1; k++) {
			p_array[k] = p_array[k + 1];
		}

		num_Elements--;
		return true;
	}

	virtual void clear() //vlears the array
	{
		num_Elements = 0; // makes it think its exmpty so it can be overwritten. date is still there though
	}

	virtual int binarySearch(T val) { return -1; };

protected:
	bool expand() { //expands the array by an ever increasing value

		if (growSize <= 0) {
			return false;
		}
		T* temp = new T[maxSize + growSize];
		
		assert(temp != nullptr);
	
		memcpy(temp, p_array, sizeof(T) * maxSize);
		
		delete[] p_array;
	
		p_array = temp;
		
		temp = nullptr;
	
		maxSize = maxSize + growSize;

		growSize = growSize * 2;

		return true;
	}

protected: //variables
	T* p_array; //pointer to where array is stored
	int maxSize; //current max size of array
	int growSize; //ammount to grow each time
	int num_Elements; //how mnay things in the array
};


#include "UnorderedList.h"
#include "OrderedList.h"
