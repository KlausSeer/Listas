#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
using namespace System;

struct Nodo {
	int Dato;
	Nodo* Siguiente;
}*Primero, *Ultimo;

void InsertarAlFinal() {
	Nodo* Nuevo = new Nodo();
	cout << "Ingrese el dato nuevo: ";
	cin >> Nuevo->Dato;
	if (Primero == NULL) {
		Primero = Nuevo;
		Primero->Siguiente = Primero;
		Ultimo = Primero;
	}
	else {
		Ultimo->Siguiente = Nuevo;
		Nuevo->Siguiente = Primero;
		Ultimo = Nuevo;
	}
}

void MostrarLista() {
	Nodo* Actual = new Nodo();
	Actual = Primero;
	if (Primero != NULL) {
		do {
			cout << Actual->Dato << endl;
			Actual = Actual->Siguiente;
		} while (Actual != Primero);
	}
	else {
		cout << "La lista esta vacia";
	}
}

void BuscarNodo() {
	Nodo* Actual = new Nodo();
	Actual = Primero;
	bool Encontrado = false;
	int NodoBuscado;
	cout << "Ingrese el valor del nodo buscado: ";
	cin >> NodoBuscado;
	if (Primero != NULL) {
		do {
			if (Actual->Dato == NodoBuscado) {
				cout << "El nodo se ha encontrado" << endl;
				Encontrado = true;
			}
			Actual = Actual->Siguiente;
		} while (Actual != Primero && Encontrado != true);
		if (!Encontrado) {
			cout << "El nodo no se ha encontrado" << endl;
		}
	}
	else {
		cout << "La lista se encuentra vacia";
	}
}

void EliminarNodo() {
	Nodo* Actual = new Nodo();
	Actual = Primero;
	Nodo* Anterior = new Nodo();
	Anterior = NULL;
	bool Encontrado = false;
	int NodoBuscado;
	cout << "Ingrese el valor a eliminar: ";
	cin >> NodoBuscado;
	if (Primero != NULL) {
		do {
			if (Actual->Dato == NodoBuscado) {
				cout << "El nodo se ha encontrado y se ha eliminado" << endl;
				if (Actual == Primero) {
					Primero = Primero->Siguiente;
					Ultimo->Siguiente = Primero;
				}
				else if (Actual == Ultimo) {
					Anterior->Siguiente = Primero;
					Ultimo = Anterior;
				}
				else {
					Anterior->Siguiente = Actual->Siguiente;
				}

				Encontrado = true;
			}
			Anterior = Actual;
			Actual = Actual->Siguiente;
		} while (Actual != Primero && Encontrado != true);
		if (!Encontrado) {
			cout << "El nodo no se ha encontrado";
		}
	}
	else {
		cout << "La lista se encuentra vacia";
	}
}

int main() {

	InsertarAlFinal();
	InsertarAlFinal();
	InsertarAlFinal();
	InsertarAlFinal();
	InsertarAlFinal();
	MostrarLista();
	BuscarNodo();
	EliminarNodo();
	MostrarLista();

	_getch();
	return 0;
}