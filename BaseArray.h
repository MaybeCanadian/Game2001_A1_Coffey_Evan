#pragma once


template<class T>
class BaseArray
{
public:
	BaseArray(int size) : p_array(NULL), maxSize(0), growSize(2), num_Elements(0)
	{
		if (size) {
			maxSize = size;
			p_array = new T(maxSize);
		}
	}

	~BaseArray() {
		if (p_array != NULL0) {
			delete[] p_array;
			p_array = NULL;
		}
	}

	T& operator[](int index) 
	{
		assert(p_array != NULL && index <= num_Elements);
		return p_array[index];
	}

	virtual int linearSearch(T value) { //returns the index
		assert(p_array != NULL);

		for (int i = 0; i < num_Elements - 1; i++) {
			if (p_array[i] == value) {
				return i;
			}
		}

		return -1; // found nothing
	}

	virtual int getSize() { return num_Elements };
	virtual int getMaxSize() { return maxSize };
	virtual int getGrowSize() { return growSize };

	virtual void push(T val) { //adds to the back of the array
		assert(p_array != NULL);

		if (num_Elements >= maxSize) {
			expand();
		}

		p_array[num_Elements] = val;
		num_Elements++;
	}
	
	virtual bool remove(int index) { //gets rid of one item in the array
		assert(p_array != NULL);

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

	virtual bool expand() { //expands the array by an ever increasing value

		T* temp = new T(maxSize + growSize);
		assert (temp != NULL);

		memcopy(temp, p_array, sizeof(T) * maxSize);

		delete p_array;

		p_array = temp;

		maxSize = maxSize + growSize;

		growSize = growSize * 2;

		return true;
	}

private: //variables
	T* p_array; //pointer to where array is stored
	int maxSize; //current max size of array
	int growSize; //ammount to grow each time
	int num_Elements; //how mnay things in the array
};

