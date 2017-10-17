#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include "ListaEnlazada.h"
#include <cstring>
class Departamento {
	private:
		char des[45];
		int  cod;
	public:
		ListaEnlazada<Producto> *sublis;
		Departamento() { }
		Departamento (char *v1, int v2) { 
			strcpy(des,v1); 
			cod = v2; 
			sublis = new ListaEnlazada<Producto>;
		}
		char *get_des( ) { return des; }
		int get_cod( ) { return cod; }
		bool operator <( Departamento c ) { return this->cod <c.cod; }
		bool operator==( Departamento c ) { return this->cod==c.cod; }
		friend ostream & operator<<(  ostream &os, Departamento  c ) { 
			os << c.cod << " " << c.des << endl;
			return os;
		} 
		void imprimir() { cout << cod << " " << des << endl; }
};

#endif
