#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Cliente.h"
#include "Producto.h"
#include "Ventas.h"

using namespace std;
void init(string path[]);

int main(int argc, char** argv) 
{
	string arch[3] = {"cliente.txt", "productos.txt", "ventas.txt"};
	init(arch);
	return 0;
}

void init(string path[])
{
	fstream cliente;
	fstream producto;
	fstream ventas;
	
	cliente.open(path[0].c_str(),ios::in);
	producto.open(path[1].c_str(),ios::in);
	ventas.open(path[2].c_str(),ios::in);
	
	string line;
	char *split;
	int cont = 0;
	int ID, nPhone; string Name;
	while(getline(cliente,line))
	{
		split = strtok(&line[0]," 	");
		while(split!=NULL)
		{
			if(cont == 0) ID = atoi(split);
			if(cont == 1) Name = (string)split;
			if(cont == 2) nPhone = atoi(split);
			split = strtok(NULL, " 	");
			cont++;
		}
	}
	cout << ID <<" "<< Name <<" "<< nPhone;
	cliente.close();
		
}
