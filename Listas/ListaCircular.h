#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <iostream>
using namespace std;

template<class T> class ListaCircular;

template<class T>
class nodo {
	private:
		T valor;
		nodo<T> *siguiente;
	public:
		nodo(T v, nodo<T> *sig = NULL) : valor(v),	siguiente(sig){};
		void setValor(T _valor) { valor = _valor; }
		void setSiguiente(nodo<T> *p) { siguiente = p; }
		T getValor() { return valor; }
		Nodo<T> *getSiguiente() { return siguiente;	}
	friend class ListaCircular<T>;
};

template<class T>
class ListaCircular {
	private:
		nodo<T> *actual, *cab, *p;
	public:
		ListaCircular() { actual = NULL; cab = NULL; p = NULL; }
		~ListaCircular();
		void Insertar(T v);
		void Borrar(T v);
		bool ListaVacia() { return actual == NULL; }
		void Mostrar();
		void Siguiente();
		bool Actual() { return actual != NULL; }
		T ValorActual() { return actual->valor; }
};

template<class T>
ListaCircular<T>::~ListaCircular() {
   nodo<T> *cab, *p;
   while (actual->siguiente != actual) {
      nodo = actual->siguiente;
      actual->siguiente = nodo->siguiente;
      delete nodo;
   }
   delete actual;
   actual = NULL;
}

template<class T>
void ListaCircular<T>::Insertar(T v) {
   nodo<T> *nuevo;
   nuevo = new nodo<T>(v);
//	if (ListaVacia()) {
//		cab = nuevo;
//		cab->setSiguiente(cab);
//		return 1;
//	}
//	p = cab;
//	do {
//		if (v < p->getValor()) 
//			break;
//		p = p->getSiguiente();	
//	} while (p != cab);
//	
//	if (v < cab->getValor()) 
//		cab = nuevo;
//	nuevo->setSiguiente(p);
//	return 1;
//   
	if (actual == NULL) 
		actual = nuevo;
	else 
		nuevo->setSiguiente(actual->getSiguiente());
	actual->setSiguiente(nuevo);
}

template<class T>
void ListaCircular<T>::Borrar(T v) {
	nodo<T> *Nodo;
	
	Nodo = actual;
	do {
		if (actual->siguiente->valor != v)
			actual = actual->siguiente;
	} while (actual->siguiente->valor != v && actual != Nodo);
	
	if(actual->siguiente->valor == v) {
		if(actual == actual->siguiente) {
			delete actual;
			actual = NULL;
		} else {
			Nodo = actual->siguiente;
			actual->siguiente = Nodo->siguiente;
			delete Nodo;
		}
	}
}

template<class T>
void ListaCircular<T>::Mostrar() {
   nodo<T> *Nodo = actual;
   do {
      cout << Nodo->valor << "-> ";
      Nodo = Nodo->siguiente;
   } while(Nodo != actual);
   cout << endl;
}

template<class T>
void ListaCircular<T>::Siguiente() {
	if(actual) 
		actual = actual->siguiente;
}
#endif
