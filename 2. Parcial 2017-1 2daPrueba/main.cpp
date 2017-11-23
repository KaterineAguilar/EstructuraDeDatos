#include <iostream>
#include <fstream>
#include <string.h>
//#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include "Pilas_dinamicas.h"
#include "Colas_dinamicas.h"
#include "ListaEnlazada.h"

using namespace std;

void getData(string path);

int main(int argc, char** argv)
{

	getData("estructuras.txt");

	return 0;
}

void getData(string path)
{
	fstream arch;
	arch.open(path.c_str(),ios::in);
	string line, line2;
	char *split;
	int StructAmount = 0;
	int cant = 0;
	int num[2];
	//-LISTA DE STRUCTS
	Pilas_dinamicas <int> pil_num[2];
	Pilas_dinamicas <char> pil_char[2];
	Pilas_dinamicas <string> pil_string[2];
	Colas_dinamicas <int> col_num[2];
	Colas_dinamicas <char> col_char[2];
	Colas_dinamicas <string> col_string[2];
	ListaEnlazada <int> lis_num[2];
	ListaEnlazada <char> lis_char[2];
	ListaEnlazada <string> lis_string[2];
	//----------------------------------
	int caso = 1;
	while(true) {

		for(int i = 0; i < 2; i++) {
			pil_num[i].~Pilas_dinamicas();	pil_char[i].~Pilas_dinamicas(); pil_string[i].~Pilas_dinamicas();
			col_num[i].~Colas_dinamicas(); col_char[i].~Colas_dinamicas(); col_string[i].~Colas_dinamicas();
			lis_num[i].~ListaEnlazada();   lis_char[i].~ListaEnlazada();   lis_string[i].~ListaEnlazada();
		}

		getline(arch,line);
		StructAmount = atoi(&line[0]);

		if(arch.eof())
			break;

		//agarrando tipo de estructura y de dato
		getline(arch,line);
		//separandolos. . .
		split = strtok(&line[0],",	 ");
		char Structure[10]; //Estructura en la que se esta trabajando PILA - COLA - LISTA
		//guardando estructura actual
		strcpy(Structure,split);
		split = strtok(NULL,", 	");
		//--------------------------
		char DataType[10];  //TIPO DE DATO DE LA ESTRUCTURA NUMERICA - CARACTER - CADENA
		//guardando tipo de dato
		strcpy(DataType,split);
		split = strtok(NULL,", 	");
		//-------------------------
		//por la cantidad de estructuras que hayan, sacar tamano de las mismas.
		for(int i = 0; i < StructAmount; i++) {
			num[i] = atoi(split);
			split = strtok(NULL,", 	");
		}
		//-------------------------
		//CREANDO ESTRUCTURAS
		for(int i = 0; i < StructAmount; i++) {
			if(i == 0) {
				getline(arch, line);
				split = strtok(&line[0],", 	");
			} else {
				getline(arch, line2);
				split = strtok(&line2[0],", 	");
			}
			/*
			-----> PILA
			*/
			if(strcmp(Structure,"pila") == 0) {
//				cout << "**PILA**" << endl;
//				cout << "Elemento " << i+1 << ": ";
//					if(i==0)
//						cout << line;
//					else
//						cout << line2;
				if(strcmp(DataType,"numerico") == 0) {
					for(int k = 0; k < num[i]; k++){
						pil_num[i].Anadir(atoi(split));
						split = strtok(NULL,",");
					}
				} else if(strcmp(DataType,"caracter") == 0) {
					for(int k = 0; k < num[i]; k++){
						pil_char[i].Anadir(*split);
						split = strtok(NULL,",");
					}
				} else if(strcmp(DataType,"cadena") == 0) {
					for(int k = 0; k < num[i]; k++){
						pil_string[i].Anadir((string)split);
						split = strtok(NULL,",");
					}
				}
//				cout << endl;
			/*
			-----> COLA
			*/
			} else if(strcmp(Structure,"cola") == 0) {
//				cout << "**COLA**" << endl;
//				cout << "Elemento " << i+1 << ": ";
//					if(i==0)
//						cout << line;
//					else
//						cout << line2;
				if(strcmp(DataType,"numerico") == 0) {
					for(int k = 0; k < num[i]; k++){
						col_num[i].Anadir(atoi(split));
						split = strtok(NULL,",");
					}
				} else if(strcmp(DataType,"caracter") == 0) {
					for(int k = 0; k < num[i]; k++){
						col_char[i].Anadir(*split);
						split = strtok(NULL,",");
					}
				} else if(strcmp(DataType,"cadena") == 0) {
					for(int k = 0; k < num[i]; k++){
						col_string[i].Anadir(string(split));
						split = strtok(NULL,",");
					}
				}
//				cout << endl;
			/*
			-----> LISTA
			*/
			} else if(strcmp(Structure,"lista") == 0) {
//				cout << "**LISTA**" << endl;
//				cout << "Elemento " << i+1 << ": ";
//					if(i==0)
//						cout << line;
//					else
//						cout << line2;
				if(strcmp(DataType,"numerico") == 0) {
					for(int k = 0; k < num[i]; k++){
						lis_num[i].Anadir(atoi(split));
						split = strtok(NULL,",");
					}
				} else if(strcmp(DataType,"caracter") == 0) {
					for(int k = 0; k < num[i]; k++){
						lis_char[i].Anadir(*split);
						split = strtok(NULL,",");
					}
				} else if(strcmp(DataType,"cadena") == 0) {
					for(int k = 0; k < num[i]; k++){
						lis_string[i].Anadir((string)split);
						split = strtok(NULL,",");
					}
				}
//				cout << endl;
			}
		}
		getline(arch,line); // proceso a ejecutar
		split = strtok(&line[0],", 	");
		int tipo = 0;
		char Operation[10]; //operacion a trabajar
		strcpy(Operation,split);
		split = strtok(NULL,", 	");


		cout << "Caso " << caso++ << "(" << Structure << "->" << Operation << "->" << split << "):" << endl;
		if(strcmp(split,"pila")) {
			tipo = 1;
		} else if(strcmp(split,"cola")) {
			tipo = 2;
		} else if(strcmp(split,"lista")){
			tipo = 3;
		}
			split = strtok(NULL,", 	");
		/*
			ESTA MIERDA ESTA HORRIBLE
			ESTA MIERDA ESTA HORRIBLE
			ESTA MIERDA ESTA HORRIBLE T_T
			ESTA MIERDA ESTA HORRIBLE
			ESTA MIERDA ESTA HORRIBLE
			ESTA MIERDA ESTA HORRIBLE

		*/
		if(strcmp(Operation,"revertir") == 0) {

			if(strcmp(Structure,"pila") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					pil_num[0].invert(tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					pil_char[0].invert(tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					pil_string[0].invert(tipo);
				}
			} else if(strcmp(Structure,"cola") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					col_num[0].invert(tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					col_char[0].invert(tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					col_string[0].invert(tipo);
				}
			} else if(strcmp(Structure,"lista") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					lis_num[0].invert(tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					lis_char[0].invert(tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					lis_string[0].invert(tipo);
				}
			}

		} else if(strcmp(Operation,"ordenar") == 0) {

			if(strcmp(Structure,"pila") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					pil_num[0].sort(tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					pil_char[0].sort(tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					pil_string[0].sort(tipo);
				}
			} else if(strcmp(Structure,"cola") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					col_num[0].sort(tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					col_char[0].sort(tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					col_string[0].sort(tipo);
				}
			} else if(strcmp(Structure,"lista") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					lis_num[0].sort(tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					lis_char[0].sort(tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					lis_string[0].sort(tipo);
				}
			}

		} else if(strcmp(Operation,"mezclar") == 0) {

			if(strcmp(Structure,"pila") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					pil_num[0].mezcla(pil_num[1],tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					pil_char[0].mezcla(pil_char[1],tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					pil_string[0].mezcla(pil_string[1],tipo);
				}
			} else if(strcmp(Structure,"cola") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					col_num[0].mezcla(col_num[1],tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					col_char[0].mezcla(col_char[1],tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					col_string[0].mezcla(col_string[1],tipo);
				}
			} else if(strcmp(Structure,"lista") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					lis_num[0].mezcla(lis_num[1],tipo);
				} else if(strcmp(DataType,"caracter") == 0) {
					lis_char[0].mezcla(lis_char[1],tipo);
				} else if(strcmp(DataType,"cadena") == 0) {
					lis_string[0].mezcla(lis_string[1],tipo);
				}
			}

		} else if(strcmp(Operation,"convertir") == 0) {

			if(strcmp(Structure,"pila") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					pil_num[0].convertir(tipo);
					pil_num[0].Imprimir();
				} else if(strcmp(DataType,"caracter") == 0) {
					pil_char[0].convertir(tipo);
					pil_char[0].Imprimir();
				} else if(strcmp(DataType,"cadena") == 0) {
					pil_string[0].convertir(tipo);
					pil_string[0].Imprimir();
				}
			} else if(strcmp(Structure,"cola") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					col_num[0].convertir(tipo);
					col_num[0].Imprimir();
				} else if(strcmp(DataType,"caracter") == 0) {
					col_char[0].convertir(tipo);
					col_char[0].Imprimir();
				} else if(strcmp(DataType,"cadena") == 0) {
					col_string[0].convertir(tipo);
					col_string[0].Imprimir();
				}
			} else if(strcmp(Structure,"lista") == 0) {
				if(strcmp(DataType,"numerico") == 0) {
					lis_num[0].convertir(tipo);
					lis_num[0].Imprimir();
				} else if(strcmp(DataType,"caracter") == 0) {
					lis_char[0].convertir(tipo);
					lis_char[0].Imprimir();
				} else if(strcmp(DataType,"cadena") == 0) {
					lis_string[0].convertir(tipo);
					lis_string[0].Imprimir();
				}
			}

		} else if(strcmp(Operation,"concatenar") == 0) {
			if(strcmp(Structure,"pila") == 0) {
				if(strcmp(DataType,"numerico")) {
					pil_num[0].concat(pil_num[1],tipo);
				} else if(strcmp(DataType,"caracter")) {
					cout << "SI 3";
					pil_char[0].concat(pil_char[1],tipo);
				} else if(strcmp(DataType,"cadena")) {
					cout << "SI 3";
					pil_string[0].concat(pil_string[1],tipo);
				}
			} else if(strcmp(Structure,"cola")) {
				if(strcmp(DataType,"numerico")) {
					col_num[0].concat(col_num[1],tipo);
				} else if(strcmp(DataType,"caracter")) {
					cout << "SI 3";
					col_char[0].concat(col_char[1],tipo);
				} else if(strcmp(DataType,"cadena")) {
					cout << "SI 3";
					col_string[0].concat(col_string[1],tipo);
				}
			} else if(strcmp(Structure,"lista")) {
				if(strcmp(DataType,"numerico")) {
					lis_num[0].concat(lis_num[1],tipo);
				} else if(strcmp(DataType,"caracter")) {
					lis_char[0].concat(lis_char[1],tipo);
				} else if(strcmp(DataType,"cadena")) {
					lis_string[0].concat(lis_string[1],tipo);
				}
			}

		}
		/*
			ESTE ES EL CODIGO MAS INEFICIENTE QUE HICE ESTE SEMESTRE ....
			ESTE ES EL CODIGO MAS INEFICIENTE QUE HICE ESTE SEMESTRE ....
			ESTE ES EL CODIGO MAS INEFICIENTE QUE HICE ESTE SEMESTRE ....
			ESTE ES EL CODIGO MAS INEFICIENTE QUE HICE ESTE SEMESTRE ....
		*/
		cout << endl << endl;
	}


}
