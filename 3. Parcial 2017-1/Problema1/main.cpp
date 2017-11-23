#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include "ArbolAVL.h"
using namespace std;

void cargar();

int main(int argc, char** argv) {
	
	cargar();
	
	return 0;
}

void cargar() {
	fstream file;
	file.open("claves.txt", ios::in);
	string line;
	char *split;
	ArbolAVL<int> arbolito;
	
	if (file.fail())
		cout << "error al abrir el archivo claves.txt";
	else {
		while(getline(file,line)) {
			split = strtok(&line[0]," ");
			while(split) {
				arbolito.Anadir(atoi(split));
				split = strtok(NULL, " ");
			}
		}
	}
	//arbolito.imprimir(2);
	cout << "Recorrido en Anchura: "<< endl;
	arbolito.mostrar(arbolito.AlturaArbol()*arbolito.NumeroNodos(),arbolito.AlturaArbol()+1,16);
	cout << endl << endl;
	cout << "Recorrido en InOrden" << endl << endl;
	arbolito.imprimir(2);
	
	int izq = 0, der = 0;
	NodoAVL<int> *aux;
	arbolito.Raiz();
	aux = arbolito.NodoActual();
	
	izq = arbolito.SumaClaves(aux->getIzquierdo()) + aux->getValor();
	der = arbolito.SumaClaves(aux->getDerecho()) + aux->getValor();
	cout << endl << endl << izq << " " << der << endl;
	if(izq > der) {
		aux = aux->getIzquierdo();
		cout << endl << "Rama por la izquierda " << izq << endl << endl;		
	} else {
		aux = aux->getDerecho();
		cout << endl << "Rama por la derecha " << der << endl << endl;
	}
	arbolito.imprimirSubArbol(aux);
	
}
