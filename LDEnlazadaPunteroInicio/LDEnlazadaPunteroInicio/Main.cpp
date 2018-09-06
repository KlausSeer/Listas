#include <iostream>
#include "Lista.h"
#include <conio.h>

using namespace std;

int main() 
{
	Lista<int>* lst = new Lista<int>();

	lst->agregaInicial(50);
	lst->agregaInicial(40);
	lst->agregaInicial(30);
	lst->agregaPos(10, 0);
	lst->agregaPos(20, 1);
	lst->agregaPos(60, 5);
	lst->agregaPos(70, 6);
	lst->agregaPos(80, 8);

	for (int i = 0; i < lst->longitud(); i++)
	{
		cout << lst->obtenerPos(i) << endl;
	}

	cout << lst->longitud() << endl;
	cout << lst->obtenerInicial() << endl;
	cout << lst->obtenerPos(0) << endl;
	cout << lst->obtenerPos(1) << endl;
	cout << lst->obtenerPos(3) << endl;
	cout << lst->obtenerPos(5) << endl;
	cout << lst->obtenerPos(6) << endl;
	cout << lst->obtenerPos(7) << endl;
	cout << lst->obtenerPos(10) << endl;
	cout << lst->obtenerFinal() << endl;
	cout << lst->buscar(40) << endl;

	_getch();
}
