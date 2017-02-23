#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool BusquedaBinaria(int vec[], int n, int &valor);
bool BusquedaBloques(int vec[], int n, int &valor);
void shell2(int vec[],int n);


int main(){
	
	
	int a=500000;
	
	int valor = 4568;
	
	srand(time(NULL));
	int vec[a];
		
	for(int i=0;i<a;i++) vec[i]=rand()%a+1;
	
	shell2(vec,a);
	
	
	if(BusquedaBinaria(vec,a,valor)){
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
