#include "BaseArray.h"

int main(void) {
	
	BaseArray<int>* test;

	test = new UnorderedList<int>(10);

	cout << test->getSize() << endl;

	system("PAUSE");

	test->push(10);

	cout << test->getSize() << endl;

	cout << test[0][0] << endl;


	return 0;
}


