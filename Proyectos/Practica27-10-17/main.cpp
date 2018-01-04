#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ArbolBB.h"
#include "ArbolAVL.h"

using namespace std;

void cargar(ArbolBB<int> ListaArbolitos[]);
void verificarAVL(ArbolBB<int> ListaArbolitos[], int);
void NodoNivel(ArbolBB<int> ListaArbolitos[], int);
void ReestructurarAVL(ArbolBB<int> ListaArbolitos[], ArbolAVL<int> ListaArbolitosA[], int);

int main(int argc, char** argv) {
	
	int CantidadArbolitos = 13;
	ArbolBB<int> ListaArbolitos[CantidadArbolitos];
	ArbolAVL<int> ListaArbolitosA[CantidadArbolitos];
	
	cargar(ListaArbolitos);

	for (int i =0;i < CantidadArbolitos-1; i++) {
		cout << "Arbol " << i+1 << ":" << endl;
		ListaArbolitos[i].imprimir(2);
		cout << "Altura: " << ListaArbolitos[i].AlturaArbol();
		cout << endl << "------------------" << endl;		
	}

	verificarAVL(ListaArbolitos, CantidadArbolitos);
	NodoNivel(ListaArbolitos, CantidadArbolitos);
	ReestructurarAVL(ListaArbolitos, ListaArbolitosA, CantidadArbolitos);
	return 0;
}
void ReestructurarAVL(ArbolBB<int> ListaArbolitos[], ArbolAVL<int> ListaArbolitosA[], int CantidadArbolitos) {
	int cont = 0;
	int cant = 0;
	for (int i = 0; i < CantidadArbolitos-1; i++) {
		cont = 0;
		if ( ListaArbolitos[i].EsAVL(cont, true) == 0) {
		} else
			cant++;
	}
	cout << endl << endl << "Cantidad de arboles que se pueden reestructurar: " << cant << endl << endl;
}

void NodoNivel(ArbolBB<int> ListaArbolitos[], int CantidadArbolitos) {
	cout << endl << "----------------------" << endl;
	int Nivel = 0;
	cout << "Nivel: ";
	cin >> Nivel;
	for (int i = 0; i < CantidadArbolitos-1; i++) {
		cout << "Arbol " << i+1 << ":" << endl;
		ListaArbolitos[i].Lugar(Nivel, true);
		cout << endl << endl;
	}
	
}

void verificarAVL(ArbolBB<int> ListaArbolitos[], int CantidadArbolitos) {
	int ArbolesAVL = 0;
	int cont = 0;
	ArbolBB<int> aux;
	for (int i = 0; i < CantidadArbolitos-1; i++) {
		cont = 0;
		aux = ListaArbolitos[i];
		if (aux.EsAVL(cont, true) == 0)
			ArbolesAVL++;	
	}
	cout << endl << "cantidad de ArbolesBB que son AVL: " << ArbolesAVL << endl;
}

void cargar(ArbolBB<int> ListaArbolitos[]) {
	
	fstream file("claves.txt",ios::in);
	string line;
	char *split;
	int i = 0;
	if (file.fail())
		cout << "Error al abrir el archivo claves.txt" << endl;
	else {
		while (getline(file,line)) {
			split = strtok(&line[0], ",");
			while (split) {
				ListaArbolitos[i].Anadir(atoi(split));
				split = strtok(NULL, ",");	
			}
			i++;
		}
	}
	
}
