#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <cstring>
using namespace std;

class Libro
{
	int Codigo;
	char Descripcion[30];
	char Autor[20];
	public:
		Libro();
		void setCodigo (int _Codigo) { Codigo = _Codigo; }
		void setDescripcion (char _Descripcion[30]) { strcpy (Descripcion, _Descripcion); }
		void setAutor (char _Autor[20]) { strcpy (Autor, _Autor); }
		void imprimir () { cout << Codigo << " " << Descripcion << " " << Autor << endl;	}
		int getCodigo() { return Codigo; }
		string getDescripcion() { return string(Descripcion); }
		char *getAutor() { return Autor; }
};

#endif
