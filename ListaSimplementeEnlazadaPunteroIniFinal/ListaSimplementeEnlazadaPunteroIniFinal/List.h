#pragma once

#include <functional>

using namespace std;

typedef unsigned int uint;

template <typename T, T NADA = 0>
class List {
	struct Node;
	typedef function<int(T, T)> Comp;

	Node*   ini;
	uint    lon; 

	Comp    comparar; 

	public:
		List() : ini(nullptr), lon(0), comparar([](T a, T b) {return a - b; }) {}
		List(Comp comparar) : ini(nullptr), lon(0), comparar(comparar) {}
		~List();

		uint    longitud();

		bool    blank();
		void    addFirst(T elem);
		void    modifyLast(T elem);
		void    removeFirst();

		void List<T, NADA>::modifyPos(T elem, uint pos);
		T List<T, NADA>::obtainedPos(uint pos);
};

template <typename T, T NADA>
struct List<T, NADA>::Node {
	T       elem;
	Node*   sig; 

	Node(T elem = NADA, Node* sig = nullptr) : elem(elem), sig(sig) {}
};

template <typename T, T NADA>
List<T, NADA>::~List() {
	Nod* aux = ini;
	while (aux != nullptr) {
		aux = ini;
		ini = ini->sig;
		delete aux;
	}
}

template <typename T, T NADA>
uint List<T, NADA>::longitud() {
	return lon;
}

template <typename T, T NADA>
bool List<T, NADA>::blank() {
	return lon == 0;
}

template <typename T, T NADA>
void List<T, NADA>::addFirst(T elem) {
	Node* nuevo = new Node(elem, ini);
	if (nuevo != nullptr) {
		ini = nuevo;
		lon++;
	}
}

template <typename T, T NADA>
void List<T, NADA>::modifyLast(T elem) {
	modifyPos(elem, lon - 1);
}

template <typename T, T NADA>
void List<T, NADA>::removeFirst() {
	if (lon > 0) {
		Node* aux = ini;
		ini = ini->sig;
		delete aux;
		lon--;
	}
}

template <typename T, T NADA>
void List<T, NADA>::modifyPos(T elem, uint pos) {
	if (pos >= 0 && pos < lon) {
		Node* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		aux->elem = elem;
	}
}

template <typename T, T NADA>
T List<T, NADA>::obtainedPos(uint pos) {
	if (pos >= 0 && pos < lon) {
		Node* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		return aux->elem;
	}
	else {
		return NADA;
	}
}
