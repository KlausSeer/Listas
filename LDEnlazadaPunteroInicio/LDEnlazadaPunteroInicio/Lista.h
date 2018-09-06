#pragma once

#include <functional>

using namespace std;

typedef unsigned int uint;

template <typename T, T NADA = 0>
class Lista
{
	struct Nodo;
	typedef function<int(T, T)> Comp;

	Nodo*   Inicio;
	uint    nElementos; // Número de elementos en la lista
	Comp    Comparar; // Lambda de criterio de comparación

public:

	class Iterator {
		unsigned int    pos;
		Nodo*           aux;

	public:
		Iterator(unsigned int pos, Nodo* aux) : pos(pos), aux(aux) {}
		void operator ++() { pos++; aux = aux->next; }
		bool operator !=(Iterator x) { return pos != x.pos; }
		T    operator  *() { return aux->elem; }
	};
	Iterator begin() {
		return Iterator(0, Inicio);
	}
	Iterator end() {
		return Iterator(nElementos, nullptr);
	}

	Lista() : Inicio(nullptr), nElementos(0), Comparar([](T a, T b) {return a - b; }) {}
	Lista(Comp Comparar) : Inicio(nullptr), nElementos(0), Comparar(Comparar) {}
	~Lista();

	uint    longitud();

	bool    esVacia();

	void    agregaInicial(T Elemento);
	void    agregaPos(T Elemento, uint pos);
	void    agregaFinal(T Elemento);

	void    modificarInicial(T Elemento);
	void    modificarPos(T Elemento, uint pos);
	void    modificarFinal(T Elemento);

	void    eliminaInicial();
	void    EliminarPosicion(uint pos);
	void    EliminarPosicionFinal();

	T       obtenerInicial();
	T       obtenerPos(uint pos);
	T       obtenerFinal();
	T       buscar(T Elemento);
};

template <typename T, T NADA>

struct Lista<T, NADA>::Nodo 
{
	T       Elemento;
	Nodo*   Next; // Puntero apunta al siguiente nodo
	Nodo*	Prev; // Puntero apunta al nodo previo
	Nodo(T Elemento = NADA, Nodo* Next = nullptr, Nodo* Prev = nullptr) : Elemento(Elemento), Next(Next), Prev(Prev) {}
};

template <typename T, T NADA>
Lista<T, NADA>::~Lista() 
{
	Nodo* aux = Inicio;
	while (aux != nullptr)
	{
		aux = Inicio;
		Inicio = Inicio->Next;
		delete aux;
	}
}

template <typename T, T NADA>
uint Lista<T, NADA>::longitud()
{
	return nElementos;
}

template <typename T, T NADA>
bool Lista<T, NADA>::esVacia()
{
	return nElementos == 0;
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaInicial(T Elemento)
{
	Nodo* nuevo = new Nodo(Elemento, Inicio);
	if (nuevo != nullptr)
	{
		Inicio->Prev = nuevo;

		Inicio = nuevo;
		nElementos++;
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaPos(T Elemento, uint pos) 
{
	if (pos > nElementos) return;
	if (pos == 0)
	{
		agregaInicial(Elemento);
	}
	else
	{
		Nodo* aux = Inicio;
		for (int i = 1; i < pos; i++) 
		{
			aux = aux->Next;
		}

		Nodo* nuevo = new Nodo(Elemento, aux->Next, aux);
		if (nuevo != nullptr) 
		{
			aux->Next = nuevo;
			nuevo->Next->Prev = nuevo; //APRENDETELO!!!!
			nElementos++;
		}
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaFinal(T Elemento)
{
	agregarPos(Elemento, nElementos); // ;)
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarInicial(T Elemento) 
{
	if (nElementos > 0) 
	{
		Inicio->Elemento = Elemento;
	}
}

template <typename T, T NADA>

void Lista<T, NADA>::modificarPos(T Elemento, uint pos) 
{
	if (pos >= 0 && pos < nElementos) 
	{
		Nodo* aux = Inicio;
		for (int i = 0; i < pos; i++) 
		{
			aux = aux->Next;
		}
		aux->Elemento = Elemento;
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarFinal(T Elemento) 
{
	modificar(Elemento, nElementos - 1);
}

template <typename T, T NADA>
void Lista<T, NADA>::eliminaInicial() 
{
	if (nElementos > 0) 
	{
		Nodo* aux = Inicio;
		Inicio = Inicio->Next;
		Inicio->Prev = nullptr;
		delete aux;
		nElementos--;
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::EliminarPosicion(uint pos)
{
	if (nElementos >= 0 && pos < nElementos)
	{
		if (pos == 0)
		{
			eliminaInicial();
		}

		Nodo* aux = Inicio;
		for (int i = 1; i < pos; i++)
		{
			aux = aux->Next;
		}

		aux->Next->Prev = aux->prev; //APRENDETELO!!!!
		aux->Prev->Next = aux->Next; //APRENDETELO!!!!
		nElementos--;
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::EliminarPosicionFinal()
{
	EliminarPosicion(nElementos);
}

template <typename T, T NADA>
T Lista<T, NADA>::obtenerInicial() 
{
	return obtenerPos(0);
}
template <typename T, T NADA>
T Lista<T, NADA>::obtenerPos(uint pos) 
{
	if (pos >= 0 && pos < nElementos) 
	{
		Nodo* aux = Inicio;
		for (int i = 0; i < pos; i++) 
		{
			aux = aux->Next;
		}
		return aux->Elemento;
	}
	else 
	{
		return NADA;
	}
}

template <typename T, T NADA>
T Lista<T, NADA>::obtenerFinal() 
{
	return obtenerPos(nElementos - 1);
}

template <typename T, T NADA>
T Lista<T, NADA>::buscar(T Elemento) 
{
	Nodo* aux = Inicio;
	while (aux != nullptr) 
	{
		if (Comparar(aux->Elemento, Elemento) == 0)
		{
			return aux->Elemento;
		}
		aux = aux->Next;
	}
	return NADA;
}
