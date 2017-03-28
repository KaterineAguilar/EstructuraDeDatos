#ifndef ARCHIVOBINARIO_H
#define ARCHIVOBINARIO_H
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class ArchivoBinario{
	private:		
		fstream flujo;
		char nombre[50];
	public: 
		ArchivoBinario(char *nom) 				{ strcpy(nombre, nom); }
		~ArchivoBinario()						{ cerrar(); }
		void abrir(const std::_Ios_Openmode &t)	{ flujo.open(nombre, t); }
		void cerrar() 							{ if(flujo.is_open()) flujo.close(); }
		void leer(T &obj) 						{ flujo.read((char*)&obj, sizeof(T)); }
		void escribir(T &obj)					{ flujo.write((char*)&obj, sizeof(T)); }
		int tamano();							
		bool fail()								{ return flujo.fail(); }
		bool isFinal()							{ return flujo.eof(); }
};

template <class T>
int ArchivoBinario<T>::tamano()
{
	flujo.seekg(0, ios::end);
	int total = flujo.tellp() / sizeof (T);
	flujo.seekg(0, ios::beg);
	return total;
}
#endif
