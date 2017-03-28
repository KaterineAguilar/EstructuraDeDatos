#include <iostream>
#include <vector>
#include <cstdlib>
#include "MezclaDirecta.h"
#include "ArchivoBinario.h"
#include "Cliente.h"
#include "Empresa.h"
#include "Cita.h"

using namespace std;
void cargarDatos(string path[], vector<Cliente> &cliente, vector<Empresa> &empresa, vector<Cita> &cita);

int main(int argc, char** argv) {
		
	string path[3] = {"Clientes.txt", "Empresa.txt", "Citas.txt"};
	
	vector<Cliente> cliente;
	vector<Empresa> empresa;
	vector<Cita> 	cita;
	cargarDatos(path, cliente, empresa, cita);
	
	cout << "Clientes no ordenados alfabeticamente " << endl << endl;
	for( int i = 0; i< cliente.size();i++) cliente[i].imprimir();
	
	cout << endl << endl;
	
	cout << "Empresa Ordenada Ascendente por ID" << endl <<endl;
	for(int i = 0; i < empresa.size(); i++) empresa[i].imprimir();

	cout << endl << endl;
	int idaux;
	
	cout << "Ingrese id para buscar cita pendiente de empresa: ";
	cin >> idaux;
	
	for(int i = 0; i < cita.size(); i++) 
		if(cita[i].getCita() == idaux)
			cita[i].imprimir();
	
	cout << endl << endl;
	
	cout << "Ingrese cedula para buscar cita pendiente de cliente: ";
	cin >> idaux;
	
	for(int i = 0; i < cita.size(); i++) 
		if(cita[i].getCedula() == idaux)
			cita[i].imprimir();
	
	
	
	
	return 0;
}

void cargarDatos(string path[], vector<Cliente> &cliente, vector<Empresa> &empresa, vector<Cita> &cita)
{	
	ArchivoBinario <Cliente> ListaCliente((char*)"Clientes.dat");
	ArchivoBinario <Empresa> ListaEmpresa((char*)"Empresa.dat");
	ArchivoBinario <Cita> ListaCita((char*)"Citas.dat");

	ifstream file(path[0].c_str());
	string line;
	char *split;
	Cliente c;
	while(getline(file,line)){
		split = strtok(&line[0], ",");		
		while(split != NULL) {
			c.setCedula(atoi(split));
	    	split = strtok (NULL, ",");
	    	c.setNombre(split);
	    	split = strtok (NULL, ",");
		}
		cliente.push_back(c);
//		c.imprimir();
	}
	file.close();
	ListaCliente.abrir(ios::out| ios::binary);
	for(int i = 0; i < cliente.size(); i++) ListaCliente.escribir(cliente[i]);
	
	//-------------------------------------------------------------------------------
	file.open(path[1].c_str());

	Empresa e;
	while(getline(file,line)){
		split = strtok(&line[0], ",");		
		while(split != NULL) {
			e.setId(atoi(split));
	    	split = strtok (NULL, ",");
	    	e.setNom(split);
	    	split = strtok (NULL, ",");
	    	e.setHora_am1(atoi(split));
	    	split = strtok (NULL, ",");
	    	e.setHora_am2(atoi(split));
	    	split = strtok (NULL, ",");
	    	e.setHora_pm1(atoi(split));
	    	split = strtok (NULL, ",");
	    	e.setHora_pm2(atoi(split));
	    	split = strtok (NULL, ",");
		}
		empresa.push_back(e);
//		e.imprimir();
	}
	file.close();
	ListaEmpresa.abrir(ios::out| ios::binary);
	for(int i = 0; i < empresa.size(); i++) ListaEmpresa.escribir(empresa[i]);
	ListaEmpresa.cerrar();
	
	int tam = empresa.size();
	empresa.clear();
	MezclaDirecta <Empresa> ordCliente((char*)"Empresa.dat");
	ListaEmpresa.abrir(ios::in | ios::binary);

	ordCliente.Ordenar(tam);
	if(ListaEmpresa.fail()){
		cout << "error";
	} else {
		while(true) {
		ListaEmpresa.leer(e);
		if(ListaEmpresa.isFinal())
			break;
//		e.imprimir();
		empresa.push_back(e);
		}
	}
	
	//------------------------------------------------------------
	file.open(path[2].c_str());

	Cita ci;
	while(getline(file,line)){
		split = strtok(&line[0], ",");		
		while(split != NULL) {
			ci.setId(atoi(split));
			split = strtok (NULL, ",");
			ci.setCed(atoi(split));
			split = strtok (NULL, ",");
			ci.setFecha(split);
			split = strtok (NULL, ",");
			ci.setHora(atoi(split));
			split = strtok (NULL, ",");
		}
		cita.push_back(ci);
//		ci.imprimir();
	}
	file.close();	
	ListaCita.abrir(ios::out| ios::binary);
	for(int i = 0; i < cita.size(); i++) ListaCita.escribir(cita[i]);
}
