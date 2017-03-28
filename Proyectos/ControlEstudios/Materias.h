#ifndef MATERIAS_H
#define MATERIAS_H
#include <iostream>
#include <stdlib.h>

class Materias
{
	int Codigo;
	char NombreMat[80];
	char UC;
	public:
		Materias();
		int getCodigo() { return Codigo; }
		char *getNombreMat() { return NombreMat; }
		int getUC() { return UC-'0'; }
		void imprimir() {
			std::cout << Codigo << " " << NombreMat << " " << UC << std::endl;
		}
};

#endif
