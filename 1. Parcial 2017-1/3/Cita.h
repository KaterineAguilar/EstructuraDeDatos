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
		bool operator<( Cita &x ) { return strcmpi(fecha,x.fecha)<0; }
		bool operator>( Cita &x ) { return strcmpi(fecha,x.fecha)>0; }
		Cita();
		Cita(int _id, int _ced, char *_fecha, int _hora);
		void setId(int _id) { id = _id; }
		void setCed(int _ced) { ced = _ced; }
		void setFecha(char *_fecha) { strcpy(fecha,_fecha); }
		void setHora(int _hora) { hora = _hora; }
		void imprimir() { cout << id << " " << ced << " " << fecha << " Hora: " << hora << endl; }
		int getCita() { return id; }
		int getCedula() { return ced; }
		char *getFecha() { return fecha; }
};

Cita::Cita(){
	
}

Cita::Cita(int _id, int _ced, char *_fecha, int _hora)
{
	id = _id;
	ced = _ced;
	strcpy(fecha,_fecha);
	hora = _hora;
}

#endif
