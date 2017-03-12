#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool BusquedaBinaria(int vec[], int n, int &valor);
bool BusquedaBinariaR(int vec[],int n,int &valor,int inicio,int final);
bool BusquedaBloques(int vec[], int n, int &valor);
void shell2(int vec[],int n);


int main(){
	
	int n=100;
	
	int valor = 50;
	
	srand(time(NULL));
	int vec[n];
		
	for(int i=0;i<n;i++) vec[i]=rand()%500+1;
	
	shell2(vec, n);
	
	//BusquedaBinariaClasica---------
	/*if(BusquedaBinaria(vec, n, valor)){
		cout << "Numero encontrado en: [" << valor << "]" <<endl;
	}else{
		cout << "Numero no encontrado en el array" << endl;
	}*/
	//BusquedaBinariaClasica---------
	
	//BusquedaBinariaRecursiva-------
	if(BusquedaBinariaR(vec, n,valor,0,500-1)){
		cout << "Encontrado en: " << valor << endl;
	}else cout << "No Encontrado";
	//BusquedaBinariaRecursiva--------

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
bool BusquedaBinariaR(int vec[],int n,int &valor,int inicio,int final){

	int mitad=(inicio+final)/2;
	
	if(inicio<=final){
		if(vec[mitad]==valor){
			valor=mitad;
			return true;
		}
		if(vec[mitad]>valor){
			final = mitad-1;
			BusquedaBinariaR(vec,n,valor,inicio,final);
		}
		if(vec[mitad]<valor){
			inicio = mitad+1;	
			BusquedaBinariaR(vec,n,valor,inicio,final);
		}	
	}else return false;
	
}
void shell2(int vec[],int n){
	bool band;
	int incre, aux;
	incre= n/2;
	
	while(incre>0){
		band=false;
		for(int i=0;i+incre<n;i++){
			if(vec[i]>vec[i+incre]){
				aux=vec[i];
				vec[i]=vec[i+incre];
				vec[i+incre]=aux;
				band=true;
			}
		}
		if(!band) incre/=2;
	}
}
bool BusquedaBloques(int vec[], int n, int &valor){
	
	
	
	
}
