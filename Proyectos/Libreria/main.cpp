#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctype.h>
#include "Libro.h"
#include "Editorial.h"
#include "Sort.h"

using namespace std;

void init(vector <Libro> &libros, vector <Editorial> &editorial);
void busqueda(vector <Libro> libros, vector <Editorial> editorial, int opc);
int menu();

int main(int argc, char** argv)
{
	vector <Libro> libros;
	vector <Editorial> editorial;
	int opc;
	init(libros, editorial);
	opc = menu();
	busqueda(libros, editorial, opc);
//	for (int i = 0; i < libros.size(); i++)
//		libros[i].imprimir();

	return 0;
}
int menu(){
	int opc;
	
		system("cls");
		cout << "-------------------- MENU --------------------" << endl;
		cout << endl;
		cout << "1. Buscar Libro por Codigo y titulo: " << endl;
		cout << "2. Buscar Libro por titulo: " << endl;
		cout << "3. Salir." << endl;
		cout << "..: ";
		cin >> opc;
		system("cls");
	
	return opc;	
}
void busqueda(vector <Libro> libros, vector <Editorial> editorial, int opc)
{
	if(opc == 1) {
		int cod;
		cout << "Ingrese Codigo de la Editorial: ";
		cin >> cod;
		cout << endl;
		string titulo;
		cout << "Ingrese el titulo a buscar: ";
		fflush(stdin);
		getline(cin, titulo);
		if ((titulo[0] >= 65 && titulo[0] <= 76) || (titulo[0] >= 97 && titulo[0] <= 108)) {
			
			for (int i = 0; i < libros.size(); i++) {
				string pala = libros[i].getDescripcion();
				if(pala.compare(titulo) == 0) {
					for(int j = 0; j < editorial.size(); j++) {
						if(libros[i].getCodigo() == editorial[j].getCodigo())  {
							cout << endl << "Editorial: " << editorial[j].getNombre() << endl;  
						}
					}
					cout << libros[i].getDescripcion() << " Autor: " << libros[i].getAutor() << endl;
					break;	
				} else {
					cout << endl << "Libro no encontrado";
					break;
				}
			}
		}
		if ((titulo[0] >= 77 && titulo[0] <= 90) || (titulo[0] >= 109 && titulo[0] <= 122)) {
			
			for (int i = libros.size(); i > 0; i--) {
				string pala = libros[i].getDescripcion();
				if(pala.compare(titulo) == 0) {
					for(int j = 0; j < editorial.size(); j++) {
						if(libros[i].getCodigo() == editorial[j].getCodigo())  {
							cout << endl << "Editorial: " << editorial[j].getNombre() << endl;  
						}
					}
					cout << libros[i].getDescripcion() << " Autor: " << libros[i].getAutor() << endl;
					break;	
				} else {
					cout << endl << "Libro no encontrado";
					break;
				}
			}
		}
	}
	
	if(opc == 2) {
		string titulo;
		cout << "ingrese el titulo a buscar: ";
		fflush(stdin);
		getline(cin, titulo);

		if ((titulo[0] >= 65 && titulo[0] <= 76) || (titulo[0] >= 97 && titulo[0] <= 108)) {
			
			for (int i = 0; i < libros.size(); i++) {
				string pala = libros[i].getDescripcion();
				if(pala.compare(titulo) == 0) {
					cout << libros[i].getDescripcion() << " Autor: " << libros[i].getAutor() << endl;
					break;	
				}
			}
		}
		if ((titulo[0] >= 77 && titulo[0] <= 90) || (titulo[0] >= 109 && titulo[0] <= 122)) {
			
			for (int i = libros.size(); i > 0; i--) {
				string pala = libros[i].getDescripcion();
				if(pala.compare(titulo) == 0) {
					cout << libros[i].getDescripcion() << " Autor: " << libros[i].getAutor() << endl;
					break;	
				}
			}
		}
	}
	cout << endl << endl;
	for (int i = 0; i < editorial.size(); i++)
	{
		int cont = 0;
		for(int j = 0; j < libros.size(); j++)
		{
			if(editorial[i].getCodigo() == libros[j].getCodigo()) cont++;
		}
		cout << "Cantidad de libros para editorial " << editorial[i].getNombre() << ": " << cont << endl;
	}
	
}
void init(vector <Libro> &libros, vector <Editorial> &editorial)
{
	fstream inLibro, inEditorial, f1 ,f2, f3;
	Libro li;
	Editorial ed;
	string linea;
	char *split;
	int c = 0, N = 0;
	bool ord = false;

	inEditorial.open("editorial.txt", ios::in);
	inEditorial.clear();
	editorial.clear();

	if (inEditorial.fail())
		cout << "Error al abrir el archivo editorial.txt" << endl;
	else {
		while (getline(inEditorial, linea)) {
			split = strtok(&linea[0],",");
			c = 0;
			while (split != NULL) {
				if (c == 0) ed.setCodigo(atoi(split));
				if (c == 1) ed.setEditorial(split);
				split = strtok(NULL,",");
				c++;
			}
			editorial.push_back(ed);
		}
	}
	inEditorial.close();
	
	f1.open("f1.txt", ios::out);
	f2.open("f2.txt", ios::out);
	f3.open("f3.txt", ios::out);

	inLibro.open("libro.txt", ios::in);
	inLibro.clear();

	if (inLibro.fail())
		cout << "Error al abrir el archivo Libro.txt" << endl;
	else {
		while (getline(inLibro, linea)) {
			split = strtok(&linea[0],",");
			c = 0;
			int cod;
			while (split != NULL) {
				if (c == 0) {
					cod = atoi(split);
					if (cod == 1) f1 << atoi(split);
					if (cod == 2) f2 << atoi(split);
					if (cod == 3) f3 << atoi(split);
				}
				if (c == 1) {
					if (cod == 1) f1 << ',' << split;
					if (cod == 2) { 
						f2 << ',' << split;
						N++;
					} 
					if (cod == 3) f3 << ',' << split;
					
				}
				if (c == 2) {
					if (cod == 1) f1 << ',' << split << endl;
					if (cod == 2) f2 << ',' << split << endl;
					if (cod == 3) f3 << ',' << split << endl;
				}
				split = strtok(NULL,",");
				c++;
			}
		}
	}
	inLibro.close();
	f1.close();
	f2.close();
	f3.close();

	inLibro.open("libro.txt", ios::out);
	f1.open("f1.txt", ios::in);
	f2.open("f2.txt", ios::in);
	f3.open("f3.txt", ios::in);
	int num[N+1];
	char desc[N+1][30];
	char autor[N+1][20];
	int l = 0, ll = 0, lll = 0;
	
	while (getline(f1,linea)) {
		split = strtok(&linea[0],",");
		c = 0;
		while (split != NULL) {
			if (c == 0) num[lll++] = atoi(split);
			if (c == 1) strcpy(desc[l++], split);
			if (c == 2) strcpy(autor[ll++], split);
			split = strtok(NULL, ",");
			c++;
		}
	}
	shell2(desc, autor, N);
	for (int i = 0; i < N; i++) {
		inLibro << num[i] << ',' << desc[i] << ',' << autor[i] << endl;
	}	
	l = 0, ll = 0, lll = 0;
	while (getline(f2,linea)) {
		split = strtok(&linea[0],",");
		c = 0;
		while (split != NULL) {
			if (c == 0) num[lll++] = atoi(split);
			if (c == 1) strcpy(desc[l++], split);
			if (c == 2) strcpy(autor[ll++], split);
			split = strtok(NULL, ",");
			c++;
		}
	}
	shell2(desc, autor, N);
	for (int i = 0; i < N; i++) {
		inLibro << num[i] << ',' << desc[i] << ',' << autor[i] << endl;
	}
	l = 0, ll = 0, lll = 0;
	while (getline(f3,linea)) {
		split = strtok(&linea[0],",");
		c = 0;
		while (split != NULL) {
			if (c == 0) num[lll++] = atoi(split);
			if (c == 1) strcpy(desc[l++], split);
			if (c == 2) strcpy(autor[ll++], split);
			split = strtok(NULL, ",");
			c++;
		}
	}
	shell2(desc, autor, N);
	for (int i = 0; i < N; i++) {
		inLibro << num[i] << ',' << desc[i] << ',' << autor[i] << endl;
	}
	
	f1.close();
	f2.close();
	f3.close();
	inLibro.close();
	
	remove("f1.txt");
	remove("f2.txt");
	remove("f3.txt");

	fstream bin;
	bin.open("salida.dat", ios::out | ios::binary);
	inLibro.open("libro.txt", ios::in);
	inLibro.clear();
	libros.clear();
	if (inLibro.fail())
		cout << "Error al abrir el archivo libro.txt" << endl;
	else {
		while (getline(inLibro, linea)) {
			split = strtok(&linea[0],",");
			c = 0;
			while (split != NULL) {
				if (c == 0) li.setCodigo(atoi(split));
				if (c == 1) li.setDescripcion(&split[1]);
				if (c == 2) li.setAutor(&split[1]);
				split = strtok(NULL,",");
				c++;
			}
			bin.write((char*)&li,sizeof(li));
			libros.push_back(li);
		}
	}
	inLibro.close();
	bin.close();
	
}

