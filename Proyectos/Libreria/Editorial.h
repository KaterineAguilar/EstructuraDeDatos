#ifndef EDITORIAL_H
#define EDITORIAL_H
#include <iostream>
#include <cstring>
using namespace std;

class Editorial
{
	int Codigo;
	char Editor[20];
	public:
		Editorial();
		void setCodigo (int _Codigo) { Codigo = _Codigo; }
		void setEditorial (char _Editorial[20]) {strcpy (Editor, _Editorial); }
		void imprimir () { cout << Codigo << " " << Editor << endl; }
		int getCodigo() { return Codigo; }
		char *getNombre() { return Editor; }
};

#endif
