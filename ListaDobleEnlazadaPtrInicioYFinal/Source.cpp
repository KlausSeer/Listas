#include <iostream>
#include "List.h"

void main()
{
	List<int>* lst = new List<int>();

	lst->add(3);
	lst->add(4);
	lst->add(5);
	lst->add(6);

	for (List<int>::Iterator it = lst->begin(); it != lst->end(); ++it)
	{
		cout << (*it) << endl;
	}

	cout << lst->get(0) << endl;
	cout << lst->getlast() << endl;

	system("pause");
}
