#include <iostream>
#include <stdlib.h>
#include <time.h>
/*
DYLAN PREPAS
MARTES: 11-1
MIERCO: 10-12
VIERNE: 11-1

04247231306

*/
using namespace std;
void shakerSort(int vec[],int n);
void imprimir(int v[],int n);
int main(int argc, char** argv){
	
	int v[]={55,23,31,14,16,19,21,10,12,18,24,36,63,84,2};
	int vec[50000];
	srand(time(NULL));
	for(int i=0;i<50000;i++) vec[i]=rand()%500000;
	
	shakerSort(vec,50000);
	imprimir(vec,50000);
	//shakerSort(v,15);
	//imprimir(v,15);	
	
	
	return 0;
}

void shakerSort(int v[],int n){
	
	int inicio=0, final=n-1;
	int aux;
	bool band=false;
	int cont=0;
	do{
		
		if(!band){
			for(int i=0;i<final;i++){
				if(v[i]>v[i+1]){
					aux=v[i];
					v[i]=v[i+1];
					v[i+1]=aux;
				}
				if(i==final-1){
					band=true;
					final--;
				}
			}	
		}
		if(band){	   
			for(int i=final;i>inicio;i--){
				if(v[i]<v[i-1]){
					aux=v[i];
					v[i]=v[i-1];
					v[i-1]=aux;
				}
				if(i-1==inicio){
					band=false;
					inicio++;
				}
			}
		}
		
		cont++;
	}while(cont<final/2);
	
}
void imprimir(int v[],int n){
	for(int i=0;i<n;i++){
		cout << v[i]<<" ";
	}
}
