#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include "ArbolAVL.h"

using namespace std;

void cargar();

int main(int argc, char** argv) {
	
	cargar();
	
	return 0;
}

void cargar() {
	ArbolAVL<int> arbolito;
	fstream arch;
	string linea;
	char *separar;
	int cantPalabras = 0;
	
	int codigo;
	arch.open("texto.txt", ios::in);
	
	if (arch.fail())
		cout << "Error al abrir el archivo texto.txt" << endl;
	else {
		while (getline(arch, linea)) {
			separar = strtok(&linea[0]," !#$%&/()=?¡");
			while (separar) {	
				codigo = 0;
				string aux = (string)separar;
				string com = "";
				for (int i = 0; i < aux.size(); i++) {				
					if (((int)aux[i] >= 64 && (int)aux[i] <= 90) || ((int)aux[i] >= 97 && (int)aux[i] <= 122)) {
						com = com + aux[i];	
						codigo += aux[i];
					}
				}
				if (aux.size() == com.size())
					arbolito.Anadir(codigo, aux);
						
				separar = strtok(NULL, " !#$%&/()=?¡");
			}
		}
	}
	
	arbolito.imprimir(2);
	cout << endl << "Palabra a buscar" << endl;
	cin >> linea;
	cout << endl;
	arbolito.Buscar(linea);
	cout << endl;
	if(arbolito.eficiencia(cantPalabras))
		cout << "el arbolito es eficiente :D";
	else 
		cout << "el arbolito no es eficiente :(";
		
	getch();	
		
}
