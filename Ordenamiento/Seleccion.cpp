#include <iostream>

using namespace std;

void selection_sort(int vector[],int size);
void seleccion_mejorada(int vec[],int n);

int main (int argc, char** argv)
{
	int v[15] = {15,12,36,48,52,21,1,5,4,3,12,7,9,2,8};
	selection_sort(v,15);
	for (int i = 0; i < 15; i++) cout << v[i] << " ";
	return 0;
}

void selection_sort(int vector[],int size)
{
	int a,b,heavy,position=0,flag=0;
	size--;
	for(b=size; b>=0; b--) {
		heavy=vector[0];
		position=0;
		for(a=0; a<=b; a++) {
			if(vector[a]>heavy) {
				heavy=vector[a];
				position=a;
			}
		}
		int aux=vector[b];
		vector[b]=vector[position];
		vector[position]=aux;
	}
}

