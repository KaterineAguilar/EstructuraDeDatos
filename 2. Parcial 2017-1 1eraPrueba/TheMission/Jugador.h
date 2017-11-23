#ifndef JUGADOR_H
#define JUGADOR_H
#include "Colas_dinamicas.h"

class Jugador
{
	string nombre;
	int puntaje;
	int posicion;
	int turno;
	int color;
	Colas_dinamicas<int> colaPuntaje;
	public:
		Jugador(string _nombre, int _puntaje, int _posicion, int _turno, int _color) {
			nombre = _nombre;
			puntaje = _puntaje;
			posicion = _posicion;
			turno = _turno;
			color = _color;
		}
		bool operator>( Jugador &x ) { return this->puntaje>x.puntaje; }
		void incPuntaje(int _puntaje) { puntaje += _puntaje; }
		void decPuntaje(int _puntaje) { puntaje -= puntaje; }
		void incPosicion(int _posicion) { posicion += _posicion; }
		void setPosicion(int _posicion) { posicion = _posicion; }
		int getPosicion() { return posicion; }
		int getPuntaje() { return puntaje; }
		string getNombre() { return nombre; }
		int getTurno() { return turno; }
		int getColor() { return color; }
		Colas_dinamicas<int> getColaPuntaje() { return colaPuntaje; }
		int anadirPuntaje(int _puntaje) { colaPuntaje.Anadir(_puntaje); }
		int quitarPuntaje() { return colaPuntaje.Leer(); }
		void informacion() { cout << nombre << " Puntaje: " << puntaje << " Posicion: " << posicion << endl; }
};

#endif
