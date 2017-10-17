#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

template<class T>
class Nodo {
	private:
		T valor;
		Nodo<T> *siguiente, *anterior;
	public:
		Nodo(T v, Nodo<T> *sig = NULL, Nodo<T> *ant = NULL) : valor(v),	siguiente(sig), anterior(ant) {}
		void setValor(T val){ valor = val; }
		T getValor(){ return valor; }
		void setSiguiente(Nodo<T> *p){ siguiente = p; }
		Nodo<T> *getSiguiente(){ return siguiente; }
		void setAnterior(Nodo<T> *p){ anterior = p; }
		Nodo<T> *getAnterior(){ return anterior; }
};

#endif
