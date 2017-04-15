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
   nuevo = new Nodo<T>(v, ultimo);
   ultimo = nuevo;
}

template<class T>
T Pilas_dinamicas<T>::Pop()
{
    Nodo<T> *_Nodo;
    T v;
    if(!ultimo) return 0;
    _Nodo = ultimo;
    ultimo = _Nodo->siguiente;
    v = _Nodo->valor;
    delete _Nodo;
    return v;
}

template <class T>
void Pilas_dinamicas<T>::Imprimir(){
	
	Nodo<T> *p = ultimo;
	
	while(p){
		cout<<p->get_info()<<" ";
		p=p->get_sig();
	}
	if(!p){
	//	cout<<"-Papelera Vacia"<<endl;
	}
}
#endif
