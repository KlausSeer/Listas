#include <iostream>

using namespace std;

typedef unsigned short ushort;
template<typename T,T NADA = 0>

class Lista {
	
	struct Nodo;
	Nodo* first;
	Nodo* last;
	ushort lon;

public:
	
	Lista() : first(nullptr) , last (nullptr) , lon (0){}
	~Lista();
	
	ushort longitud();
	void addFirst(T elem);
	void modify(T elem, ushort pos);
	void modifyPrev(Nodo* nodo);
	T getElem(ushort pos);
	T getElemPrevPos(ushort pos);
};

template<typename T, T NADA >
struct Lista<T, NADA>::Nodo {
	T       elem;
	Nodo*    prev;
	Nodo*    next;
	Nodo(T elem = NADA, Nodo* next = nullptr, Nodo* prev = nullptr) : elem(elem), next(next), prev(prev) {}
};

template <typename T, T NADA>
Lista<T, NADA>::~Lista() {
	Nodo* aux = first;
	while (aux != nullptr) {
		aux = first;
		first = first->next;
		delete aux;
	}
}

template <typename T, T NADA>
ushort Lista<T, NADA>::longitud() {
	return lon;
}

template <typename T, T NADA>
void Lista<T, NADA>::addFirst(T elem) {
	
	Nodo* nuevo = new Nodo(elem, first, last); 
	if (nuevo != nullptr) {
		if (lon == 0) { last = nuevo; }
		first = nuevo;	
		lon++;
		if (lon >= 2) { modifyPrev(first->next); }
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::modifyPrev(Nodo* nodo) {
	nodo->prev = first;
}

template <typename T, T NADA>
void Lista<T, NADA>::modify(T elem, ushort pos) {
	if (pos >= 0 && pos < lon) {
		Nodo* aux = first;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		aux->elem = elem;
	}
}

template <typename T, T NADA>
T Lista<T, NADA>::getElem(ushort pos) {
	if (pos >= 0 && pos < lon) {
		Nodo* aux = first;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		return aux->elem;
	}
	else {
		return NADA;
	}
}
template <typename T, T NADA>
T Lista<T, NADA>::getElemPrevPos(ushort pos) {
	if (lon == 1) { return -5; }
	else{
	     Nodo* aux = first;
	     for (short i = 0; i < pos; i++)
	     {
	     	aux = aux->next;
	     }
	     Nodo* prev = aux->prev;
	     return prev->elem;
	}
}
int main() {

	Lista<int>* lst = new Lista<int>();

	lst->addFirst(50);
	lst->addFirst(10);
	lst->addFirst(20);
	lst->addFirst(30);
	lst->addFirst(1);
	lst->modify(4,2);
	for (int i = 0; i < lst->longitud(); i++) {
		cout << lst->getElem(i) << endl;
	}
	int pos;
	while (1) {
		cout << "\n\nIngrese la pos-> para darle el elemento de nudo previo "; cin >> pos;
		if (pos > lst->longitud() - 1) {
			cout << "Ingrese otra pos";
		}
		else{
		   if (lst->getElemPrevPos(pos) == -5) { cout << "Solo hay un elemento"; }
		   else cout << "\nEl elemento previo de la pos " << pos << " es: " << lst->getElemPrevPos(pos);;
	    }
	}
}