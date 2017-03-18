#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int hashRaiz(int number);
long long CreditCards();
int calcNum(long long number);
inline string to_string(int x);

void buscar(long long TDC, long long BankCards[][100], int nFil[], int it, int max);

int main(int argc, char** argv)
{

	srand(time(NULL));
	fstream claves;
	string linea;
	claves.open("claves.txt", ios::in);

	long long data[100]; //data generada del archivo
	long long BankCards[100][100]; // lugar a guardar despues de usar hashraiz
	int nFil[100]; // cantidad de numeros almacenados en cada fila de la matriz
	int colision = 0;
	int n = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			BankCards[i][j] = -1;
	}

	for (int i = 0; i < 100; i++) 
		nFil[i] = 0;

	if (claves.fail()) {
		cout << "error al abrir el archivo";
	} else {
		while (getline(claves, linea)) {
			data[n++] = atoll(&linea[0]);
		}
	}

	claves.close();
	int max = n/10; //Num de Iteraciones resultante de la cant de datos dividido entre 10
	//---------LLENO Y RESUELVO COLISION----------
	for (int i = 0; i < n; i++) {
		int pos = hashRaiz(calcNum(data[i]));
		if (BankCards[nFil[pos]][pos] == -1)
			BankCards[nFil[pos]][pos] = data[i];
		else {
			nFil[pos]++;
			BankCards[nFil[pos]][pos] = data[i];
			colision++;
		}
	}
	
	cout << "Colisiones anteriores: " << (colision * 100)/n << "%" << endl;
	cout << "Colisiones resueltas por el metodo de Arreglos anidados" << endl << endl;
	
	//BUSCANDO NUMERO reinicializo el vector auxiliar nFil = 0 
	for (int i = 0; i < 100; i++) 
		nFil[i] = 0;
	long long TDC;
	cout << "Numero de Tarjeta de Credito a buscar: ";
	cin >> TDC;
	buscar(TDC, BankCards, nFil, 0, max);
	

	

//	for (int i = 0; i < 3; i++) {								//IMPRIMIR DATOS GUARDADOS CON HASH
//		for (int j = 0; j < 100; j++)
//			if(BankCards[i][j] == -1 )
//				cout << " ";
//			else
//				cout << "[" << j << "] " << BankCards[i][j] << " ";
//		cout << endl << endl << endl;
//	}
	return 0;
}
void buscar(long long TDC, long long BankCards[][100], int nFil[], int it, int max)
{
	int pos = hashRaiz(calcNum(TDC));
	
	if (BankCards[nFil[pos]][pos] == TDC)
		cout << endl << "Tarjeta encontrada en posicion: " << "[" << nFil[pos] << "]" << "[" << pos << "]" << endl;
	else {
		nFil[pos]++;
		it++;
		if(it != max)
			buscar(TDC, BankCards, nFil, it, max);
		else
			cout << endl << "Numero no encontrado.. ";
	}
}

int hashRaiz(int number)
{
	double result;
	string ret;
	result = sqrt(number);
	result *= 100;

	ret += to_string((int)result%10);
	result/=10;
	ret += to_string((int)result%10);
	reverse(ret.begin(),ret.end());

	return atoi(&ret[0]);
}

int calcNum(long long number)
{

	int storage[16];
	int aux = 0;

	for (int i = 15; i >= 0; i--) {
		storage[i] = number % 10;
		number /= 10;
	}
	int cont = 0;
	int pos = 15;

	for (int i = 0; i < 6; i ++) {
		for (int j = 0; j < storage[cont]; j++ )
			pos--;
		cont++;
		aux += storage[pos];
		aux *= 10;
		pos = 15;
	}
	aux /= 10;


	return aux;
}

long long CreditCards()
{
	int Num[4];

	string linea;

	for(int i = 0; i < 4; i++) {
		Num[i] = rand() % 9999 + 1000;
		while(Num[i]<1000 || Num[i]>9999) Num[i] = rand() % 9999 + 1000;
		linea += to_string(Num[i]);
	}

	return atoll(&linea[0]);
}

inline string to_string(int x)
{
	string l;
	while(x) {
		l.push_back(x%10 + '0');
		x/=10;
	}
	reverse(l.begin(),l.end());
	return l;
}
