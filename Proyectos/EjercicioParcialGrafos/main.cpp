#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "Grafo.h"

using namespace std;

class Datos {
	public:
		string vertice_partida;
		string vertice_llegada;
		int vertices_recorridos;
};

void cargar();

int main() {
	
	cargar();
	
	
}

void cargar() {
	

	Grafo *g = new Grafo("aristas.txt",' ', false, true);
	
	g->imprimirListaAdyacencia();
	cout << "----------------------";
	
	string id_partida;
	string id_llegada;
	Vertice *partida;
	Vertice *llegada;
	
	cout << "desde donde quiere partir: ";
	cin >> id_partida;
	partida = new Vertice(id_partida);
	cout << endl << "a donde queire llegar:";
	cin >> id_llegada;
	llegada = new Vertice(id_llegada);
	int opc = 1;
	
	vector<Datos> lista_datos;
	Datos a;
	
	do {
		g->buscarCaminos_MinMaxLongitud_Vertices(partida, llegada);
		int algo = g->imprimirListaCaminos();
		cout << "Vertices recorridos " << algo << endl	;
		a.vertice_partida = id_partida;
		a.vertice_llegada = id_llegada;
		a.vertices_recorridos = algo;
		lista_datos.push_back(a);
		cout << "desea continuar con sus caminos? 1=si 0=no";
		cin >> opc;
		if (opc==1) {		
			cout << endl << "a donde quiere llegar desde aqui?:";	
			id_partida = id_llegada;
			cin >> id_llegada ;
			partida = llegada;
			llegada = new Vertice(id_llegada);
		}
		//system("pause>0")	;
	} while(opc);
	
	Datos aux;
	
		aux = lista_datos[0];
	for(int i = 1; i < lista_datos.size(); i++) {
		if(aux.vertices_recorridos > lista_datos[i].vertices_recorridos)
			aux = lista_datos[i];
			//cout << "desde " << aux.vertice_partida << " hasta " << aux.vertice_llegada << " con: " << aux.vertices_recorridos << endl;
	}
	cout << "desde " << aux.vertice_partida << " hasta " << aux.vertice_llegada << " con: " << aux.vertices_recorridos << endl;
//	cout << "Camino que visito menor numero de vertices: " << endl << endl;
//	cout << "desde " << aux.vertice_partida << " hasta " << aux.vertice_llegada << " con: " << aux.vertices_recorridos << endl;
	
//	ListaD <Vertice> *lista_vert;
//	lista_vert.agregar(new Vertice(id_partida))
	
	
	//g->imprimirListaCaminos();
	
	
		
	
}
