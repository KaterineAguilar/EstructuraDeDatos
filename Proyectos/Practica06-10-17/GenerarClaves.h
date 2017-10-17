#ifndef GENERARCLAVES_H
#define GENERARCLAVES_H
#include "ListaCircular.h"

class GenerarClaves
{
	
	char caracter;
	int cantidadCaracteres;
	int maximoCaracteres;
	ListaCircular<char> listaCedula;
	ListaCircular<char> listaNombre;
	
	public:
		GenerarClaves(){
			
			cantidadCaracteres=1;
			maximoCaracteres=15;
			cout<<"el progrma esta disenado bajo la instruccion de que solo \nleera 15 caracteres si sobrepasa el limite, simplemente \nignorara los digitos sobrantes despues del 15"<<endl;
			
		
		}
		
		int obtenerClaves();
		void lineas(){cout<<"-------------------------------------------------------"<<endl;}
};

int GenerarClaves::obtenerClaves(){
				
	lineas();
	//lee el nombre caracter a caracter obviando los espacios en blanco, sin usar arreglos y sin pasar 15 digitos
	cout<<"\n\ningrese nombre: "<<endl;
	do{
		caracter=getchar();
		if(caracter!='\n'&&caracter!=' ') {
		listaNombre.AgregarSinOrden(caracter);
		cantidadCaracteres++;
		}
	}while(caracter!='\n'&&cantidadCaracteres<=maximoCaracteres);
			
	fflush(stdin);cantidadCaracteres=0;
	//lee la cedula caracter a caracter obviando los espacios en blanco, sin usar arreglos y sin pasar 15 digitos
	cout<<"ingrese cedula: "<<endl;
		do{
			caracter=getchar();
			if(caracter!='\n'&&caracter!=' ') {
				listaCedula.AgregarSinRepetir(caracter);
				cantidadCaracteres++;
			}
		}while(caracter!='\n'&&cantidadCaracteres<=maximoCaracteres);
			
		//listaNombre.Imprimir(0);
		//listaCedula.Imprimir();
	ListaCircular <char> clave;
	int nombreC=listaNombre.getNumNodos();
	int cedulaC=listaCedula.getNumNodos();
	int aux,aux2;
	listaCedula.setPenCab();
	for(int i=0;i<nombreC;i++){
		listaNombre.eliminar(0,caracter);
		aux=caracter;
		aux2=aux%cedulaC;
		listaCedula.Mover(aux2,1);
		clave.AgregarSinOrden(listaCedula.GetActual());
	}
	cout<<"clave generada: ";
	clave.ImprimirLineal(1);
	lineas();
	return 0;
}
#endif
