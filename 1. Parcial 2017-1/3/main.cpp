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
bool crearCita(vector<Cliente> &cliente, vector<Empresa> &empresa, vector<Cita> &cita);

int main(int argc, char** argv) {
		
	string path[3] = {"Clientes.txt", "Empresa.txt", "Citas.txt"};
	
	vector<Cliente> cliente;
	vector<Empresa> empresa;
	vector<Cita> 	cita;
	cargarDatos(path, cliente, empresa, cita);
	
	cout << "Clientes ordenados alfabeticamente " << endl << endl;
	for( int i = 0; i < cliente.size();i++) cliente[i].imprimir();
	
	cout << endl << endl;
	
	cout << "Empresa Ordenada Ascendente por ID" << endl <<endl;
	for(int i = 0; i < empresa.size(); i++) empresa[i].imprimir();

	cout << endl ;
	
	while(crearCita(cliente, empresa, cita)){
		if(!crearCita(cliente, empresa, cita))
			break;
	}
	
	cout << "/------------------------------------------------------------/" << endl << endl;

	int idaux;
	
	cout << "Ingrese id para buscar cita pendiente de empresa: ";
	cin >> idaux;
	int cont = 0;
	for (int i = 0; i < cita.size(); i++) {
		if (cita[i].getCita() == idaux) 
			cita[i].imprimir();
		else
			cont++;
	}
	if(cont == cita.size()) 
		cout << "Este Id no posee cita. " << endl;
	
	cout << endl << endl;
	
	cout << "Ingrese cedula para buscar cita pendiente de cliente: ";
	cin >> idaux;
	cont = 0;
	for(int i = 0; i < cita.size(); i++) {
		if (cita[i].getCedula() == idaux) 
			cita[i].imprimir();
		else
			cont++;
	}
	if(cont == cita.size()) 
		cout << "Esta Cedula no posee cita. " << endl;
		
	cout << endl << endl;
	
	return 0;
}

bool crearCita(vector<Cliente> &cliente, vector<Empresa> &empresa, vector<Cita> &cita)
{
	cout << "/------------------------------------------------------------/" << endl << endl;
	cout << "Creando cita.. . "	 << endl << endl;
	int cAux;
	cout << "Ingrese cedula: " ;
	cin >> cAux;
	cout << endl;
	
	bool enc = false;
	int posCliente, posEmpresa;
	for(int i = 0; i < cliente.size(); i++) {
		if (cliente[i].getCedula() == cAux) {
			enc = true;
			posEmpresa = i;
			break;
		}
	}
	if(enc) {
		cout << "**********************************" << endl;
		for (int i = 0; i < empresa.size(); i++) 
			cout << "[" << empresa[i].getId() << "]" << empresa[i].getNombre() <<  endl;
		cout << "**********************************" << endl;	
		
		int opc;
		bool again = true;
		do{
			cout << "Ingrese codigo de la empresa para crear una cita. " << endl;
			cin >> opc;
			for (int i = 0; i < empresa.size(); i++)
				if (empresa[i].getId() == opc) {
					again = false;
					posEmpresa = i;
					break;
				}
					
		}while (again);
		string fecha = " ";
		string concat;
		cout << "Ingrese fecha para la cita (DD-MM-AA): ";
		fflush(stdin);
		getline(cin, concat);
		fecha+=concat;
		cout << "\nHorarios de la empresa..: " << empresa[posEmpresa].getHora_am1() << " - " << empresa[posEmpresa].getHora_am2();
		cout << " am\t" << empresa[posEmpresa].getHora_pm1() << " - " << empresa[posEmpresa].getHora_pm2() << "pm" << endl << endl;
		int hora;
		bool cit = true;
		do{
			cout << "ingrese hora para su cita..: ";
			cin >> hora;	
			if (empresa[posEmpresa].getHora_am1() <= hora && hora <= empresa[posEmpresa].getHora_am2()) {
				cit = false;
			}	
			if (empresa[posEmpresa].getHora_pm1() <= hora && hora <= empresa[posEmpresa].getHora_pm2()) {
				cit = false;
			}
		}while (cit);
				
		Cita c;
		c.setId(opc); c.setCed(cAux); c.setFecha(&fecha[0]); c.setHora(hora);
		cita.push_back(c);
		ArchivoBinario <Cita> LCita((char*)"Citas.dat");
		LCita.quicksort(cita,0,cita.size()-1);
		
		
	} else 
		cout << "Cliente no encontrado.. "; 
	
	char a;
	
	cout << "\n\nDesea crear otra cita? (s/n): ";
	cin >> a;	
		
	if(a == 's' || a == 'S') 
		return true;
	else if(a == 'n' || a == 'N')
		return false;
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
	ListaCliente.cerrar();
	
	ListaCliente.quicksort(cliente, 0, cliente.size()-1);
	
	ListaCliente.abrir(ios::out| ios::binary);
	for(int i = 0; i < cliente.size(); i++) 
		ListaCliente.escribir(cliente[i]);
	ListaCliente.cerrar();
	
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
	ListaEmpresa.cerrar();
	
	ListaEmpresa.abrir(ios::out| ios::binary);
	for(int i = 0; i < empresa.size(); i++) 
		ListaEmpresa.escribir(empresa[i]);
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
	ListaCita.cerrar();
	
	ListaCita.quicksort(cita, 0, cita.size()-1);
	
	ListaCita.abrir(ios::out| ios::binary);
	for(int i = 0; i < cita.size(); i++) 
		ListaCita.escribir(cita[i]);
	ListaCita.cerrar();
}
