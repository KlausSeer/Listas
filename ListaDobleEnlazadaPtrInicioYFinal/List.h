#pragma once
#include <iostream>
#include <functional>

using namespace std;

template <typename T, T NONE = 0>
class List {
	struct Node;

	Node*   last;
	Node*   first;
	unsigned int    nElem; 


public:
	List() : first(nullptr), nElem(0) {};
	~List();

	void add(T elem);
	T get(int pos);
	T getlast();

	class Iterator {
		unsigned int pos;
		Node* aux;
	public:
		Iterator(unsigned int pos, Node* aux) : pos(pos), aux(aux) {}
		void operator ++() { pos++; aux = aux->next; }
		bool operator !=(Iterator x) { return pos != x.pos; }
		T operator *() { return aux->elem; }
	};
	Iterator begin() {
		return Iterator(0, first);
	}
	Iterator end() {
		return Iterator(nElem, nullptr);
	}

};

template <typename T, T NONE>
struct List<T, NONE>::Node {
	T       elem;
	Node*   next;
	Node*	prev;

	Node(T elem = NONE, Node* next = nullptr, Node* prev = nullptr) : elem(elem), next(next), prev(prev) {}
};

template <typename T, T NONE>
List<T, NONE>::~List() {
	Node* aux = first;
	while (aux != nullptr) {
		aux = first;
		first = first->next;
		delete aux;
	}
}

template<typename T, T NONE>
void List<T, NONE>::add(T elem)
{
	if (nElem == 0)
	{
		Node* nuevo = new Node(elem, nullptr, nullptr);
		if (nuevo != nullptr)
		{
			first = nuevo;
			last = nuevo;
			nElem++;
		}
	}

	else
	{
		Node* aux = first;
		Node* nuevo = new Node(elem, first, nullptr);
		if (nuevo != nullptr)
		{
			aux->prev = nuevo;
			first = nuevo;
			nElem++;
		}
	}

}

template<typename T, T NONE>
inline T List<T, NONE>::get(int pos)
{
	if (pos == 0)
		return first->elem;
	if (pos < nElem)
	{
		Node* aux = first;
		for (int i = 0; i < pos; i++)
		{
			aux = aux->next;
		}
		return aux->elem;
	}
	else if (pos == nElem)
	{
		return getlast();
	}
	else
		return NONE;
}

template<typename T, T NONE>
inline T List<T, NONE>::getlast()
{
	return last->elem;
}
