#include <iostream>
#include "list.h"
#include <stdlib.h>

using namespace std;

int main() {
	List<int>* lst = new List<int>();

	lst->addFirst(50);
	lst->addFirst(40);
	lst->addFirst(30);
	lst->addFirst(20);
	lst->modifyLast(80);
	lst->removeFirst();


	for (int i = 0; i < lst->longitud(); i++) {
		cout << lst->obtainedPos(i) << endl;
	}
	cout << lst->longitud() << endl;



	system("pause");
	return 0;

}