#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool busquedaSimple(int array[], int size, int key);
void shell2(int vec[],int n);

int main(int args, char **argv)
{
	int n=100;
	
	int valor = 1;
	
	srand(time(NULL));
	int vec[n];
		
	for(int i = 0; i < n; i++) vec[i] = rand()%200+1;
	
	shell2(vec,n);
	
	if(busquedaSimple(vec, n, valor)){
		cout << "Encontrado en: " << valor << endl;
	}else 
		cout << "No Encontrado";
	
}

bool busquedaSimple(int array[],int size, int key){
	for(int i=0;i<size;i++)
		if(key==array[i])
			return true;
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
