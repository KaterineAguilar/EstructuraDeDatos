#ifndef CITA_H
#define CITA_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Cita
{
	int id;
	int ced;
	char fecha[14];
	int hora;
	public:
		void setId(int _id) { id = _id; }
		void setCed(int _ced) { ced = _ced; }
		void setFecha(char *_fecha) { strcpy(fecha,_fecha); }
		void setHora(int _hora) { hora = _hora; }
		void imprimir() { cout << id << " " << ced << " " << fecha << " " << hora << endl; }
		int getCita() {return id; }
		int getCedula() {return ced; }
};

#endif
