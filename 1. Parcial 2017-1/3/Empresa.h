#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Empresa
{
	int id;
	char nom[60];
	int hora_am1, hora_am2;
	int hora_pm1, hora_pm2;
	public:
		bool operator<( Empresa &x ) { return this->id<x.id; }
		void setValue(int value) { id = value; };
		void setId(int _id) { id = _id; }
		void setNom(char *_nom) { strcpy(nom, _nom); }
		void setHora_am1(int _h) { hora_am1 = _h; }
		void setHora_am2(int _h) { hora_am2 = _h; }
		void setHora_pm1(int _h) { hora_pm1 = _h; }
		void setHora_pm2(int _h) { hora_pm2 = _h; }
		void imprimir() { cout << id << " " << nom << " " << hora_am1 << " " << hora_am2 << " " << hora_pm1 << " " << hora_pm2 << endl; }
};

#endif
