#ifndef Bicola_H
#define Bicola_H
#include <iostream>
using namespace std;

template<class T> class Bicola;

template<class T>
class nodo {
	private:
		T valor;
		nodo<T> *sucesor, *predecesor;
	public:
		nodo(T v, nodo<T> *sig = NULL, nodo<T> *ant = NULL) {
			valor = v;
			sucesor = sig;
			predecesor = ant;
		}
		void setValor(T val){ valor = val; }
		T getValor(){ return valor; }
		void setSucesor(nodo<T> *p){ sucesor=p; }
		nodo<T> *getSucesor(){ return sucesor; }
		void setPredecesor(nodo<T> *p){ predecesor=p; }
		nodo<T> *getPredecesor(){ return predecesor; }
	friend class Bicola<T>;
};

template<class T>
class Bicola {
	private:
		nodo<T> *first, *last;
		int nNodes;
	public:
		Bicola() : first(NULL), last(NULL), nNodes(0) {}
		~Bicola();
		bool isEmpty();
		void push_front(T);
        void push_back(T);
		T pop_front();
        T pop_back();
		void print();
		void sort();
};

template<typename T>
void Bicola<T>::sort()
{
    T temp_data;
    nodo<T> *aux_node = first;
    nodo<T> *temp = aux_node;

    while (aux_node) {
        temp = aux_node;
        while (temp->getSucesor()) {
            temp = temp->getSucesor();
            if (aux_node->getValor() > temp->getValor()) {
                temp_data = aux_node->getValor();
                aux_node->setValor(temp->getValor());
                temp->setValor(temp_data);
            }
        }
        aux_node = aux_node->getSucesor();
    }
}
template<class T>
bool Bicola<T>::isEmpty()
{
	nodo<T> *p = first;
	if(!p)
		return true;
	return false;
}
template<typename T>
void Bicola<T>::push_front(T data_)
{
    nodo<T> *new_nodo = new nodo<T> (data_);
    nodo<T> *temp = first;

    if (!first) {
        first = new_nodo;
    } else {
        temp->setPredecesor(new_nodo);
        new_nodo->setSucesor(first);
        first = new_nodo;
        while (temp->getSucesor() != NULL) {
            temp = temp->getSucesor();
        }
        last = temp;
    }
    nNodes++;
}

template<typename T>
void Bicola<T>::push_back(T data_)
{
    nodo<T> *new_nodo = new nodo<T> (data_);
    nodo<T> *temp = first;
    nodo<T> *curr;

    if (!first) {
        first = new_nodo;
    } else {
        while (temp->getSucesor() != NULL) {
            curr = temp;
            temp = temp->getSucesor();
            temp->setPredecesor(curr);
            new_nodo->setPredecesor(temp);
        }
        temp->setSucesor(new_nodo);
        last = new_nodo;
    }
    nNodes++;
}

template<class T>
T Bicola<T>::pop_front()
{
    nodo<T> *Nodo;
    T v;
    Nodo = first;
    if(!Nodo)
        return 0;
    first = Nodo->getSucesor();
    v = Nodo->getValor();
    delete Nodo;
    nNodes--;
    if(!first)
        last = NULL;
    return v;
}
template<class T>
T Bicola<T>::pop_back()
{
    nodo<T> *Nodo;
    T v;
    if(!last)
        return 0;
    Nodo = last;
    last = Nodo->getSucesor();
    v = Nodo->getValor();
    delete Nodo;
    nNodes--;
    return v;
}
template<class T>
void Bicola<T>::print()
{
	nodo<T> *p = first;
	while(p){
		cout << p->getValor() << " ";
		p = p->getSucesor();
	}
}
template<class T>
Bicola<T>::~Bicola()
{
	while(first)
		pop_front();
	nNodes = 0;
}
#endif
