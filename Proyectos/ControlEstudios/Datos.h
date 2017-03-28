#ifndef DATOS_H
#define DATOS_H
#include <iostream>
#include <cstring>

class Datos
{
		int Cedula;
		char Nombre[30];
	public:
		Datos();
		int getCedula() { return Cedula; }
		char *getNombre() { return Nombre; }
		void imprimir() {
			std::cout << Cedula << " " << Nombre << std::endl;
		}

};

#endif
