#include <iostream>
#include <vector>
#include "ArchivoB.h"
#include "Articulos.h"

using namespace std;

int main(int argc, char** argv) {
	
	ArchivoBinario <Articulos> inArt("articulos.dat");
	
	inArt.abrir("in");
	Articulos ar;
	int cantArt = inArt.tamanio();
	vector <Articulos> ListaArticulos;
//	Articulos *ListaArticulosD = new Articulos[cantArt];
	
	int cont=0;
	while(true) {
		inArt.leer(ar);
		if(inArt.isFinal())
			break;
		ListaArticulos.push_back(ar);
//		ListaArticulosD[cont++] = ar;
	}
	
	for(int i = 0; i < cantArt; i++) {
		ListaArticulos[i].imprimir();
//		ListaArticulosD[i].imprimir();	
	}
	inArt.cerrar();
	return 0;
}
