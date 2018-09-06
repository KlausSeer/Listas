#pragma once
typedef unsigned int uint;
template<typename T, T NADA = 0 >

class List {
public:
	struct Node {
		T       elem;
		Node*   next;
		Node(T elem = NADA, Node* next = nullptr) : elem(elem), next(next) {}
	};

	uint lon;
	Node *first;
	Node *last;
	Node* ref;

public:
	class Iterator;
	List() : first(nullptr), last(nullptr), ref(nullptr), lon(0) {}
	~List() {}

	void addFirst(T elem);
	void addFirstenCircular(T elem);
	void remove(uint pos);
	void removeFirst();
	T getFirst();
	T getPos(uint pos);

	Iterator begin() {
		return Iterator(0, first);
	}
	Iterator end() {
		return Iterator(lon, nullptr);
	}
};


template <typename T, T NADA>
void List<T, NADA>::addFirst(T elem) {
	Node* nuevo = new Node(elem, first);
	if (nuevo != nullptr) {
		first = nuevo;
		lon++;
		if (last == nullptr)
			last = first;
	}
}

template <typename T, T NADA>
void List<T, NADA>::addFirstenCircular(T elem) {
	if (first == nullptr) {
		Node* nuevo = new Node(elem, nullptr);
		first = last = nuevo;
	}
	else {
		Node* nuevo = new Node(first->elem, first->next);
		first->elem = elem;
		first->next = nuevo;
	}
	lon++;
}


template <typename T, T NADA>
void List<T, NADA>::removeFirst() {
	if (lon > 0) {
		if (lon == 1) {
			delete first;
			lon--;
		}
		Node* aux = first;
		first = first->next;
		last->next = first;
		delete aux;
		lon--;
	}
}

template <typename T, T NADA>
void List<T, NADA>::remove(uint pos) {
	if (pos < lon)
	{
		if (pos == 0 && first!=nullptr)
		{
			removeFirst();

		}
		Node* aux = first;
		for (int i = 1; i < pos; i++)
		{
			aux = aux->next;
		}
		Node* aux2 = aux->next;
		aux->next = aux2->next;
		delete aux2;
		lon--;
	}
}

template <typename T, T NADA>
T List<T, NADA>::getFirst() {
	return first->elem;
}


template <typename T, T NADA>
T List<T, NADA>::getPos(uint pos) {
	if (pos >= 0 && pos <= lon) {
		Node* aux = first;
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
class List<T, NADA>::Iterator {
	unsigned int  pos;
	Node* aux;
public:
	Iterator(unsigned int pos, Node* aux) : pos(pos), aux(aux) {}
	void operator ++() { pos++; aux = aux->next; }
	bool operator !=(Iterator x) { return pos != x.pos; }
	T    operator  *() { return aux->elem; }
};