#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <iostream>

class Articulos{
	int CodArt;
	char DescProd[60];
	/*char CedulaC[12];
	char NnomClie[60];
	int CodArt;
	char DescArt[60];
	int Cantidad;
	float Pvp;
	int Mes;
	char Observaciones[20];*/
	public:
		
		void imprimir() { std::cout << "Codigo:\t" << CodArt << "\t" << DescProd << std::endl; }
	
};

#endif
