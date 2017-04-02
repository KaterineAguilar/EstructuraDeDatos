#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <time.h>
#include "Pilas_dinamicas.h"
#include "Colas_dinamicas.h"
#include "Jugador.h"

using namespace std;

void generarTablero(string path, int *&tablero, int &tam, int &fil, int &col);
void mostrarTablero(int *tablero, int tamTablero, int col, Jugador *jugador, int cantJugadores);
void iniciarPartida(Jugador **&jugadores, int &cantJugadores, int col, int *tablero, int tamTablero, Colas_dinamicas <Jugador*> &turnos, Pilas_dinamicas <int> casillas[]);
void color(int c);
int dado();

int main(int argc, char** argv) {
	
	Colas_dinamicas <Jugador*> turnos;
	
	
	int *tablero;
	int fil, col;
	int tamTablero;
	int cantJugadores;
	Jugador **jugadores;
	
	srand(time(NULL));
	generarTablero("tablero.txt", tablero, tamTablero, fil, col);
	Pilas_dinamicas <int> casillas[tamTablero];
	iniciarPartida(jugadores, cantJugadores, col, tablero, tamTablero, turnos, casillas);

	cout << endl << endl;

	Jugador *mayor;
	mayor = jugadores[0];
	for(int i = 0; i < cantJugadores; i++)	{
		jugadores[i]->informacion();
		if(jugadores[i]->getPuntaje() > mayor->getPuntaje())
			mayor = jugadores[i];
	}
	
		
	cout << endl << endl;		
	color(mayor->getColor());
	cout << "!!!1GANADOR!!! ";
	mayor->informacion();
	color(7);
	
	
	
	return 0;
}

void iniciarPartida(Jugador **&jugadores, int &cantJugadores, int col, int *tablero, int tamTablero, Colas_dinamicas <Jugador*> &turnos, Pilas_dinamicas <int> casillas[])
{
	do{
		cout << "Cantidad de Jugadores?: ";
		cin >> cantJugadores;	
		
	}while(cantJugadores<1);
	
	jugadores = new Jugador*[cantJugadores];
	int _color = 2;
	for(int i = 0; i < cantJugadores; i++) {
		int turno = dado();
		string linea;
		fflush(stdin);
		cout << "Nombre jugador " << i+1 << ": ";
		getline(cin, linea);
		cout << endl;
		jugadores[i] = new Jugador(linea,0,0, turno, _color++);
		system("cls");
	}
	
	//ORDENANDO POR TURNOS CON BURBUJA JAJA
	Jugador *temp;
	for(int i = 0; i < cantJugadores; i++){
		for(int j = 0 ; j < cantJugadores-1; j++){
			if(jugadores[j]->getTurno() < jugadores[j+1]->getTurno()){
				temp = jugadores[j];
				jugadores[j] = jugadores[j+1];
				jugadores[j+1] = temp;	
			}	
		}		
	}
	//ORDENANDO POR TURNOS CON BURBUJA JAJA
	//CREANDO PILA PARA CADA POSICION DEL TABLERO
	for(int i = 0; i < tamTablero; i++) {
		if(tablero[i] != 0)
			casillas[i].Push(tablero[i]);
		else
			casillas[i].Push(0);
	}
	//CREANDO PILA PARA CADA POSICION DEL TABLERO	
	//AÑADIENDO A LA COLA DE TURNOS A LOS JUGADORES
	for(int i = 0; i < cantJugadores; i++){
		color(7);
		turnos.Anadir(jugadores[i]);
		color(jugadores[i]->getColor());
		cout << "Turno " << i+1 << ": " << jugadores[i]->getNombre() << endl;
	}
	color(7);
	//AÑADIENDO A LA COLA DE TURNOS A LOS JUGADORES	
	//PARA COMPROBAR QUE EL MAPA Y LAS PILAS ESTEN CORRECTAS//
//	for(int i = 0; i < tamTablero; i++) {
//		cout << tablero[i] << " ";
//	}
//	cout << endl << endl;
//	for(int i = 0; i < tamTablero; i++) {
//		casillas[i].Imprimir();
//	}
	//PARA COMPROBAR QUE EL MAPA Y LAS PILAS ESTEN CORRECTAS//
	
	Jugador *JugadorEnTurno;
	int cont = 0;
	bool game = true, help = false;
	int mov = 1;
	int emergencyiterator=0;
	while(game) {
		for(int i = 1; i <= cantJugadores; i++){
			mov = dado();
			JugadorEnTurno = turnos.Leer();
			if(JugadorEnTurno->getPosicion() < tamTablero) {
				JugadorEnTurno->incPosicion(mov);
			}
			if(JugadorEnTurno->getPosicion() > tamTablero){
				JugadorEnTurno->setPosicion(tamTablero);
			}
			int num= 0;
			int pos = JugadorEnTurno->getPosicion()-1;
			if(tablero[pos] != 0) {
				if(JugadorEnTurno->getPuntaje() <= 400) {
					help = false;
					int valor1 = casillas[pos].Pop();
					JugadorEnTurno->anadirPuntaje(valor1); //añadiendo puntaje a la cola de puntajes
					JugadorEnTurno->incPuntaje(valor1);
					tablero[pos] = casillas[pos].Pop();
					while(JugadorEnTurno->getPuntaje() > 400) {
						int valor2 = JugadorEnTurno->quitarPuntaje(); //quitando puntaje de la cola del jugador
						JugadorEnTurno->decPuntaje(valor2);
						casillas[pos].Push(valor2);
						tablero[pos] = valor2;
						help = true;
					}
					if(help) {
						JugadorEnTurno->anadirPuntaje(valor1);
						JugadorEnTurno->incPuntaje(valor1);
					}
					
				}
			}
			
			for(int i = 0; i < cantJugadores; i++)
				if(jugadores[i]->getNombre() == JugadorEnTurno->getNombre()) 
					if(JugadorEnTurno->getPosicion()==tamTablero)
						cont++;
			if(cont == cantJugadores) game=false;
			if(emergencyiterator == tamTablero*cantJugadores) game = false;
			
			cout << "**************************************" << endl;
			color(JugadorEnTurno->getColor());
			JugadorEnTurno->informacion();
			cout << endl;
			mostrarTablero(tablero, tamTablero, col, JugadorEnTurno, cantJugadores);
			cout << "**************************************" << endl;
			turnos.Anadir(JugadorEnTurno);
			emergencyiterator++;
		}
	}
	Jugador *aux;
	for(int i = 0; i < cantJugadores; i++) {
		aux = turnos.Leer();
		for(int j = 0; j < cantJugadores; j++) 
			if(jugadores[j]->getNombre() == aux->getNombre())
				jugadores[j] = aux;
	}
}

