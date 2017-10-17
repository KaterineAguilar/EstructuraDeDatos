#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <vector>
#include "Registro.h"
#include "ListaDobEnlazada.h"
#include "Colas_dinamicas.h"
#include "Pilas_dinamicas.h"
using namespace std;

void cargar(string path);

int main(int argc, char** argv) {
	
	cargar("datos.txt");
	
	return 0;
}

void cargar(string path) {
	ifstream file(path.c_str());
	string line;
	char *split;
	char *splitaux;
	string current;
	string to[3];
	string to1[3];
	int co = 0;
	vector<string> v_string;
	vector<char> v_char;
	vector<int> v_int;
	int menor = 0;
	
	Pilas_dinamicas<string> a;
	Colas_dinamicas<string> b;
	Pilas_dinamicas<char> c;
	Colas_dinamicas<char> d;
	Pilas_dinamicas<int> e;
	Colas_dinamicas<int> f;
	
	ListaDobEnlazada<Registro> registros;
	
	if(file.fail()) {
		cout << "error";
	} else {
		while(getline(file,line)){
			split = strtok(&line[0],",");
			while(split) {	
				if (isalpha(split[0])) {
					current = split;
					if (current.size() > 1) {
						to[co] = "string";
						v_string.push_back(current);
					} else  {
						v_char.push_back(split[0])	;
						to[co] = "char";
					}			
				} else {
					v_int.push_back(atoi(split));
					to[co] = "int";		
				}		
				split = strtok(NULL,",");
			}
			
			co++;
		}		
	}
	file.close();
	
	for(int i = 0, k = 0; i < co; i++) {
		if (to[i] == "string") {
			if(v_string.size()%2==0){ 	
				for(int i =0 ; i < v_string.size(); i++) {
					a.Anadir(v_string[i]);
				}
				to1[k] = "pila";
				cout << "Pila: "; a.Imprimir(); cout << endl;
			} else {
				for(int i =0 ; i < v_string.size(); i++) {
					b.Anadir(v_string[i]);
				}
				to1[k] = "cola";
				cout << "Cola: "; b.Imprimir(); cout << endl;
			}				
		} else if (to[i] == "char") {
			if(v_char.size()%2==0){ 
				for(int i =0 ; i < v_char.size(); i++) {
					c.Anadir(v_char[i]);
				}
				to1[k] = "pila";
				cout << "Pila: "; c.Imprimir(); cout << endl;
			} else {
				for(int i =0 ; i < v_char.size(); i++) {
					d.Anadir(v_char[i]);
				}
				to1[k] = "cola";
				cout << "Cola: "; d.Imprimir(); cout << endl;
			}
		} else {
			if(v_int.size()%2==0){ 
				for(int i =0 ; i < v_int.size(); i++) {
					e.Anadir(v_int[i]);
				}
				to1[k] = "pila";
				cout << "Pila: "; e.Imprimir(); cout << endl;
			} else {
				for(int i =0 ; i < v_int.size(); i++) {
					e.Anadir(v_int[i]);
				}
				to1[k] = "cola";
				cout << "Cola: "; e.Imprimir(); cout << endl;
			}
		}	
	}
	
	if (v_char.size() < v_int.size() && v_char.size() < v_string.size()) {
		menor = v_char.size();
	} else if (v_int.size() < v_string.size() && v_int.size() < v_char.size()) {
		menor = v_int.size();
	} else {
		menor = v_string.size();
	}
	
	cout << endl;
	Registro reg;
	
		
	for (int j = 0; j < menor; j++) {
		for (int i = 0; i < 3; i++) {
			if (to[i] == "string") {
				if(to1[i] == "cola") {
					reg.setDato_string(a.Leer());
				} else {
					reg.setDato_string(b.Leer());
				}
			} else if (to[i] == "char") {
				if(to1[i] == "cola") {
					reg.setDato_char(c.Leer());
				} else {
					reg.setDato_char(d.Leer());
				}
			} else {
				if(to1[i] == "cola") {
					int x = f.Leer();
							
					reg.setDato_int(x);
				} else {
						int x = e.Leer();
				
					reg.setDato_int(x);
				}
			}	
		}
		registros.Anadir(reg);
	}
	
	cout << "Imprimiendo ascendente: " << endl;
	registros.Imprimir(1);
	
	

	
}
