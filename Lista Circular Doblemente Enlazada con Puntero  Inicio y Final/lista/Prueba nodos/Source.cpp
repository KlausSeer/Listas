#include <iostream>

using namespace std;

template<typename T, T nada =0>

class Lista {
private:

	struct Nodo
	{
		Nodo* before;
		Nodo* after;
		T elem;

		Nodo(T elem = nada, Nodo* before = nullptr, Nodo* after = nullptr) : elem(elem), before(before), after(after){}
	};

	unsigned short lon=0;
	Nodo* first, *last;

public:

	Lista() : first(nullptr), last(nullptr){}

	unsigned short size() { return lon; }

	void addfirst(T elem) {
		Nodo* nodo = new Nodo(elem, last, first);
		if (first == nullptr) {

			first = nodo;
			last = first;
			first->after = first;
			first->before = last;
			lon++;

		}

	}

	void add(T elem, unsigned short pos) {

		if (pos > lon)
			return;
		if (pos == 0) {
			addfirst(elem);
		}
		else if (pos == lon) { addlast(elem); }
		else {
			Nodo* aux = first;
			for (int i = 1; i < pos; i++) {

				aux = aux->after;

			}
			Nodo* nuevo = new Nodo(elem, aux, aux->after);

			if(nuevo != nullptr){
				aux->after = nuevo;
				lon++;
			}

		}

	}

	void addlast(T elem) {
	
		if (first == nullptr) {

			addfirst(elem);

		}
		else {
			Nodo* aux = first;
			
			for (int i = 1; i < lon; i++) {

				aux = aux->after;

			}

			Nodo* nodo = new Nodo(elem, aux, first);

			if (nodo != nullptr) {

				aux->after = nodo;

			}

			last = aux->after;
			lon++;
		}

	}

	void modifyfirst(T elem){
	
		first->elem = elem;

	}

	void modifylast(T elem){
	
		last->elem = elem;
	
	}

	void modify(T elem,unsigned short pos){
		
		if (pos > lon)
			return;
		if (pos == 0) {
			modifyfirst(elem);
		}
		else if (pos == lon) { modifylast(elem); }
		else {
			Nodo* aux = first;

			for (int i = 1; i < pos; i++) {

				aux = aux->after;

			}

			aux->elem = elem;
		}
	
	}

	void removefirst(){
	
		Nodo* aux = first;
		first = first->after;
		first->before = last;
		delete aux;
		lon--;

	}

	void removelast(){
	
		Nodo* aux = last;
		last = last->before;
		last->after = first;
		delete aux;
		lon--;
	
	}

	void remove(unsigned short pos){
		
		if (pos > lon)
			return;
		if (pos == 0) {
			removefirst(elem);
		}
		else if (pos == lon) { removelast(elem); }
		else {
			Nodo* aux = first;

			for (int i = 1; i < pos; i++) {

				aux = aux->after;

			}
			Nodo* aux2 = aux->after;
			aux2->before = aux->before;
			
			delete aux;

		}
	}

	T getfirstelem(){
	
		return getelem(1);
	
	}

	T getelem(unsigned short pos) {
	
		if (pos >= 1 && pos <= lon) {
			Nodo* aux = first;
			for (int i = 0; i < pos; i++) {
				aux = aux->after;
			}
			return aux->elem;
		}
		else {
			return nada;
		}
	
	}

	T getlastelem(){
	
		return getelem(lon);
	
	}

};


int main() {
	Lista<int>* lst = new Lista<int>();

	lst->addfirst(50);
	lst->add(55, 1);
	lst->add(20, 2);
	lst->add(60, 3);
	lst->add(70, 4);
	lst->add(80, 5);
	for (int i = 1; i <= lst->size(); i++) {
		cout << lst->getelem(i) << endl;
	}
	cout << "/////////////////////" << endl;
	cout << lst->size() << endl;
	cout << "/////////////////////" << endl;
	cout << lst->getfirstelem() << endl;
	cout << lst->getelem(1) << endl;
	cout << lst->getelem(2) << endl;
	cout << lst->getelem(3) << endl;
	cout << lst->getelem(4) << endl;
	cout << lst->getelem(5) << endl;
	cout << lst->getelem(6) << endl;
	cout << lst->getelem(7) << endl;
	cout << lst->getelem(10) << endl;
	cout << lst->getlastelem() << endl;
	cout << "/////////////////////" << endl;
	getchar();
	return 0;
}
