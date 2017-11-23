#ifndef COLAS_DINAMICAS_H
#define COLAS_DINAMICAS_H
#include <iostream>
using namespace std;

template<class T> class Colas_dinamicas;

template<class T>
class nodo {
	private:
		T valor;
		nodo<T> *siguiente;
	public:
		nodo(T v, nodo<T> *sig = NULL) {
			valor = v;
			siguiente = sig;
		}
	
	friend class Colas_dinamicas<T>;
};

template<class T>
class Colas_dinamicas {
	private:
		nodo<T> *primero, *ultimo;
	public:
		Colas_dinamicas() : primero(NULL), ultimo(NULL) {}
		~Colas_dinamicas();
		void Anadir(T v);
		T Leer();
};

template<class T>
Colas_dinamicas<T>::~Colas_dinamicas()
{
   while(primero) Leer();
}

template<class T>
void Colas_dinamicas<T>::Anadir(T v)
{
   nodo<T> *nuevo;
   nuevo = new nodo<T>(v);
   if(ultimo) ultimo->siguiente = nuevo;
   ultimo = nuevo;
   if(!primero) primero = nuevo;
}

template<class T>
T Colas_dinamicas<T>::Leer()
{
   nodo<T> *Nodo;
   T v;
   Nodo = primero;
   if(!Nodo) return 0;
   primero = Nodo->siguiente;
   v = Nodo->valor;
   delete Nodo;
   if(!primero) ultimo = NULL;
   return v;
}
#endif
