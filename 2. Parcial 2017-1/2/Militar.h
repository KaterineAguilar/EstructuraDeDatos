#ifndef MILITAR_H
#define MILITAR_H
#include <cstring>
#include <iostream>
using namespace std;
class Militar {
	
		int rango;
		char nombre[20];
	public:
		Militar(){};
		Militar(int r, char *n) { rango = r; strcpy(nombre, n); }
		void setRango(int r) { rango = r; }
		void setNombre(char *n) { strcpy(nombre, n); }
		int getRango() { return rango; }
		char *getNombre() { return nombre; }	
		friend ostream& operator<<(ostream& os, const Militar& dt) {  
	    os << dt.nombre << " Rango: " << dt.rango << endl;
		    return os;  
		} 
};

#endif
