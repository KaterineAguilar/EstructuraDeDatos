#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Cliente.h"
#include "Producto.h"
#include "Ventas.h"

using namespace std;

void init(string path[], vector <Cliente*> &c, vector <Producto*> &p, vector <Ventas*> &v);
void listado(vector <Cliente*> c, vector <Producto*> p, vector <Ventas*> v);
void factura(vector <Cliente*> c, vector <Producto*> p, vector <Ventas*> v);

int main(int argc, char** argv) 
{
		
	
	vector <Cliente*> c;
	vector <Producto*> p;
	vector <Ventas*> v;
	char opc;
	string arch[3] = {"cliente.txt", "producto.txt", "ventas.txt"};
	
	init(arch, c, p, v);
	listado(c, p, v);
	
	
	do{
		cout << "\nDesea Generar una Factura? (S/N) _. ";
		cin >> opc;
		if(opc!='s'&&opc!='n') cout << "ingrese Opcion valida " << endl;
	}while(opc!='s'&&opc!='n');
	
	if(opc=='s') factura(c, p, v);
	
	return 0;
}

void factura(vector <Cliente*> c, vector <Producto*> p, vector <Ventas*> v)
{
	fstream arch;
	int ced;
	cout << "Ingrese Cedula para Generar Factura: ";
	cin >> ced;
	bool generar = false;
	
	for(int i = 0; i < c.size(); i++)
	{
		float mTotal=0;
		if(c[i]->getID() == ced)
		{
			arch.open("Factura.txt",ios::out);
			arch << "*********** Factura ***********" << endl << endl;
			arch << c[i]->getName() << " " << c[i]->getNphone() << endl << endl;
			for(int j = 0; j < v.size(); j++)
			{
				if(c[i]->getID() == v[j]->getID())
				{
					for(int k=0; k < p.size(); k++)
					{
						if(v[j]->getCode() == p[k]->getCode()) 
						{
							arch << p[k]->getDesc() << " " << p[k]->getPrice() << endl;
							mTotal += p[k]->getPrice();
						}
					}
				}
			}
			arch << "-------------------------------" << endl;
			arch << "Monto Total: " << mTotal << endl;
			cout << endl << "Factura Generada. . " << endl;
			generar = true;
		} else {
			
		}
	}
	if(generar)
		arch.close();
	else
		cout << endl << "Numero no encontrado en la Base de datos. . ." << endl;
		
}

void listado(vector <Cliente*> c, vector <Producto*> p, vector <Ventas*> v)
{
	for(int i = 0; i < c.size();i++)
	{
		cout << c[i]->getName() << " ";
		float mTotal=0;
		for(int j = 0; j < v.size(); j++)
		{
			if(c[i]->getID() == v[j]->getID()){	
				for(int k=0; k < p.size(); k++)
				{
					if(v[j]->getCode() == p[k]->getCode()) mTotal += p[k]->getPrice();
				}
			}
		}
		cout << " Monto Total de Productos Adquiridos: " << mTotal <<"Bs"<< endl;
	}
	
}

void init(string path[], vector <Cliente*> &c, vector <Producto*> &p, vector <Ventas*> &v)
{
	fstream cliente;
	fstream producto;
	fstream ventas;
	
	cliente.open(path[0].c_str(),ios::in);
	producto.open(path[1].c_str(),ios::in);
	ventas.open(path[2].c_str(),ios::in);
	
	string line;
	char *split;
	
	if(cliente.fail()) cout << "Error " << endl;
	else {
		while(getline(cliente,line))
		{
			split = strtok(&line[0],",");
			int cont = 0;
			int ID;
			long long int nPhone;
			string Name;
	
			while(split != NULL){

				if(cont == 0) ID = atoi(split);
				if(cont == 1) Name = string(split);
				if(cont == 2) nPhone = atoll(split);
							
				split = strtok(NULL, ",");
				cont++;
			}
			c.push_back(new Cliente(ID, Name, nPhone));
		}
		cliente.close();
	}
	
	if(producto.fail()) cout << "Error en Productos " << endl;
	else {
		while(getline(producto,line))
		{
			split = strtok(&line[0],",");
			int cont = 0;
			int code;
			string desc;
			float precio;
			while(split != NULL)
			{
				if(cont == 0) code = atoi(split);
				if(cont == 1) desc = string(split);
				if(cont == 2) precio = atof(split);
				split = strtok(NULL, ",");
				cont++;
			}
			p.push_back(new Producto(code,desc,precio));
		}
		producto.close();
	}
	
	if(ventas.fail()) cout << "Error en Ventas " << endl;
	else {
		while(getline(ventas,line))
		{
			split = strtok(&line[0],",");
			int ced;
			int code;
			int cont = 0;
			while(split != NULL)
			{
				if(cont == 0) ced = atoi(split);
				if(cont == 1) code = atoi(split);
				split = strtok(NULL,",");
				cont++;
			}
			v.push_back(new Ventas(ced,code));
		}
		ventas.close();
	}
		
}
