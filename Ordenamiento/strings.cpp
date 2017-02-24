#include<stdio.h>
#include<conio.h> //permite getch.
#include<string.h> // permite strcmp y strcpy.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char nombre[3000][100];
    char aux[120];//tiene que ser de igual o mayor tamaño que la segunda componente
    //de nombre porque aquí copiaremos esa cadena.
    int i,j,k;
    int l=0;
    string line;
    
    ifstream ar("Nombres.txt");
    
    while(getline(ar,line)){
//    	cout << l << endl;
    	strcpy(nombre[l++],line.c_str());
	}
    
    
    /*printf("Para terminar escriba * \n");
    do
        {
            printf("Introduce un nombre: ");
            gets(nombre[l]);//lee cadenas y las almacena.
            l++;
        }
    while (strcmp(nombre[l-1],"*")!=0);//permite comparar cadenas.*/

    // ORDENAR CADENAS
    for(i=0; i<l-1; i++)
    {
        k=i;
        strcpy(aux, nombre[i]);
        for(j=i+1; j<l; j++)
        {
            if(strcmp(nombre[j], aux)<0)
            {
                k=j;
                strcpy(aux, nombre[j]);
               //permite hacer una copia auxiliar de la cadena nombre[j];
            }
        }
        strcpy(nombre[k],nombre[i]);
        strcpy(nombre[i],aux);
    }

    for(i=0; i<l; i++)
    {
        printf("%s",nombre[i]);
        printf("\n");
    }

  return 0;
}
