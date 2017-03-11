#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include "Personas.h"
#include "Sort.h"

using namespace std;

void setData(string path, vector <Personas*> &p, vector <int> &id, vector <string> &name, vector <string> &lastName);
void writeData(int sort, string path, vector <Personas*> &p, vector <int> &id, vector <string> &name, vector <string> &lastName);


int main(int argc, char** argv) {
	
	vector <Personas*> personas;
	vector <int> id;
	vector <string> name;
	vector <string> lastName;
	
	int sort;
	cout << "1. Ordenar por Cedula" << endl;
	cout << "2. Ordenar por Nombre" << endl;
	cout << "3. Ordenar por Apellido" << endl;
	cout << "_: ";
	cin >> sort;
	
	setData("data2.dat", personas, id, name, lastName);
	writeData(sort,"salida.txt",personas, id, name, lastName);
	
	cout << "Archivo generado" <<endl;
	getch();
	return 0;
}
void writeData(int sort, string path, vector <Personas*> &p, vector <int> &id, vector <string> &name, vector <string> &lastName) {
	
	ofstream file(path.c_str());
	file.clear();
	p.clear();
	if(sort == 1){
		shell(id,id.size(),name,lastName);
		for(int i = 0;i < id.size(); i++){
			file << id[i] << " " << lastName[i] << " " << name[i] << endl;
//			p.push_back(new Personas(id[i],name[i],lastName[i]));
		} 
	} 
	if(sort == 2){
		strings(name,name.size(),id,lastName);
		for(int i = 0;i < name.size(); i++){
			file << name[i] << " " << lastName[i] << " " << id[i] << endl;
//			p.push_back(new Personas(id[i],name[i],lastName[i]));
		} 
	}
	if(sort == 3){
		strings(lastName,lastName.size(),id,name);
		for(int i = 0;i < lastName.size(); i++){
			file << lastName[i] << " " << name[i] << " " << id[i] << endl;
//			p.push_back(new Personas(id[i],name[i],lastName[i]));
		} 
	}
		
}

void setData(string path, vector <Personas*> &p, vector <int> &id, vector <string> &name, vector <string> &lastName) {
	
	ifstream file(path.c_str());
	string line;
	char *split;
	
	
	
	while(getline(file,line)){
		
		split = strtok(&line[0], "	 ");
		int cont = 0;
		while(split != NULL) {	
			if(cont==0) id.push_back(atoi(split));
			if(cont==1) lastName.push_back(string(split));
			if(cont==2) name.push_back(string(split));
	    	split = strtok (NULL, "	 ");
	    	cont++;
		}
	}
	
	
}
