#include "BaseArray.h"

int main(void) {
	
	BaseArray<int>* ordered;
	BaseArray<float>* unordered;

	ordered = new OrderedList<int>(10, false);

	unordered = new UnorderedList<float>(5);

	cout << "Testing both lists exist by checking first max size then number of elements." << endl;

	cout << "ordered:   " << ordered->getMaxSize() << "   " << ordered->getSize() << endl;

	cout << "unordered:   " << unordered->getMaxSize() << "   " << unordered->getSize() << endl;

	system("PAUSE");

	cout << "Next we will test the unordered list by itself, \n" <<
		"then we will add 5 values to it with one being a duplicate. \n" <<
		"lastly we will print the list." << endl;

	unordered->push(3);
	unordered->push(1);
	unordered->push(4);
	unordered->push(5);
	unordered->push(1);
	

	system("PAUSE");

	cout << "the unordered list has " << unordered->getSize() << endl;

	for (int i = 0; i < unordered->getSize(); i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << unordered[0][i] << "    ";
	}

	cout << "lets remove the 4 from the list" << endl << endl;

	unordered->remove(4);

	for (int i = 0; i < unordered->getSize(); i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << unordered[0][i] << "    ";
	}

	cout << endl << "next we will add a multiple numbers to increase its max size, current max size is " << unordered->getMaxSize() << endl;



	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);
	unordered->push(1);

	cout << "the list now has " << unordered->getSize() << " elements, and a max size of " << unordered->getMaxSize() << endl;

	cout << "lastly lets find the 5" << endl;

	cout << "the 5 is in position " << unordered->linearSearch(5) << endl;

	cout << "the value at that position is " << unordered[0][unordered->linearSearch(5)] << endl;

	cout << endl << endl;

	for (int i = 0; i < unordered->getSize(); i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << unordered[0][i] << "    ";
	}
	
	cout << endl;
	system("PAUSE");

	cout << endl << endl << "Now lets use the ordered lsit" << endl;

	cout << "lets first add 4 items to the array" << endl;

	ordered->push(1);
	ordered->push(1);
	ordered->push(3);
	ordered->push(2);
	ordered->push(5);

	cout << "the ordered lists size is now " << ordered->getSize() << endl;

	for (int i = 0; i < ordered->getSize(); i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << ordered[0][i] << "    ";
	}

	system("PAUSE");

	cout << "lets add two numbers then remove the 4." << endl;

	ordered->push(6);
	ordered->push(4);

	for (int i = 0; i < ordered->getSize(); i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << ordered[0][i] << "    ";
	}

	ordered->remove(ordered->binarySearch(4));

	for (int i = 0; i < ordered->getSize(); i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << ordered[0][i] << "    ";
	}




	system("PAUSE");
	return 0;
}


