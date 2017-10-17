#include <iostream>
#include "GenerarClaves.h"


int main(int argc, char** argv) {
	
	GenerarClaves practica2;
	
	if(practica2.obtenerClaves()==0){
		return 0;	
	}else{
		cout<<"error generando claves"<<endl;
		return 1;
	}
}
