#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "node.h"

template <class T>
class ListaCircular
{
      node<T> *cab, *p;
      int numeroNodos;
 public:
       ListaCircular() { cab=NULL;  numeroNodos=0;         }
       bool Vacia()    { return cab==NULL;   }
       T    GetActual(){ return p->getInfo(); }
       int  Agregar ( T ele );
       int  AgregarSinRepetir ( T ele );
       int  AgregarSinOrden( T ele );
       void Mover   ( int pos, int band=1 );
       void Imprimir( int band=1 );
       void ImprimirLineal( int band=1 );
	   void eliminar( int band ,T &elemento);
	   int getNumNodos(){return numeroNodos; };	
	   void setPenCab(){p=cab;};          
}; 

template <class T>
int ListaCircular<T>::Agregar ( T ele )
{
      node<T> *pnue;
      pnue= new node<T>;
      if ( !pnue )  return 0; 
      pnue->setInfo(ele);
	  numeroNodos++;
      if ( Vacia() ) 
      {
           cab= pnue;
           cab->setNext( cab );
           cab->setPrevious( cab ); 
           return 1;
      }
      p= cab;
      do {
          if ( ele<p->getInfo() ) break;
          p= p->getNext();
      }while ( p!=cab );
      if ( ele<cab->getInfo() ) cab=pnue;
      pnue->setNext(p);
      pnue->setPrevious(p->getPrevious());       
      p->getPrevious()->setNext(pnue);
      p->setPrevious(pnue);
     
      return 1;
}


template <class T>
int ListaCircular<T>::AgregarSinRepetir ( T ele )
{
      node<T> *pnue;
      pnue= new node<T>;
      if ( !pnue )  return 0; 
      pnue->setInfo(ele);
      if ( Vacia() ) 
      {
           cab= pnue;
           cab->setNext( cab );
           cab->setPrevious( cab ); 
		   numeroNodos++;
           return 1;
      }
      p= cab;
      do {
          if ( ele<p->getInfo() || ele==p->getInfo()) break;
          p= p->getNext();
      }while ( p!=cab );
      if(!(ele==p->getInfo())){

		  if ( ele<cab->getInfo()) cab=pnue;
		  pnue->setNext(p);
	      pnue->setPrevious(p->getPrevious());       
	      p->getPrevious()->setNext(pnue);
	      p->setPrevious(pnue);
		  numeroNodos++;
		}
      return 1;
}

template <class T>
int ListaCircular<T>::AgregarSinOrden( T ele )
{
      node<T> *pnue;
      pnue= new node<T>;
      if ( !pnue )  return 0; 
      numeroNodos++;
      pnue->setInfo(ele);
      if ( Vacia() ) 
      {
           cab= pnue;
           cab->setNext( cab );
           cab->setPrevious( cab ); 
           return 1;
      }
      p= cab;
      do {
          p->getNext();
          if ( !p->getInfo() ) break;
      }while ( p!=cab );
      pnue->setNext(p);
      pnue->setPrevious(p->getPrevious());       
      p->getPrevious()->setNext(pnue);
      p->setPrevious(pnue);
      return 1; 
}

template <class T>
void ListaCircular<T>::Imprimir( int band )
{
  if ( Vacia() ) return;
  p= cab;
  if ( band )
  {
    cout<<"Recorrido hacia adelante:\n";
    do 
   {
      cout<<"Elemento: "<<p->getInfo()<<endl;
      p= p->getNext();
   } while ( p!=cab );
  }
  else
  {
    cout<<"Recorrido hacia atras:\n";
    do
   {      
      p= p->getPrevious();            
      cout<<"Elemento: "<<p->getInfo()<<endl;
   } while ( p!=cab );
  }
}


template <class T>
void ListaCircular<T>::ImprimirLineal( int band )
{
  if ( Vacia() ) return;
  p= cab;
  if ( band )
  {
   // cout<<"Recorrido hacia adelante:\n";
    do 
   {
      cout<<p->getInfo()<<" ";
      p= p->getNext();
   } while ( p!=cab );
  }
  else
  {
//    cout<<"Recorrido hacia atras:\n";
    do
   {      
      p= p->getPrevious();            
      cout<<p->getInfo()<<" ";
   } while ( p!=cab );
  }
  cout<<endl;
}


template <class T>
void ListaCircular<T>::eliminar( int band, T &elemento )
{
	node<T> *aux;
  if ( Vacia() ) return;
  p= cab;
  numeroNodos--;
  if ( band==0 )
  {
  //  cout<<"Recorrido hacia adelante:\n";

      elemento=p->getInfo(); 
      cab=p->getNext();
      p->getPrevious()->setNext(p->getNext());
	  p->getNext()->setPrevious(p->getPrevious());
//	  cout<<"elem: "<<elemento<<endl;
	 
  }
  else
  {
  // cout<<"Recorrido hacia atras:\n";
    
	  p=p->getPrevious();
	  elemento=p->getInfo(); 
	  cab->setPrevious(p->getPrevious());
	  p->getPrevious()->setNext(p->getNext());
//	  cout<<"elem: "<<elemento<<endl;
  }
}

template <class T>
void ListaCircular<T>::Mover( int pos, int band )
{
    for (int i=0; i<pos; i++)
      if ( band ) p=p->getNext();
      else        p=p->getPrevious(); 
     // cout<<"info que deberia mostrar: "<<p->getInfo()<<endl;
}

#endif
