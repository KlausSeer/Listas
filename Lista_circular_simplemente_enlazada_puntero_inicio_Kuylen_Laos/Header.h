#pragma once

template <typename T, T NADA = 0>

class Lista {
public:
	struct Nodo {
		Nodo * next;
		T elem;

		Nodo(T elem = NADA, Nodo* next = nullptr) : elem(elem), next(next) {}
	}	*first, *last;

	unsigned int lon;


public:
	class Iterator;
	Lista() : first(nullptr), last(nullptr), lon(0) {}


	void addFirst(T newElem) {
		Nodo * nuevo = new Nodo(newElem, first);
		if (nuevo != nullptr) {
			first = nuevo;
			lon++;
			if (last == nullptr)
				last = first;
		}
	}

	void addFirstCircular(T newElem) {
		if (first != nullptr) {
			Nodo * nuevo = new Nodo(first->elem, first->next);
			first->elem = newElem;
			first->next = nuevo;
		}
		else {
			Nodo * nuevo = new Nodo(newElem, nullptr);
			first = last = nuevo;
		}
		return;
	}

	void add(unsigned short pos, T newElem) {
		if (pos > lon)
			return;
		if (pos == 0)
			addFirst(newElem);
		else if (pos == lon)
			addLast(newElem);
		else {
			Nodo * aux = first;
			for (short i = 1; i < pos; i++)
				aux = aux->next;

			Nodo * nuevo = new Nodo(newElem, aux->next);
			if (nuevo != nullptr) {
				aux->next = nuevo;
				lon++;
			}
		}
		return;
	}

	void addLast(T newElem) {
		Nodo * nuevo = new Nodo(newElem, nullptr);
		if (nuevo != nullptr) {
			if (last != nullptr) {
				last->next = nuevo;
				last = nuevo;
			}
			else {
				last = nuevo;
				first = nuevo;
			}
			lon++;
		}
	}

	void modifyfirst(T newElem) {
		if (lon > 0)
			first->elem = newElem;
		return;
	}
	Iterator begin() {
		return Iterator(0, first);
	}
	Iterator end() {
		return Iterator(lon, nullptr);
	}
};

	void find() {
		Nodo * aux = first;
		return;
	}


template <typename T, T NADA>
class Lista<T, NADA>::Iterator {
	unsigned int  pos;
	Nodo* aux;
public:
	Iterator(unsigned short pos, Nodo* aux) : pos(pos), aux(aux) {}
	void operator ++() { pos++; aux = aux->next; }
	bool operator !=(Iterator v) { return pos != v.pos; }
	T    operator  *() { return aux->elem; }
};
