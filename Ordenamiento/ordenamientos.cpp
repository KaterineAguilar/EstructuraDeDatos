// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include<string.h>
void seleccion(int vec[], int n);
void seleccion_mejorada(int vec[],int n);
 void ordShell(int a[], int n);
 void quicksort(int a[], int primero, int ultimo);
//void revisar(string cadena[],int n );
using namespace std;
int main(){
    
	 fstream fichero;
 	int cont=0;
	string texto;
	string nombres[1666];
	char *nom=new char[1666];
	
	
	fichero.open("texto.txt",ios::in);
//	fichero>>texto;
	if(fichero.is_open()){
		
		while(!fichero.eof()){
				
		
		    getline(fichero,texto);
		    strcpy(nom,texto.c_str());
		   // nom[cont]=(char*) texto.c_str();
		 
			cout<<nom[cont]<<endl;
		   cont++;
		}
	
			fichero.close();
	}
   
     



     cin.get();
	
	return 0;
}
/*void revisar(string cadena[],int n ){
	
	   int i,j;
	   
	  for( i=0;i<n;i++){
	  	
	  	   cout<<cadena[i]<<" ";
	  	   
	  }
	
	
}*/
void seleccion(int vec[], int n){

	int i, j, may, aux, cont = n;

      
	for (i = 0; i<n; i++){
		may = -9999;
		for (j = 0; j<cont; j++){

			if (vec[j]>may){

				may = vec[j];
				aux = j;
			}

		}

		cont--;
		vec[aux] = vec[cont];
		vec[cont] = may;

	}

}
void seleccion_mejorada(int vec[],int n){
	
	int may,menor,i,j,posf,posi,aux,aux2;
	posf=n;posi=0;
	menor=vec[0];
	int v=n/2;
	     for(i=1;i<v;i++){
	     	      may=-9999;
	     	   for( j=i;j<posf;j++){
	     	   	      
	     	   	      if(vec[j]>may){
	     	   	      	   may=vec[j];
	     	   	      	   aux=j;
	     	   	      	
						}
	     	   	        
	     	   	      if(vec[j]<menor){
	     	   	      	   menor=vec[j];
	     	   	      	   aux2=j;
	     	   	      	
						}
		  	}
	          
			  posf--;
			   vec[aux]=vec[posf];
			   vec[posf]=may;
			   vec[aux2]=vec[posi];
			   vec[posi]=menor;
			   posi++; menor=9999; 
	    
		 }

}
 void ordShell(int a[], int n){
		int salto, i, j, k;
		salto = n / 2;
		while (salto > 0){
			for (i = salto; i < n; i++){
			     j = i - salto;
			      while (j >= 0){
			         k = j + salto;
			           if (a[j] <= a[k])
			                 j = -1; // par de elementos ordenado
			            else{
			                  //intercambiar(a[j], a[j+1]);
			                   double aux =  a[j] ;
                               a[j] = a[j+1];
                               a[j+1] = aux;
			                  j -= salto;
			              }
			       }
			}
		   salto = salto / 2;
		}
}
void quicksort(int a[], int primero, int ultimo){
		int i, j, central;
		double pivote;
		central = (primero + ultimo) / 2;
		pivote = a[central];
		i = primero;
		j = ultimo;
		do {
		      while (a[i] < pivote) i++;
		      while (a[j] > pivote) j--;
		   if (i <= j){
		       // intercambiar(a[i], a[j]);
		          double aux =  a[i] ;
                  a[i] = a[j];
                  a[j] = aux;
		         i++;
		         j--;
		   }
		}while (i <= j);
		if (primero < j)
		   quicksort(a, primero, j); // mismo proceso con sublista izqda
		if (i < ultimo)
		   quicksort(a, i, ultimo); // mismo proceso con sublista drcha
}
