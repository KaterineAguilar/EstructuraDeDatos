#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Militar.h"
#include "ListaDobCircular.h"
#include "ListaDobEnlazada.h"
#include <conio.h>

void josephus();

int main(int argc, char** argv) {
	
	josephus();
	
	return 0;
}

void josephus() {
	
	ifstream mil("milicia.txt");
	ifstream jug("jugada.txt");
	ListaDobCircular<Militar> jugadores;
	ListaDobEnlazada<string> nombres;
	Militar militarcito;
	string line;
	char *split;
	
	if (mil.fail()) {
		cout << "error al abrir milicia" << endl;
	} else {
		char *nom;
		int rang;
		
		while(getline(mil, line)) {			
			split = strtok(&line[0],",");
			nom = split;
			split = strtok(NULL,",");
			rang = atoi(split);	
			nombres.Anadir(nom);	
			militarcito.setNombre(nom);
			militarcito.setRango(rang);
			jugadores.AgregarSinOrden(militarcito);
		}


	}
	mil.close();
	
	cout << "Lista de Militares: " << endl <<endl;
	jugadores.Imprimir(1);
	cout << endl << endl;
	bool inRange = false;
	int currRang = 0;
	Militar p;
	if (jug.fail()) {
		cout << "Error al abrir jugada.txt" << endl;
	} else {
		int mov = 0;
		int dir = 0;
		while(getline(jug,line)) {			
			split = strtok(&line[0],",");
			mov = atoi(split);
			split = strtok(NULL,",");
			dir = atoi(split);			
			p = jugadores.GetActual();
			cout << p.getNombre() << " -- " << mov << " pasos.";
			if (dir==0)
				cout << "Sentido horario";
			else
				cout << "Sentido Antihorario";
			jugadores.Mover(mov,dir);
			p = jugadores.GetActual();		
			while (p.getRango() != currRang) {
				cout << endl << " jugador " << p.getNombre() << " Rango alto -> ";
				dir *= -1;
				jugadores.Mover(1,dir);
				p = jugadores.GetActual();
			}
			cout << " Sale: " << p.getNombre() << " Rango: " << p.getRango();
			jugadores.eliminar();
//			jugadores.Mover(0,0);
			p = jugadores.GetActual();
			currRang = p.getRango();		
			for( int i = 0; i < jugadores.getTam(); i++) {
				jugadores.Mover(1,1);			
				p = jugadores.GetActual();			
				if(p.getRango() < currRang)
					currRang = p.getRango();
			}
			getch();
			if(jugadores.getTam() == 1)
			 break;		
			cout << endl;
		}
		Militar p = jugadores.GetActual();
		cout << endl << endl << p.getNombre() << " ha escapado.";
	}	
	getch();
}
