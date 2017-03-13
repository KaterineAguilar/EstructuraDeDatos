	#include <iostream>

using namespace std;

void ShowData(int vec[],int n,int fil,int col);
void RadixSort(int vec[],int n,int fil, int col);
void ordenarVec(int vec[],int n, int fil, int col,int vecAux[]);

int **M;

int main(int argc, char** argv) {
	
	int array[]= {25,7,51,1,9999,5,328,168,218};

	int n = sizeof(array)/sizeof(int);
	int fil=n,col=10;
	
	M = new int*[fil];
    for (int i = 0; i < fil; i++) M[i] = new int[col];
    
	for(int i=0;i<fil;i++) 
		for(int j=0;j<col;j++)
			M[i][j]=0;	
	
	RadixSort(array,n,fil,col);	
	
	return 0;
}

void RadixSort(int vec[],int n,int fil,int col){
	int m=-99999;
	int m1=0;
	for(int i=0;i<n;i++) if (vec[i]>m) m=vec[i];
	while(m>0){
		m/=10;
		m1++;
	}
	
	int vecAux[col];

	int millares,centenas,decenas,unidades;
	
	int cont=0;
	while(cont<m1){
		
		for(int i=0;i<n;i++){
	
			millares = vec[i]/1000;
			centenas = (vec[i]-(millares*1000))/100;
			decenas = (vec[i]- (millares*1000 + centenas*100))/10;
			unidades = vec[i]-(millares*1000 + centenas*100 + decenas*10 );
			
			if(cont==0){
				M[vecAux[unidades]][unidades] = vec[i];
				vecAux[unidades]++;	
			}		
			if(cont==1){
				M[vecAux[decenas]][decenas] = vec[i];
				vecAux[decenas]++;
			}
			if(cont==2){
				M[vecAux[centenas]][centenas] = vec[i];
				vecAux[centenas]++;
			}
			if(cont==3){
				M[vecAux[millares]][millares] = vec[i];
				vecAux[millares]++;
			}
			
					
		}
	
		ordenarVec(vec,n,fil,col,vecAux);
			
		system("pause");
		cont++;
	}

	
	cout << endl;	
}
void ordenarVec(int vec[],int n,int fil,int col,int vecAux[]){
	
	int cont=0;
	int pos=0;
	
	for(int j=0;j<col;j++){
		if(M[0][j]>0) {
			for(int k=0;k<vecAux[j];k++){					
				vec[pos]=M[cont][j];
				cont++;
				pos++;
			}
		}
		cont=0;
	}

	ShowData(vec,n,8,10);
			
	
	for(int i=0;i<fil;i++) 
		for(int j=0;j<col;j++)
			M[i][j]=0;
	
	for(int i=0;i<n;i++) vecAux[i]=0;
}

void ShowData(int vec[],int n,int fil,int col){
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			cout << M[i][j]<<"\t";
		}
		cout <<endl;
	}
	for(int i=0;i<n;i++) cout << vec[i] << " ";
}
