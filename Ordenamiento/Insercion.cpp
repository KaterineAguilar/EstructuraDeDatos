#include <iostream>

using namespace std;

void insertion_sort(int vector[],int size);

int main (int argc, char** argv)
{
	int v[24] = {15,2,3,6,1,9,4,5,6,15,25,48,51,32,5,98,62,152,2,3,0,-1,88,15};
	insertion_sort(v,24);
	for (int i = 0; i <24; i++) cout << v[i] << " ";
	return 0;

}
void insertion_sort(int vector[],int size)
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
