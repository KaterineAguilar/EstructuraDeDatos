/*
* Mariandrea de la Consolacion Maldonado Vazquez
* CI. V. 24693522
* Pedro Jose Labrador Perez
* CI. V. 25587776
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <conio.h>
#include <fstream>
#include "ListaEnlazada.h"
#include "Producto.h"
#include "Departamento.h"

using namespace std;

void inventario(ListaEnlazada<Departamento> *obj);
int busqueda_codigo(ListaEnlazada<Departamento> *obj, int cod_search, Producto &an);

int main(int argc, char *argv[]) {
	ListaEnlazada<Departamento> *obj = new ListaEnlazada<Departamento>;
	int cod; float pre; int cant;
	char line[80], *p, des[45];
	ifstream arc1("principal.txt");
	ifstream arc2("productos.txt");
	while (true) {
		arc1.getline(line,80,'\n');
		if (arc1.eof()) 
			break;
		p = strtok(line,",");
		cod =atoi(p);
		p = strtok(NULL,",");
		strcpy(des,p);
		Departamento x(des,cod);
		obj->Anadir(x);
	}
	arc1.close();
	while (true) {
		arc2.getline(line,80,'\n');
		if (arc2.eof()) 
			break;
		p = strtok(line,",");
		cod = atoi(p);
		p = strtok(NULL,",");
		strcpy(des,p);
		p = strtok(NULL,",");
		pre = atof(p);
		p = strtok(NULL,",");
		cant = atoi(p);
		int cod_aux = cod/100;
		Departamento x((char*)"xxxx",cod_aux);
		Producto y(cod,des,pre,cant);
		if (obj->buscar(x))     
			x.sublis->Anadir(y);
	}
	arc2.close();
		
	Producto anadir;
	ListaEnlazada<Producto> factura;
	char sw = ' ';
	do {
		system("cls");
		inventario(obj);
		cout << "Ingrese codigo del elemento a comprar: ";
		int cod_search;
		cin >> cod_search;
		int opc = busqueda_codigo(obj, cod_search, anadir);
		
		if (opc == 1) {
			factura.Anadir(anadir);
		} else if (opc == 0) {
			cout << endl << "Elemento inexistente.. " << endl;
			
		} else if (opc == -1){
			cout << endl << "Codigo de departamento invalido!!!" << endl << endl;
		}
		cout << endl << endl << "Se que esto es fastidioso pero, desea comprar otro producto?(S/N)) :";
		cin >> sw;
	} while (tolower(sw) != 'n');
	
	system("cls");
	
	if (factura.getNumNodos() == 0) {
		cout << "No compraste productos.." << endl;
		return EXIT_SUCCESS;
	}
			
	cout << "**** FACTURA ****" << endl << endl;
	factura.Imprimir();
	float total = 0;
	
	Nodo<Producto> *q;
	q = factura.getInicio();
	while (q) {
		Producto curr;
		curr = q->getValor();	
		total += curr.get_pre();	
		q = q->getSiguiente();
	}
	int total_iva = total*0.17;
	cout << "----------------------------" << endl;
	cout << "Total sin IVA: " << total << endl;
	cout << "IVA: " << total_iva << endl;
	cout << "Total con IVA: "  << total + total_iva << endl;
	cout << "----------------------------" << endl << endl;
	
	system("pause>0");
	cout << "Inventario final: " << endl << endl;
	inventario(obj);
	cin.get();
	return EXIT_SUCCESS;
}

int busqueda_codigo(ListaEnlazada<Departamento> *obj, int cod_search, Producto &an) {
	
	Nodo<Departamento> *pd;
	Nodo<Producto> *q;
	pd = obj->getInicio();
	int cod_dep = cod_search/100;
	int cont = 0;
	int curr_cod;
	while (pd) {	
		if (pd->getValor().get_cod() == cod_dep) {
			q = pd->getValor().sublis->getInicio();	
			while (q) {
				Producto curr = q->getValor();
				if (curr.get_cod() == cod_search) {
					an = curr;
					int numb;
					do {
						cout << "Cantidad de " << curr.get_des() << " a comprar?: ";
						cin >> numb;
						if (numb <= 0) 
							cout << endl << "INGRESE CANTIDAD APROPIADA!!!" << endl;
					} while (numb <= 0);
					if (curr.get_cant() >= numb) {
						curr.dec_cant(numb);
						an.set_cant(numb);
						q->setValor(curr);
					} else {
						cout << endl << "CANTIDAD INSUFICIENTE EN INVENTARIO" << endl;
						return -3;
					}	
					return 1;
				}
				q = q->getSiguiente();
			}
		} else 
			cont++;
		pd = pd->getSiguiente();
	}
	if (cont == obj->getNumNodos())
		return -1;
	return 0;
}

void inventario(ListaEnlazada<Departamento> *obj) {
	Nodo<Departamento> *pd;
	Nodo<Producto> *q;
	pd = obj->getInicio();
	while (pd) {
		pd->getValor().imprimir();
		q = pd->getValor().sublis->getInicio();
		while (q) {
			if (q->getValor().get_cant() > 0) 
				q->getValor().imprimir();
			q = q->getSiguiente();
		}
		cout << endl;
		pd = pd->getSiguiente();
	}
	cout << "------------------------------------" << endl;
}
