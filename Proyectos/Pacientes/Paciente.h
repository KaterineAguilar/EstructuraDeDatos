#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <cstdlib>

class Paciente
{
	int ced;
	char nom[30];
	int edad;
	public:
		friend ostream& operator<<(ostream& os, const Paciente& dt)
		{  
	    os << dt.ced << " " << dt.nom << " " << dt.edad;
		    return os;  
		} 
		void setCedula(int _ced) { ced = _ced; }
		void setNom(char *_nom) { strcpy(nom, _nom); }
		void setEdad(int _edad) { edad = _edad; }
		void imprimir() { std::cout << ced << " " << nom << " " << edad; }
		int getCedula() { return ced; }
		char *getNom() { return nom; }
		int getEdad() { return edad; }
};

#endif
