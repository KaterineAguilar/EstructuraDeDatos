#include <iostream>
#include <fstream>
#include <vector>
#include "ArchivoBinario.h"
#include "MezclaDirecta.h"
#include "Materias.h"
#include "Inscritos.h"
#include "Datos.h"

using namespace std;

void init(vector <Datos> &ListDatos, vector <Inscritos> &ListInscritos, vector <Materias> &ListMaterias);

int main(int argc, char** argv) {
	
	vector <Datos> ListDatos;
	vector <Inscritos> ListInscritos;
	vector <Materias> ListMaterias;
	
	init(ListDatos, ListInscritos, ListMaterias);
	cout << "Listado de alumnos inscritos en cada asignatura ( de menor a mayor codigo)" << endl <<endl;
	for (int i = 0 ; i < ListInscritos.size(); i++) {
		for (int j = 0 ; j < ListDatos.size(); j++) {
			if (ListInscritos[i].getCedula() == ListDatos[j].getCedula()) {	
				for (int k = 0; k < ListMaterias.size(); k++) {
					if (ListInscritos[i].getCodigo() == ListMaterias[k].getCodigo()) {
						cout << ListMaterias[k].getCodigo() << " " << ListMaterias[k].getNombreMat() << "\t" << ListDatos[j].getNombre() << "\t" << ListDatos[j].getCedula() << endl;
					}
				}
			}
		}
	}
	cout << endl;
	int cont, cant = 0;
	for (int i = 0 ; i < ListDatos.size(); i++) {
		cont = 0;
		for (int j = 0 ; j < ListInscritos.size(); j++) {
			if(ListDatos[i].getCedula() == ListInscritos[j].getCedula()) cont++;
		}
		if (cont == ListMaterias.size()) 
			cant++;
	}
	cout<<cant<<endl;
	cout << endl << "Porcentaje de alumnos inscritos en todas las asignaturas: " << (cant*100)/ListInscritos.size() << "%" << endl;
	int menor = 0;
	for (int i = 0; i < ListMaterias.size(); i++) {
		cont = 0;
		for (int j = 0; j < ListInscritos.size(); j++) {
			if (ListMaterias[i].getCodigo() == ListInscritos[j].getCodigo()) 
				cont++;
		}
		if(cont == 1) cout << endl << "Materia con menor numero de alumnos inscritos: " << ListMaterias[i].getNombreMat() << endl;
		if(cont == ListMaterias.size()) cout << "Materia con mayor numero de alumnos inscritos: " << ListMaterias[i].getNombreMat();
	}
	
	for (int i = 0; i < ListMaterias.size(); i++) {
		for(int j = 0; j < ListInscritos.size(); j++) {
			for(int k = 0; k < ListDatos.size(); k++) {
//				if() ME DA PEREZA HACER ESTO
			}
		}
	}

	cout << endl << endl << "Introducir Cedula de Estudiante a Buscar: ";
	int ced;
	bool enc = false;
	cin >> ced;
	cout << endl <<endl;
	int UC = 0;
	for (int i = 0; i < ListDatos.size(); i++) {
		if(ListDatos[i].getCedula() == ced){
			enc = true;
			for (int j = 0; j < ListInscritos.size(); j++) {
				if (ListInscritos[j].getCedula() == ListDatos[i].getCedula()) {
					for (int k = 0; k < ListMaterias.size(); k++) {
						if (ListInscritos[j].getCodigo() == ListMaterias[k].getCodigo()) {
							cout << ListDatos[i].getNombre() << " " << ListMaterias[k].getNombreMat() << endl;
							UC += ListMaterias[k].getUC();
						}
					}
				}
			}
		} else if ((ListDatos[i].getCedula() != ced) && (i+1 == ListDatos.size()) && !enc) 
			cout << "Cedula no encontrada";
	}
	if (enc)
		cout << endl << "Total UC Inscritas: " << UC << endl;
	
	return 0;
}

void init(vector <Datos> &ListDatos, vector <Inscritos> &ListInscritos, vector <Materias> &ListMaterias)
{
	//---------------------------------------------------
	ArchivoBinario <Datos> inDatos((char*)"Datos.dat");
	Datos datos;
	
	inDatos.abrir(ios::in | ios::binary);
	int tam = inDatos.tamano();
	
	if(inDatos.fail())
		cout << "Error al abrir el archivo Datos.dat" << endl;
	else
		while(true) {
			inDatos.leer(datos);
			if(inDatos.isFinal())
				break;
//			datos.imprimir();
			ListDatos.push_back(datos);
		}
	inDatos.~ArchivoBinario();
	//---------------------------------------------------
	
	ArchivoBinario <Inscritos> inInscritos((char*)"Inscritos.dat");
	Inscritos inscritos;
	
	inInscritos.abrir(ios::in | ios::binary);
	tam = inInscritos.tamano();
	
	//--ORDENANDO CON MEZCLA DIRECTA--//
	MezclaDirecta <Inscritos> mezclarInscritos((char*)"Inscritos.dat");
	mezclarInscritos.Ordenar(tam);
	//--ORDENANDO CON MEZCLA DIRECTA--//
	
	if(inInscritos.fail())
		cout << "Error al abrir el archivo Inscritos.dat" << endl;
	else
		while(true) {
			inInscritos.leer(inscritos);
			if(inInscritos.isFinal())
				break;
//			inscritos.imprimir();
			ListInscritos.push_back(inscritos);
		}
	inInscritos.~ArchivoBinario();
	//---------------------------------------------------
	
	ArchivoBinario <Materias> inMaterias((char*)"Materia.dat");
	Materias materias;
	
	inMaterias.abrir(ios::in | ios::binary);
	tam = inMaterias.tamano();
	
	if(inMaterias.fail())
		cout << "Error al abrir el archivo materias.dat" << endl;
	else
		while(true) {
			inMaterias.leer(materias);
			if(inMaterias.isFinal())
				break;
//			materias.imprimir();
			ListMaterias.push_back(materias);
		}
	inMaterias.~ArchivoBinario();
}
