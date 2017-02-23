#include <iostream>
#include <fstream>
using namespace std;

void shell(int vec[],int n);
void shell2(int vec[],int n);
void imprimir(int vec[],int n);

int main(){
	
	int vec[13]={17,12,9,5,18,21,7,16,22,3,18,10,13};
	int n=13;
	
	shell2(vec,n);
		imprimir(vec,n);
	
}

void shell(int vec[],int n){
	
	int tmp;
	
	for(int i=n/2;i>0;i/=2){
		for (int j = i; j < n; j++){
            for(int k = j - i; k >= 0; k = k - i){
                if(vec[k+i] >= vec[k])
                    break;
                else{
                    tmp = vec[k];
                    vec[k] = vec[k+i];
                    vec[k+i] = tmp;
                }
            }
        }		
	}

	
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
void imprimir(int vec[],int n){
	
	for(int i=0;i<n;i++){
		cout << vec[i] << " "; 
	}
	
}


