typedef int Dato;
// archivo de cabecera Nodo.h
#ifndef _NODO_H
#define _NODO_H
class Nodo
{
	protected:
		Dato dato;
		Nodo* enlace;
	public:
		Nodo(Dato t)
		{
			dato = t;
			enlace = 0; // 0 es el puntero NULL en C++
		}
		Nodo(Dato p, Nodo* n) // crea el nodo y lo enlaza a n
		{
			dato = p;
			enlace = n;
		}
		Dato datoNodo() const{
			return dato;
		}
		Nodo* enlaceNodo() const
		{
			return enlace;
		}
		void ponerEnlace(Nodo* sgte)
		{
			enlace = sgte;
		}
};
#endif
//Dado que los datos que se puede incluir en una lista pueden ser de cualquier tipo (entero,
//real, caracter o cualquier objeto), puede declararse un nodo genérico y, en consecuencia, una
//lista genérica con las plantillas de C++:
template <class T> class NodoGenerico
{
	protected:
		T dato;
		NodoGenerico <T>* enlace;
	public:
		NodoGenerico (T t)
		{
			dato = t;
			enlace = 0;
		}
		NodoGenerico (T p, NodoGenerico<T>* n)
		{
			dato = p;
			enlace = n;
		}
		T datoNodo() const
		{
			return dato;
		}
		NodoGenerico<T>* enlaceNodo() const
		{
			return enlace;
		}
		void ponerEnlace(NodoGenerico<T>* sgte)
		{
			enlace = sgte;
		}
};
