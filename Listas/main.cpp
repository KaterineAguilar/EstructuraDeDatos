#include <iostream>
#include "ListaEnlazada.h"
#include "Colas_dinamicas.h"
#include "Pilas_dinamicas.h"

using namespace std;

int main(int argc, char** argv) {
	ListaEnlazada<int> ListaNumeros;
	for(int i = 1; i <= 45; i++) {
		ListaNumeros.Anadir(i);
	}
	
	ListaNumeros.Imprimir();
	cout << endl;
	ListaNumeros.~ListaEnlazada();
	ListaNumeros.Imprimir();
	cout << endl;
	if(ListaNumeros.isVacia())
		cout << "Hemos borrado la lista tio" << endl;
	int nn = 28;
	ListaNumeros.Anadir(nn);
	ListaNumeros.Imprimir();
	cout << endl;
	ListaNumeros.Eliminar(nn);
	cout << nn << " eliminado"  << endl;
	if(ListaNumeros.isVacia())	
		cout<< "vacia";
	
		return 0;
}
