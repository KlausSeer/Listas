#include <iostream>
#include "Header.hpp"

using namespace std;


int main() {
	List<int>* list = new List<int>();
	list->addFirst(10);


	list->addFirstenCircular(22);
	list->addFirstenCircular(33);
	list->addFirstenCircular(77);
	list->addFirstenCircular(84);
	list->remove(1);
	
	cout << "___________-\n";
	

	for (List<int>::Iterator it = list->begin(); it != list->end(); ++it) {
		cout << *it << endl;
	}
	
	system("pause");

	return 0;
}