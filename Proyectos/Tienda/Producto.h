#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

using namespace std;

class Producto
{
	int Code;
	string Desc;
	int Price;
	
	public:
		Producto(int _Code, string _Desc, int _Price);
		int getCode();
		string getDesc();
		int getPrice();
	
};

#endif