void generarTablero(string path, int *&tablero, int &tam, int &fil, int &col)
{
	fstream arch;
	arch.open(path.c_str(),ios::in);
	string linea;
	char *split;
	
	if(arch.fail()) 
		cout << "Error al abrir el archivo " << path << endl;
	else {
		getline(arch,linea);
		split = strtok(&linea[0]," ");
		fil = atoi(split);
		split = strtok(NULL," ");
		col = atoi(split);
		//----------------------------------
		tam = fil*col;
		//----------------------------------
		Pilas_dinamicas <int> pil;
		tablero = new int[tam];
		//----------------------------------
		while (getline(arch,linea)) {
			split = strtok(&linea[0]," ");
			while(split != NULL) {
				int a = atoi(split);
				pil.Push(a);
				split = strtok(NULL, " ");
			}
		}
		int a = 0;
		for (int i = 0; i < tam; i++) 
			tablero[i] = pil.Pop();

	}
}

int dado()
{
	return rand()%6+1;
}

void mostrarTablero(int *tablero, int tamTablero, int col, Jugador *jugador, int cantJugadores)
{
	int c= 1, salto = 0;

	for(int i = tamTablero-1; i >= 0; i--) {
//	for(int i = 0; i < tamTablero; i++) {
		color(7);
		if(salto == col){
			cout << endl;
			salto = 0;
		}
		if(tamTablero - c  == jugador->getPosicion()-1)		
			color(jugador->getColor());
		else if(jugador->getPosicion() == tamTablero)
			color(jugador->getColor());
		if(i == jugador->getPosicion()-1)
			color(jugador->getColor());
		else
			color(7);
			

				
		cout << tablero[i] << "\t";
		salto++;
		c++;
	}
	cout << endl << endl;
}
void color(int c){
	HANDLE consol;
	consol = GetStdHandle
		(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
		(consol, c);
}
