#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

string getDataA(string data, int nData);
int getDataN(string data, int nData);
string ordenarLetras(vector <string> letras);
void shell(int vec[], string letras[], int n);
void swapName(string letras[], int i, int k);
int BusquedaBinaria(int vec[], int n, int valor);

int main(int argc, char** argv) 
{
	int key;
	string data[] = {	"F135a69z190L58W", "D3z198p60S200R6", "Q121a80E115r128S", "e120g71h210I89m", "J95a67N212m96q1",
	 					"D112e70U200s67P",	"E35a200C15h90S80", "65D100o16g200f85R", "N95e70B118d149W", "97E32n150L62a78D1"};
	int nData = 10;
	string dAlfa[nData];
	int dNum[nData];

	for(int i = 0; i < nData; i++) dAlfa[i] = getDataA(data[i], nData);
	for(int i = 0; i < nData; i++) dNum[i] = getDataN(data[i], nData);
	shell(dNum,dAlfa,nData);
//	for(int i = 0; i < nData; i++) cout << dAlfa[i] << " " << dNum[i] <<endl;
	
	cout <<endl<< "Clave NUMERICA a Buscar?: ";
	cin >> key;
	int pos = -1;
	pos = BusquedaBinaria(dNum,nData,key);
	if(pos > 0) 
		cout << dAlfa[pos] << "	" << dNum[pos] << endl;
	else
		cout << "Clave no Encontrada" << endl;
	
	
	return 0;
}
int BusquedaBinaria(int vec[], int n, int valor){
	
	int inicio=0,final=n-1,mitad,pos;
	
	while(inicio<=final){
		mitad=(final+inicio)/2;

		if(vec[mitad]==valor){
			pos = mitad;
			return pos;
		}
		if(vec[mitad]>valor) final = mitad-1;
		if(vec[mitad]<valor) inicio = mitad+1;
	}
	return -1;

}
int getDataN(string data, int nData){

	int contador=0;

	for(int j = 0; j < data.size(); j++){
      	string aux = data;
     	if(!isdigit(aux[j])){
			contador+=aux[j];
      	}
    }
	return contador;
}

string getDataA(string data, int nData)
{
	string linea = "";
	string a = data;
	char *split;
	vector <string> letras;

	split = strtok(&a[0], "1234567890");
	while(split!=NULL){
		letras.push_back(string(split));
		split = strtok (NULL, "1234567890");
	}
	linea = ordenarLetras(letras);

	return linea;
}

string ordenarLetras(vector <string> letras){
	
	int n = letras.size();
	char caracteres[n][10];
    char aux[10];
    
    int i,j,k;
    int l=0;

	for(int i =0;i<n;i++)
		strcpy(caracteres[l++],letras[i].c_str());
 
    for(i=0; i<l-1; i++)
    {
        k=i;
        strcpy(aux, caracteres[i]);
        for(j=i+1; j<l; j++)
        {
            if(strcmp(caracteres[j], aux)<0)
            {
                k=j;
                strcpy(aux, caracteres[j]);
            }
        }
        strcpy(caracteres[k],caracteres[i]);
        strcpy(caracteres[i],aux);
    }
    string linea = "";
	for(int i =0;i<n;i++) linea.append(caracteres[i]);
	return linea;
	
}
void shell(int vec[], string letras[], int n){
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
				swapName(letras,i,i+incre);
				band=true;
			}
		}
		if(!band) incre/=2;
	}
}
void swapName(string letras[], int i, int k){
	string aux;	
	aux = letras[i];
	letras[i] = letras[k];
	letras[k] = aux;
}
