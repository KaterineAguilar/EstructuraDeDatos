#include <iostream>
#define sufpeq 5
using namespace std;

int pivote(int v[],int n);
void Quicksort(int v[], int n);
void Bubble(int v[],int n);
void show(int v[],int n);

int main(int args, char** argv){
	
	int v[]={13,9,15,17,11,7,16,14,8,2};
	int n=sizeof(v)/sizeof(int);
	
	Quicksort(v,n);
//	pivote(v,n);
	show(v,n);
	
	return 0;
}

int pivote(int v[],int n){
	int pivo=v[0], aux;
	int i=1;
	int j=n-1;
	while(i<j){
		while(v[i]<pivo&&i<n) i++;
		while(v[j]>pivo) j--;			
		if(i<j){
			aux=v[i];
			v[i]=v[j];
			v[j]=aux;
			i++; j--;
		}
//		show(v,n);
	}
	v[0]=v[j];
	v[j]=pivo;
	return j;
}
void Quicksort(int v[], int n){
	int pospiv;
	
	if(n<=sufpeq) Bubble(v,n);
	else{
		pospiv = pivote(v,n);
		Quicksort(v,pospiv);
		Quicksort(&v[pospiv-1],n-pospiv); //REVISAR ACA
	}	
}
void Bubble(int v[],int n){
	int temp;

	for (int i=0; i<n; i++){
		for (int j=0 ; j<n-1; j++){
			if (v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;	
			}	
		}		
	}	
		show(v,n);
}
void show(int v[],int n){
	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
	
}
