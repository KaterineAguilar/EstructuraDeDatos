#ifndef INSCRITOS_H
#define INSCRITOS_H
#include <iostream>

class Inscritos
{
	int Codigo;
	int Cedula;
	
	public:
		Inscritos();
		bool operator<( Inscritos &x ) { return this->Codigo<x.Codigo; }
		int getCodigo() { return Codigo; }
		int getCedula() { return Cedula; }
		void setValue(int _Codigo) { Codigo = _Codigo; }
		void imprimir() {
			std::cout << Codigo << " " << Cedula <<" " << std::endl;
		}
};

#endif
