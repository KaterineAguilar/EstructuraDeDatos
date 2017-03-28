#include <iostream>
#include <vector>
#include <cstdlib>
#include "fstream"

using namespace std;

void show(vector <int> vec);
void Ord(string path, vector<int> &vector);
void separa(vector<int> &vector);
void mezcla(int *p1, int *p2, int *p3, vector<int> &vector);
void insertion_sort(int *vec, int size);

int main(int argc, char** argv) {
	
	string path = "Numeros.txt";
	vector <int> Numeros;
	int size = 0;
	
	Ord(path, Numeros);
	separa(Numeros);
	cout << "Numeros Ordenados.. " << endl;
	show(Numeros);
	
	return 0;
}

void separa(vector<int> &vector)
{
	int n = vector.size()/3;
	int *p1 = new int[n];
	int *p2 = new int[n];
	int *p3 = new int[vector.size()-n*2];
	int cont = 0;
	
	for(int i = 0; i < n; i++){
		p1[i] = vector[cont++];
	}
	insertion_sort(p1,n);
	for(int i = 0; i < n; i++){
		p2[i] = vector[cont++];
	}
	insertion_sort(p2,n);
	for(int i = 0; i < vector.size()-n*2; i++){
		p3[i] = vector[cont++];
	}
	insertion_sort(p3,vector.size()-n*2);
	mezcla(p1, p2, p3, vector);
}

void mezcla(int *p1, int *p2, int *p3, vector<int> &vec)
{
	int n = vec.size()/3;
	int nVector = vec.size();
	
	vector<int> v1;
	vector<int> v2;
	vec.clear();
	
	int cont = 0;
	int i=0, j=0, k;
	
	for(k = 0;(i < n) && (j <= n);k++) {
		if(p1[i] < p2[j]){
			v1.push_back(p1[i]);
			i++;
		}else{
			v1.push_back(p2[j]);
			j++;
		}
	}
	i=j=0;
	for(k = 0;(i < n) && (j <= nVector-n*2);k++) {
		if(v1[i] < p3[j]){
			v2.push_back(v1[i]);
			i++;
		}else{
			v2.push_back(p3[j]);
			j++;
		}
	}
	
	while (i < n*2) {
		v2.push_back(v1[i]);
		i++; k++;
	}
	while (j < nVector-n*2) {
		v2.push_back(p3[j]);
		j++; k++;
	}
	for(int i = 0; i < v2.size(); i++)
		vec.push_back(v2[i]);
}

void insertion_sort(int *vector, int size)
{
	int aux,I,i;
	for(i=1; i<size;i++){
		I=i;
		aux=vector[i];
		while(I>0&&aux<vector[I-1]){
			vector[I]=vector[I-1];
			I--;
		}
		vector[I]=aux;
	}
}

void Ord(string path, vector<int> &vector)
{
	
	ifstream file(path.c_str());
	string line;
	char *split;
	int cont = 0;
	
	while(getline(file,line)){
		vector.push_back(atoi(&line[0]));
	}
}

void show(vector <int> vec)
{

	for ( int i = 0 ; i < vec.size(); i++) cout << "[" << i+1 << "]" <<  vec[i] << endl;
}
