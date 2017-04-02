#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H
#include <iostream>

using namespace std;

template <class T>
class ColaCircular
{
	T *v;
	int BEG, END, SIZE;
	public:
		ColaCircular(int size);
		int Add(T &element);
		int Delete(T &element);
		void Print();
};

template <class T>
ColaCircular<T>::ColaCircular(int size)
{
	SIZE = size;
	BEG = END = -1; // COLA VACIA
	v = new T[SIZE];
	if(!v) std::cout << "Not Enough Memory" << std::endl;		
	
}

template <class T>
int ColaCircular<T>::Add(T &element)
{
	int vEnd = ((END + 1) % SIZE);
	
	if (vEnd == BEG) 
		return -1;
		
	if (BEG == -1)
		BEG = 0;
	
	v[vEnd] = element;
	END = vEnd;
	return END;
}

template <class T>
int ColaCircular<T>::Delete(T &element)
{
	int aux;
	if (BEG == -1 && END == -1) 
		return -1;
		
	element = v[BEG];
	aux = BEG;
	if (BEG == END)
		BEG = END = -1;
	else 
		BEG = (BEG + 1) % SIZE;
	return aux;
}

template <class T>
void ColaCircular<T>::Print()
{
//	int i = BEG;
//	if(!(BEG == END)){
//		do{
//			cout << v[i++] << endl;
//			if(i == SIZE && BEG > END) i = 0;
//		}while (i != END+1);
//		cout << endl;
//	}
	for(int i = BEG; i < END; i++){
		cout << v[i] << endl;
	}
}
#endif
