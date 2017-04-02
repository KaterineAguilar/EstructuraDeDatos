#ifndef PILAS_DINAMICAS_H
#define PILAS_DINAMICAS_H
#include <iostream>
using namespace std;

template<class T> class Pilas_dinamicas;

template<class T>
class Nodo {
	private:
		T valor;
		Nodo<T> *siguiente;
	public:
		Nodo(T v, Nodo<T> *sig = NULL) : valor(v), siguiente(sig) {}
		
		void set_info(T val){ 
			valor=val;
		}
		void set_sig(Nodo<T> *p){
				siguiente=p;
		}
		T get_info(){
			return valor;
		}
		Nodo<T> *get_sig(){
			return siguiente;
		}
		
	friend class Pilas_dinamicas<T>;
};

template<class T>
class Pilas_dinamicas {
	private:
		Nodo<T> *ultimo;
	public:
		Pilas_dinamicas() : ultimo(NULL) {}
		~Pilas_dinamicas();
		
		void Push(T v);
		T Pop();
		void Imprimir();
};

template<class TIPO>
Pilas_dinamicas<TIPO>::~Pilas_dinamicas()
{
   while(ultimo) Pop();
}

template<class T>
void Pilas_dinamicas<T>::Push(T v)
{
   Nodo<T> *nuevo;

   /* Crear un nodo nuevo */
   nuevo = new Nodo<T>(v, ultimo);
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   ultimo = nuevo;
}

template<class T>
T Pilas_dinamicas<T>::Pop()
{
    Nodo<T> *_Nodo; /* variable auxiliar para manipular nodo */
    T v;      /* variable auxiliar para retorno */

    if(!ultimo) return 0; /* Si no hay nodos en la pila retornamos 0 */
    /* Nodo apunta al primer elemento de la pila */
    _Nodo = ultimo;
    /* Asignamos a pila toda la pila menos el primer elemento */
    ultimo = _Nodo->siguiente;
    /* Guardamos el valor de retorno */
    v = _Nodo->valor;
    /* Borrar el nodo */
    delete _Nodo;
    return v;
}

template <class T>
void Pilas_dinamicas<T>::Imprimir(){
	
	Nodo<T> *p = ultimo;
	
	while(p){// SIGNIFICA QUE IMPRIME SOLO SI HAY VALOR AHI 
		
		cout<<p->get_info()<<" ";
		p=p->get_sig();
	}
	
	if(!p){
		
	//	cout<<"-Papelera Vacia"<<endl;
	}
}
#endif
