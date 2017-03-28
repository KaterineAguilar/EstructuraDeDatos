#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Cliente
{
	int ced;
	char nom[30];
	public:
		bool operator<( Cliente &x ) { return (string)nom<(string)x.nom; }
		void setCedula(int _ced) { ced = _ced; };
		void setNombre(char *_nom) { strcpy(nom, _nom); };
		void imprimir() { cout << ced << " " << nom << endl; }
		char *getNom() { return nom; }
};

#endif
