#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int hashTruncamiento(int key);
int randomize();

int main(int args, char **argv)
{
	srand(time(NULL));
	int IDs_Size = 1000;
	int IDs[IDs_Size];
	int pos[IDs_Size];
	float colision = 0;
	
	for (int i = 0; i < IDs_Size; i++){
		pos[i] = -1;
		IDs[i] = randomize();
		cout << "[" << IDs[i] << "] " << hashTruncamiento(IDs[i]) << endl;
	} 
	
	for (int i = 0; i < IDs_Size; i++) 
	{
		if(pos[hashTruncamiento(IDs[i])] == -1)
			pos[hashTruncamiento(IDs[i])] = IDs[i];
		else colision++;
	}
		
	cout << endl << "Porcentaje de Colision: " << (colision*100)/IDs_Size << "%" << endl;
	
	return 0;
}

int hashTruncamiento(int key)
{
	int pos = 0;
	int digit;
	int sw = -1;
	int c = 0;
	
	while (key > 0 && c != 3)
	{
		digit = key % 10;
		
		if(sw < 0)
		{
			c++;
			pos = pos * 10 + digit;
		}
				
		key /= 10;
		sw *= -1;	
	}
//	if(/*pos < 100 ||*/ pos > 999) pos = hashFolding(randomize());
	return pos;
}
int randomize()
{
	int number;
	int numberHelper;
		
	number = rand() % 99999+10000;
	number *= 1000;
	numberHelper = rand() % 999+100;
	number += numberHelper;
	
	return number;
}
