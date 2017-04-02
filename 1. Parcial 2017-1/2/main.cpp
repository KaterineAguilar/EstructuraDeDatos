#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <math.h>

using namespace std;

void inf(string path, vector<int> &vector);
void show(int data[], int size);
bool rColsion(int data[], int num, int &ite);
int hashPlegamiento(int num);
inline int to_inverse(int x);

int main(int argc, char** argv) {
	
	vector<int> Numeros;
	string path = "Numeros.txt";
	int data[100];
	int tamData = 100;
	int colision = 0;
	int prueba = 15456;
	inf(path, Numeros);
	
	for(int i = 0; i < tamData; i++)
		data[i] = -1;
	
	for(int i = 0; i < Numeros.size(); i++) {
		int pos = hashPlegamiento(Numeros[i]);
		if(data[pos] == -1) 
			data[pos] = Numeros[i];
		else {
			colision++;
		}
	}
	show(data,100);
	
	cout << "colision " << (colision*100)/Numeros.size() << "%" << endl << endl;
	
	colision = 0;
	int ite = 0;
	for(int i = 0; i< tamData; i++) {
		int pos = hashPlegamiento(Numeros[i]);
		if(!data[pos] == -1){
			while(!rColsion(data, Numeros[i], ite)){
				rColsion(data, Numeros[i], ite);
			}
			colision++;
		}
			
	}
	show(data,100);
	cout << "Colisiones resueltas.." << endl;
	cout << "colision " << (colision*100)/Numeros.size() << "%" << endl << endl;
	
	
	cout << "Buscar clave: ";
	int clave;
	cin >> clave;
	int pos = hashPlegamiento(clave);
	if (data[pos] == clave) cout << "Valor encontrado en: " << hashPlegamiento(clave) << endl;
	else cout << " no encontrado";
//	show(data,100);
	return 0;
}

bool rColsion(int data[], int num, int &ite)
{
	ite++;
	int pos = hashPlegamiento(num);
	int valor = 0;
	
	pos += pow(ite,2);
	if (pos > 99) 
		pos -= 100;
	
	if (ite > 99) 
		ite = 1;

	if(data[pos] == -1) {
		data[pos] = num;
		
		return true;
	}
	cout << " asd"<< data[pos] << " " << ite; 
	return false;
}

int hashPlegamiento(int num)
{
	num = to_inverse(num);
	int valor=0;
	while(num){
		valor+=num%10;
		num/=10;
	}
	return valor;
}
void inf(string path, vector<int> &vector)
{
	ifstream file(path.c_str());
	string line;
	char *split;
	int cont = 0;
	
	while(getline(file,line)){
		vector.push_back(atoi(&line[0]));
	}
}
inline int to_inverse(int x)
{
	string l;
	while(x) {
		l.push_back(x%10 + '0');
		x/=10;
	}
//	reverse(l.begin(), l.end());
	return atoi(&l[0]);
}

void show(int data[], int size)
{

	for ( int i = 0 ; i < size; i++)
		if(data[i]!=-1)
			cout << "[" << i+1 << "]" <<  data[i] << " ";
		else
			cout << " ";
	cout << endl << endl;
}
