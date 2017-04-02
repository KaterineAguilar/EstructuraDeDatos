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
   /* Crear un nodo nuevo */
   /* Este será el último nodo, no debe tener siguiente */
   nuevo = new nodo<T>(v);
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(ultimo) ultimo->siguiente = nuevo;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!primero) primero = nuevo;
}

template<class T>
T Colas_dinamicas<T>::Leer()
{
   nodo<T> *Nodo; /* variable auxiliar para manipular nodo */
   T v;      /* variable auxiliar para retorno */
   /* Nodo apunta al primer elemento de la pila */
   Nodo = primero;
   if(!Nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   primero = Nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = Nodo->valor;
   /* Borrar el nodo */
   delete Nodo;
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!primero) ultimo = NULL;
   return v;
}
#endif
