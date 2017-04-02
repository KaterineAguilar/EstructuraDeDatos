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
		int lon;
	public: 
		ArchivoBinario(char *nom) 				{ strcpy(nombre, nom); }
		~ArchivoBinario()						{ cerrar(); }
		void abrir(const std::_Ios_Openmode &t)	{ flujo.open(nombre, t); longi(); }
		void cerrar() 							{ if(flujo.is_open()) flujo.close(); }
		void longi()							{ lon = sizeof(T); }
		void leer(T &obj) 						{ flujo.read((char*)&obj, sizeof(T)); }
		void escribir(T &obj)					{ flujo.write((char*)&obj, sizeof(T)); }
		void posicionar(int x)					{ flujo.seekg(x*lon, ios::beg); }
		int tamano();
		bool fail()								{ return flujo.fail(); }
		bool isFinal()							{ return flujo.eof(); }
		void quicksort(vector <T>&vec, int primero, int ultimo);
		void inter(T&a1, T&a2);
};

template <class T>
void ArchivoBinario<T>::quicksort(vector <T>&vec, int primero, int ultimo){
	
	int i,j,central;
	T pivote;
	
	central = (primero + ultimo)/2;
	pivote = vec[central];
	
	i=primero;
	j=ultimo;
	
	do{
		while(vec[i] < pivote){
			i++;	
		} 
		while(vec[j] > pivote){
			j--;
		} 
		if(i<=j){
			inter(vec[i],vec[j]);
			i++;
			j--;		
		}	
	}while(i<=j);	
	
	if(primero < j)
		quicksort(vec,primero,j);
	if(i < ultimo)
		quicksort(vec,i,ultimo);
}


template <class T>
void ArchivoBinario<T>::inter(T&a1,T&a2) {
		T aux;
	aux=a1;
	a1=a2;
	a2=aux;
}


template <class T>
int ArchivoBinario<T>::tamano()
{
	flujo.seekg(0, ios::end);
	int total = flujo.tellp() / sizeof (T);
	flujo.seekg(0, ios::beg);
	
}
#endif
