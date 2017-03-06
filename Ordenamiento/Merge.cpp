#include <iostream>
#define sufpeq 5

void Merge(int v[], int n);
void Divide(int v[], int p1[], int p2[], int n);
void Mix(int v[], int p1[], int p2[], int n);
void ShakerSort(int v[], int n);
void Print(int v[], int n);

using namespace std;

int main(){
	
	int v[] = {13,9,15,17,11,7,16,14,8,2};
	int n = sizeof(v)/sizeof(int);

	Merge(v,n);
	Print(v,n);
	
	return 0;	
}

void Merge(int v[], int n) {
	int *p1, *p2;
	
	if (n <= sufpeq) ShakerSort(v, n);
	else {
		p1 = new int[n/2];
		p2 = new int[n-n/2];
		Divide(v, p1, p2, n);
		Merge(p1, n/2);
		Merge(p2, n-n/2);
		Mix(v, p1, p2, n);
	}
}

void Divide(int v[], int p1[], int p2[], int n) {
	int i;
	
	for(i = 0;i < n/2;i++)	p1[i] = v[i];
	for(i;i < n;i++) p2[i-(n/2)] = v[i];
}

void Mix(int v[], int p1[], int p2[], int n) {
	int i, j, k;
	i = j = 0;
	
	for(k = 0;(i < n/2) && (j < n-n/2);k++) {
		if(p1[i] < p2[j]){
			v[k] = p1[i];
			i++;
		}else{
			v[k] = p2[j];
			j++;
		}
	}
	
	while (i < n/2) {
		v[k] = p1[i];
		i++; k++;
	}
	while (j < n-n/2) {
		v[k] = p2[j];
		j++; k++;
	}
	
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

void Print(int v[], int n) {
	for(int i = 0;i < n; i++) cout << v[i]<<" ";
		cout << endl;
}
