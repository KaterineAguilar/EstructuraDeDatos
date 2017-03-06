#include <iostream>
#include <time.h>
#include <stdlib.h>
#define sufpeq 5
using namespace std;

int pivote(int v[], int start, int end);
void Quicksort(int v[], int start, int end);
void Bubble(int v[], int n);
void show(int v[], int n);

int main(int args, char** argv) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for(int i = 0;i < n; i++) v[i] = rand()%100+1;
	
	show(v, n);
	Quicksort(v, 0, n-1);
	show(v, n);
	
	return 0;
}

int pivote(int v[], int start, int end) {
	int pivo;
	int left;
	int right;
	int aux;
	
	pivo = v[start];
	left = start;
	right = end;
	
	while(left < right) {
		while((v[left] <= pivo) && (left < right)){
			left++;	
		} 
		
		while(v[right] > pivo) {
			right--;	
		} 
		
		if(left < right) {
			aux = v[left];
			v[left] = v[right];
			v[right] = aux;
			left++; right--;
		}	
		
	}
	
	aux = v[right];
	v[right] = v[start];
	v[start] = aux;
	
	return right;
}
void Quicksort(int v[], int start, int end){
	int pospiv;
	
	if(end <= sufpeq) {
		Bubble(v, end);
	} else if(start < end) {
		pospiv = pivote(v, start, end);
		Quicksort(v, start, pospiv-1);
		Quicksort(v, pospiv+1, end);
			
	}
	
}
void Bubble(int v[], int n) {
	int temp;

	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < n-1; j++) {
			if (v[j] > v[j+1]) {
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;	
			}	
		}		
	}	
//		show(v,n);
}
void show(int v[], int n) {
	for(int i = 0;i < n; i++) cout << v[i] << " ";
	cout << endl << endl;
	
}
