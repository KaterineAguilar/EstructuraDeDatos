#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include "ColaCircular.h"
#include "Paciente.h"

using namespace std;

void getData(vector <Paciente> &ListaPacientes);

int main(int argc, char** argv)
{
	int NumElem = 13;
	vector<Paciente> ListaPacientes;
	ColaCircular<Paciente> Consultorio(NumElem);
	srand(time(NULL));

	int ayuda[3] = {3,4,5};
	int ayuda2[3] = {5,6,7};
	int r = 0, t = 0, l = 0;
	int tiempoNuevoPaciente = 0, tiempoConsultaDoctor = 0;

	getData(ListaPacientes);
	t = ayuda2[(rand()%3)];
	while(l < ListaPacientes.size()) {
		tiempoNuevoPaciente++;
		tiempoConsultaDoctor++;
		cout << "Tiempo nuevo Paciente: " << tiempoNuevoPaciente << " Tiempo que tarda el doctor en atender: " << tiempoConsultaDoctor << endl;
		if (tiempoNuevoPaciente == 5) {
			cout << endl;
			tiempoNuevoPaciente = 0;
			r = ayuda[(rand()%3)];
			for (int i = 0; i < r; i++) {
				if (Consultorio.isLLena()) {
					ListaPacientes[l++].imprimir();
					cout << " -> Cliente Rechazado sala de espera llena" << endl << endl;
				} else {
					Consultorio.Anadir(ListaPacientes[l++]);
				}
			}
			cout << "****************************************" << endl;
			cout << "Pacientes en sala de espera... " << endl;
			Consultorio.Imprimir();
			cout << "****************************************" << endl;
		}
		if (tiempoConsultaDoctor == t) {
			t = ayuda2[(rand()%3)];
			tiempoConsultaDoctor = 0;
			Paciente eli;
			eli = Consultorio.Leer();
			cout << endl << "Paciente atendido con exito: ";
			eli.imprimir();
			cout << endl << endl;
		}
		Sleep(1000);
	}
	return 0;
}

void getData(vector <Paciente> &ListaPacientes)
{
	fstream arch;
	arch.open("Paciente.txt", ios::in);
	string linea;
	char *split;
	int cont = 0;
	Paciente p;

	if(arch.fail())
		cout << "Error al abrir el archivo Paciente.txt" << endl;
	else {
		while (getline(arch,linea)) {
			split = strtok(&linea[0],",");
			while (split != NULL) {
				p.setCedula(atoi(split));
				split = strtok(NULL,",");
				p.setNom(split);
				split = strtok(NULL,",");
				p.setEdad(atoi(split));
				split = strtok(NULL,",");
				ListaPacientes.push_back(p);
				p.imprimir();
				cout << endl;
			}
		}
	}
	cout << "-----------------------------------------------" << endl;
}


