#include <iostream>

using namespace std;

bool BusquedaBinaria(int vec[], int n, int &valor);
bool BusquedaBloques(int vec[], int n, int &valor);


int main(){
	
	int valor = 85;
	
	int vec[]={1,2,7,8,15,24,32,35,64,84,99};
	
	if(BusquedaBinaria(vec,11,valor)){
		cout << "Numero encontrado en: [" << valor << "]" <<endl;
	}else{
		cout << "Numero no encontrado en el array" << endl;
	}
	
//	cout <<valor;
	
	return 0;
}

bool BusquedaBinaria(int vec[], int n, int &valor){
	
	int inicio=0,final=n-1,mitad;
	
	while(inicio<=final){
		mitad=(final+inicio)/2;

		if(vec[mitad]==valor){
		valor=mitad;
		return true;
		}
		if(vec[mitad]>valor) final = mitad-1;
		if(vec[mitad]<valor) inicio = mitad+1;
	}
	return false;

}

bool BusquedaBloques(int vec[], int n, int &valor){
	
	
	
	
}
