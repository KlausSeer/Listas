#include <iostream>
#include "Header.h"

using namespace std;

int main() {

	Lista<int> list;


	list.add(0, 1);
	list.add(0, 2);
	list.add(1, 8);
	list.add(1, 5);
	list.add(2, 13);
	list.add(2, 9);
	list.add(3, 6);


	list.mostrar();

	for (Lista<int>::Iterator it = list.begin(); it != list.end(); ++it) {
		cout << *it << endl;
	}
	system("pause");
	return 0;
}