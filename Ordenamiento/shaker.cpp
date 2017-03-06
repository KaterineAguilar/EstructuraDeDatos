#include <iostream>
#include <stdlib.h>
#include <time.h>

void ShakerSort(int vec[], int n);
void Print(int v[], int n);

using namespace std;

int main(int argc, char** argv) {
	
	int v[] = {7, 16, 14, 8, 2};
	int vec[25];
	srand(time(NULL));
	for(int i=0;i<25;i++) vec[i] = rand()%100+1;
	 
	ShakerSort(v,5);
	Print(v,5);
	
	ShakerSort(vec,25);
	Print(vec,25);	
	
	
	return 0;
}

void ShakerSort(int v[], int n) {

	int inicio = 0, final = n-1;
	int aux;
	bool band = false;
	int cont = 0;
	do {	
		if(!band) {
			for(int i = 0;i < final;i++) {
				if(v[i] > v[i+1]) {
					aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
				}
			}
			band = true;
			final--;		
		}
		if(band) {	   
			for(int i = final ;i > inicio;i--) {
				if(v[i] < v[i-1]){
					aux = v[i];
					v[i] = v[i-1];
					v[i-1] = aux;
				}
			}
			band = false;
			inicio++;		
		}	
		cont++;
	} while(cont<n/2);	
}

void Print(int v[], int n){
	for(int i=0;i<n;i++) cout << v[i]<<" ";
	cout << endl;
}
