#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo.h"
using namespace std;

void cargar();

int main(int argc, char** argv) {
	
	cargar();
	
	return 0;
}

void cargar() {

	Grafo grafo(false,false);
	
	int letra = 65;
	char matriz[8][9];
	
	int i = 0, j=0;

	fstream file;
	string linea;
	
	file.open("laberinto.txt", ios::in);
	if(file.fail())
		cout << "error";
	else {
		while(getline(file,linea)) {
			
			for(int x = 0; x < linea.size(); x++) {
				if (linea[x] == '0') {
					matriz[i][x] = (char)letra;
					letra++;		
				}
				else
					matriz[i][x] = linea[x];	
			}
			i++;			
		}
	}
	file.close();

	for (int x = 0; x < 8; x++) {
		for ( int y = 0; y < 9; y++) {
			cout << matriz[x][y] << " ";
		}
		cout << endl;
	}
	cout << " --------" << endl;
	
	for(int x = 1; x < 7; x++) {
		for(int y = 1; y < 8; y++) {
			//cout << matriz[x][y] ;
			if((matriz[x][y] != '#' && matriz[x][y+1] != '#') && x<8) {
				//cout << matriz[x][y] << " " << matriz[x][y+1] << " ";
				Vertice *v1 = new Vertice(string(1,matriz[x][y]),0);
				Vertice *v2 = new Vertice(string(1,matriz[x][y+1]),0);
				grafo.agregar(v1,v2);					
			}
			if((matriz[x][y] != '#' && matriz[x][y-1] != '#') && x>0) {
				//cout << matriz[x][y] << " " << matriz[x][y-1] << " ";
				Vertice *v1 = new Vertice(string(1,matriz[x][y]),0);
				Vertice *v2 = new Vertice(string(1,matriz[x][y-1]),0);
				grafo.agregar(v1,v2);	
			}
			if((matriz[x][y] != '#' && matriz[x+1][y] != '#') && y<9) {
				//cout << matriz[x][y] << " " << matriz[x+1][y] << " ";
				Vertice *v1 = new Vertice(string(1,matriz[x][y]),0);
				Vertice *v2 = new Vertice(string(1,matriz[x+1][y]),0);
				grafo.agregar(v1,v2);	
			}
			if((matriz[x][y] != '#' && matriz[x-1][y] != '#') && y>0) {
				//cout << matriz[x][y] << " " << matriz[x-1][y] << " ";
				Vertice *v1 = new Vertice(string(1,matriz[x][y]),0);
				Vertice *v2 = new Vertice(string(1,matriz[x-1][y]),0);
				grafo.agregar(v1,v2);	
			}
		}
		
	}
	Vertice *inicio = new Vertice(string(1,'&'));
	Vertice *llegada = new Vertice(string(1,'*'));
	
	cout << "Lista de Adyacencias: " << endl << endl;
	grafo.imprimirListaAdyacencia();
	cout << endl << "Camino minimo: " << endl << endl;
	grafo.buscarCaminos_MinMaxVertices_Vertices(inicio, llegada);
	grafo.imprimirListaCaminos();
	
	Nodo<Camino>* recor = grafo.lista_caminos->getCab(); 
	ListaD<Vertice>* lista_vertices = recor->getInfo()->lista_vertices;
	
	Nodo<Vertice>* verts = lista_vertices->getCab();
/*	int cont = 0;
	while(verts) {
		cout << *verts->getInfo() << endl;
		verts = verts->getLink_suc();
		cont++;
	}*/
//	cout << cont;
	verts = lista_vertices->getCab();
	fstream salida;
	salida.open("ruta.txt", ios::out);
	
	while(verts) {
		string actual = verts->getInfo()->getIdentificador();
		char let = actual.c_str()[0];
		//cout << let;
		for(int x = 1; x < 7; x++) {
			for (int y = 1; y < 8; y++) {
				if(let == matriz[x][y])
					matriz[x][y] = 'R';
			}			
		}
		verts = verts->getLink_suc();
	}
		for(int x = 1; x < 7; x++) {
			for (int y = 1; y < 8; y++) {
				if(matriz[x][y] != 'R' && matriz[x][y] != '#')
					matriz[x][y] = '0';
			}			
		}
	
	cout << endl;
	
	for (int x = 0; x < 8; x++) {
		for ( int y = 0; y < 9; y++) {
			cout << matriz[x][y] << " ";
			salida << matriz[x][y];
		}
		cout << endl;
		salida << endl;
	}
	cout << "Matriz generada en ruta.txt" << endl;
	
}
